#ifndef ASSIGNMENT2_COLTYPE_HPP
#define ASSIGNMENT2_COLTYPE_HPP
#include <memory>
#include <iostream>

using namespace std;
class GenericDataType {
public:
    virtual ~GenericDataType() = default;
    virtual std::unique_ptr<GenericDataType> clone() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const GenericDataType& v);
    virtual bool operator==(const GenericDataType& other) const = 0;
    virtual bool operator<(const GenericDataType& other) const = 0;
protected:
    virtual void print(std::ostream& os) const = 0;
};

inline std::ostream& operator<< (std::ostream& os, const GenericDataType& v) {
    v.print(os);
    return os;
}

template <typename T>
class DataType : public GenericDataType {
    T value;

public:
    explicit DataType(T const & val) : value(val) {}
    unique_ptr<GenericDataType> clone() const override; // TO IMPLEMENT

    const T& get_value() const { return value; }
    T& get_value() { return value; }
    explicit operator T() const { return value; }
    bool operator==(const GenericDataType& other) const override {
        const auto* dt = dynamic_cast<const DataType<typename std::remove_reference_t<T>>*>(&other);
        if(dt == nullptr) {
            return false;
        }
        return this->get_value() == dt->get_value();
    }
    bool operator<(const GenericDataType& other) const override {
        const auto* dt = dynamic_cast<const DataType<typename std::remove_reference_t<T>>*>(&other);
        if(dt == nullptr) {
            return false;
        }
        return this->get_value() < dt->get_value();
    }
protected:
    void print(std::ostream& os) const override {
        os << this->get_value();
    }
};

template<typename T>
std::unique_ptr<GenericDataType> DataType<T>::clone() const {
    return std::unique_ptr<GenericDataType>();
}


class ColType {
    std::unique_ptr<GenericDataType> container;

public:
    template <typename ValueType>
    explicit ColType(const ValueType& value); // TO IMPLEMENT
    ColType(const ColType& other); // TO IMPLEMENT
    ColType& operator=(const ColType& other); // TO IMPLEMENT
    GenericDataType& get() {
        return *container;
    }
    const GenericDataType& get() const {
        return *container;
    }
    bool operator==(const ColType& other) const; // TO IMPLEMENT
    bool operator<(const ColType& other) const; // TO IMPLEMENT
};
//we create a deep copy of the data using clone function
ColType::ColType(const ColType &other) {
    if (other.container) {
        container = other.container->clone();
    }

}
//Implementation of the copy assignment operator
ColType& ColType::operator=(const ColType &other) {
    if (this != &other) {  // Checking for self-assignment
        if (other.container) {
            container = other.container->clone();
        } else {
            container.reset();  // If 'other' is empty, reset container
        }
    }
    return *this;
}

bool ColType::operator==(const ColType &other) const {
        if (!container && !other.container) {
            return true;  // To check if both the current object and the one being compared are null. Returns true if that is the case
        } else if (container && other.container) {  //To check if both the current object and the object being compared are not null
            return *container == *other.container;
        }
        return false;  // When one object is empty and the other is not, return false
    }

bool ColType::operator<(const ColType &other) const {
    if (!container && !other.container) {
        return false;  // When current object is equal to the object being compared, they are actually equal and not less than
    } else if (container && other.container) {
        return *container < *other.container;  // Delegate to the GenericDataType's operator<
    }
    return container == nullptr;  // If one is empty, it's less than the non-empty one
}


template<typename ValueType>
ColType::ColType(const ValueType &value) {
    // The value passed should be wrapped in a datatype
    container = std::make_unique<DataType<ValueType>>(value);

}




#endif //ASSIGNMENT2_COLTYPE_HPP
