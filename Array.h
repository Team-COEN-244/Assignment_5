// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<typename T>
class Array {

    friend std::ostream& operator<< (std::ostream&, const Array&);
    friend std::istream& operator>> (std::istream&, Array&);

private:

    size_t size; // pointer-based array size
    int* ptr;

public:
    explicit Array(int = 10); // default constructor
    Array(const Array&); // copy constructor
    ~Array(); // destructor
    size_t getSize() const; // return size

    const Array& operator=(const Array&); // assignment operator
    bool operator==(const Array&) const; // equality operator
    bool operator!=(const Array& right) const; // inequality operator; returns opposite of == operator
    int& operator[](int); // subscript operator for non-const objects returns modifiable lvalue
    int operator[](int) const; // subscript operator for const objects returns rvalue
};

#endif
