#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <iostream>
#include <cstdint>
#include <bitset>
#include <math.h>
#include "murmurhash.hpp"

template <typename Key>
struct BloomHash {
    std::size_t operator()(Key key, unsigned int seed) const {
        std::size_t val;
        const uint8_t* key1 = (const uint8_t*)(key);
        val = murmur3_32(key1, sizeof(key), seed);
        return val;
    }
};

template <typename Key, unsigned int m, typename Hash = BloomHash<Key>>
class BloomFilter {
public:
    explicit BloomFilter(unsigned int hash_num) : k_(hash_num) {}

    BloomFilter(std::initializer_list<Key> key_ini, unsigned int hash_num) : k_(hash_num) {
        for (const auto& key : key_ini) {
            insert(key);
        }
    }

    template <typename It>
    BloomFilter(It first, It last, unsigned int hash_num) : k_(hash_num) {
        for (It element = first; element != last; ++element) {
            insert(*element);
        }
    }

    bool insert(const Key& key) {
        bool isNew = false;
        for (unsigned int i = 0; i < k_; ++i) {
            Hash b_hash;
            size_t hash_value = b_hash(key, i) % m;
            if (!data_.test(hash_value)) {
                isNew = true;
                data_.set(hash_value);
            }
        }
        return isNew;
    }

    bool contains(const Key& key) const {
        for (unsigned int i = 0; i < k_; ++i) {
            Hash b_hash;
            size_t hash_value = b_hash(key, i) % m;
            if (!data_.test(hash_value)) {
                return false;
            }
        }
        return true;
    }

    uint64_t approx_size() const{
        std::size_t X = 0;
        uint64_t nstar;
        for (int i = 0; i < m; i++)
        {
            if(data_.test())
                X += 1;
        }
        nstar = uint64_t(- (m/k_) * log(1 - (X/m)));
        return nstar;
    }

    // Implement the false_positive_rate method
    template<typename It>
    double false_positive_rate(It positive_begin, It positive_end, It negative_begin, It negative_end) const {
        std::size_t positive_count = std::distance(positive_begin, positive_end);
        std::size_t negative_count = std::distance(negative_begin, negative_end);

        std::size_t false_positives = 0;
        for (It it = negative_begin; it != negative_end; ++it) {
            if (contains(*it)) {
                false_positives++;
            }
        }

        return static_cast<double>(false_positives) / negative_count;
    }

    double space_ratio(uint64_t num_elements) const {
        return double(m) / (sizeof(Key) * num_elements * 8);
    }

    void set_k_(unsigned int hash_num) {
        k_ = hash_num;
    }

private:
    std::bitset<m> data_;
    unsigned int k_;
};

#endif  // BLOOM_FILTER_HPP