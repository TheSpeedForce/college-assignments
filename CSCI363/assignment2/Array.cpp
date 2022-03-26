// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

#include <iostream>

#define MAX 30               // for max size

//
// Array
//
template <typename T>
Array <T>::Array (void)
:Array_Base<T>(),
 cur_size_(0),
 max_size_(30)
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:Array_Base<T>(length),
 cur_size_(length),
 max_size_(MAX)
{}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:Array_Base<T>(length, fill),
 cur_size_(length),
 max_size_(MAX)
{}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:Array_Base<T>(array),
 cur_size_(array.cur_size_),
 max_size_(array.max_size_)
{}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (this != &rhs){
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        delete [] this->data_;
        T * new_data_ = new T[max_size_];
        for(int i = 0; i < cur_size_; i++)
        {
            new_data_[i] = rhs.data_[i];
        }
        this->data_ = new_data_;
    }
    return * this;
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{  
    std::cout << cur_size_ << std::endl;
    if (index < max_size_){
        return this->data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range for get");
    }
}


//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
    if (index < max_size_){
        this->data_[index] = value;
    }
    else {
        throw std::out_of_range("Error: Given index out of range for set");
    };
}


//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size > max_size_){
        cur_size_ = max_size_;
        T * new_data_ = new T[cur_size_];
        for (int i = 0; i < cur_size_; i++){
            new_data_[i] = this->data_[i];
        }
        delete [] this->data_;
        this->data_ = new_data_;
        max_size_ = new_size;
    }
    cur_size_ = new_size;
}

template <typename T>
void Array <T>::shrink(void)
{ 
    if (max_size_ > cur_size_){
        T * new_data_ = new T[cur_size_];
        for (int i = 0; i < cur_size_; i++){
            new_data_[i] = this->data_[i];
        }
        delete [] this->data_;
        this->data_ = new_data_;
        max_size_ = cur_size_;
    }
}

template <typename T>
void Array <T>::print(){
    std::cout << std::endl << "Current size:" << cur_size_ << std::endl;
    std::cout << "[";
    for (int i=0; i < cur_size_; i++){
        std::cout << this->data_[i] << " ";
    }
    std::cout << "]" << std::endl;
}
