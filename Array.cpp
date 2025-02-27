#include "Array.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

// default constructor for class Array (default size 10)
template<typename T>
Array<T>::Array(int arraySize)
    : size{ (arraySize > 0 ? static_cast <size_t>(arraySize) : throw std::invalid_argument{"Array size must be greater than 0"}) }
    , ptr{ new T[size] {} }
{ /* empty body */}

// copy constructor for class Array;
// must receive a reference to an Array
template<typename T>
Array<T>::Array(const Array& arrayToCopy) : size{ arrayToCopy.size }, ptr{ new T[size] } 
{
    for (size_t i{ 0 }; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
}

// destructor for class Array
template<typename T>
Array<T>::~Array()
{
    delete[] ptr; // release pointer-based array space
}

// return number of elements of Array
template<typename T>
size_t Array<T>::getSize() const 
{
    return size; // number of elements in Array
}

// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
template <class T>
const Array<T>& Array<T>:: operator=(const Array<T>& right)
{
    if (&right != this) {// avoid self-assignment
    // for Arrays of different sizes, deallocate original
    // left-side Array, then allocate new left-side Array
        if (size != right.size) {
            delete[] ptr; // release space
            size = right.size; // resize this object
            ptr = new T[size]; // create space for Array copy
        }

        for (size_t i{ 0 }; i < size; ++i) {
            ptr[i] = right.ptr[i]; // copy array into object
        }
    }
    return *this; // enables x = y = z, for example
}

// determine if two Arrays are equal and
// return true, otherwise return false
template<typename T>
bool Array<T>::operator==(const Array<T>& right) const
{
    if (size != right.size) {
        return false; // arrays of different number of elements
    }

    for (size_t i{ 0 }; i < size; ++i) {
        if (ptr[i] != right.ptr[i]) {
            return false; // Array contents are not equal
        }
    }
    return true; // Arrays are equal
}

// inequality operator; returns opposite of == operator
template<typename T>
bool Array<T>::operator!=(const Array& right) const
{
    return !(*this == right); // invokes Array::operator==
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue

template<typename T>
T& Array<T>::operator[](int subscript)
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
        throw std::out_of_range{ "Subscript out of range" };
    return ptr[subscript]; // reference return
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template<typename T>
T Array<T>::operator[](int subscript) const 
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size) {
        throw std::out_of_range{ "Subscript out of range" };
    }
    return ptr[subscript]; // returns copy of this element
}

// overloaded input operator for class Array;
// inputs values for entire Array
template<typename T>
std::istream& operator>>(std::istream& input, Array<T>& a)
{
    for (size_t i{ 0 }; i < a.size(); ++i)
        input >> a.ptr[i];

    return input; // enables cin >> x >> y;
}

// overloaded output operator for class Array
template<typename T>
std::ostream& operator<<(std::ostream& output, const Array<T>& a)
{   // output private ptr-based array
    for (size_t i{ 0 }; i < a.size; ++i)
        output << a.ptr[i] << " ";

    return output; // enables cout << x << y;
}
