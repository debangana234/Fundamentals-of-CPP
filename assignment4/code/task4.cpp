#include "bloom_filter.hpp"

#include "murmurhash.hpp"

int main(int argc, const char* argv[]) {
  // you might test your bloom filter here
    unsigned int noHashes = 2;
    const unsigned int m = 32;
    BloomFilter<int, m, std::size_t> bfilter = BloomFilter<int, m, std::size_t> (noHashes);
  return 0;
}
