// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
:Array_Base<T>(N),
 size_(N)
{}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
:Array_Base<T>(arr),
 size_(N)
{}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
:Array_Base<T>(N, fill),
 size_(N)
{}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    if (this != &rhs){
        for(int i = 0; i < size_; i++)
        {
            this->set(i, rhs.get(i));
        }
    }
    return *this;
}

