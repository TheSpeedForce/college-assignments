// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>
#include <iostream>

#include "Array.h"

#define MAX 30

Array::Array (void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE to Dr. Hill's comment: Separated initialization of members to different line.

    :data_(new char[MAX]), 
    cur_size_(0), 
    max_size_(MAX)
    {}

Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE to Dr. Hill's comment: Separated initialization of members to different line.

    :data_(new char[length]),
    cur_size_(length),
    max_size_(MAX)
    {}

Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE to Dr. Hill's comment: Separated initialization of members to different line.

    :data_(new char[length]),
    cur_size_(length),
    max_size_(MAX)
    {
    for(int i = 0; i < length; i++){
        data_[i] = fill;
    };
    }

Array::Array (const Array & array)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE to Dr. Hill's comment: Separated initialization of members to different line.

    :data_(new char[MAX]),
    cur_size_(array.cur_size_),
    max_size_(array.max_size_)     
    {
    for (int i = 0; i < cur_size_; i++){
        data_[i] = array.get(i);
    }
}

Array::~Array (void)
{
    delete [] data_;
    
    // COMMENT There is no need to reset the data_ variable since this object is no
    // longer useable after the desturctor returns.

    // RESPONSE to Dr. Hill's comment: commented out the following command
    // data_ = nullptr;
    
    // COMMENT This line should cause a runtime failure since the object is already
    // being deleted at this point.

    // RESPONSE to Dr. Hill's comment: commented out the following command
    // delete this;
}

const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Implement this method.

    // RESPONSE to Dr. Hill's Comment: Completed the implementation
    // I initially assumed we were just supposed to return the Array itself

    cur_size_ = rhs.cur_size_;
    max_size_ = rhs.max_size_;
    for(int i; i < cur_size_; i++){
        data_[i] = rhs.get(i);
    }
    return *this;
}


char & Array::operator [] (size_t index)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // RESPONSE to Dr. Hill's comment: Implemented exception handling to catch 
    // out of range exception.

    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

const char & Array::operator [] (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // RESPONSE to Dr. Hill's comment: Implemented exception handling to catch 
    // out of range exception.

    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

char Array::get (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // RESPONSE to Dr. Hill's comment: Implemented exception handling to catch 
    // out of range exception.

    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

void Array::set (size_t index, char value)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // RESPONSE to Dr. Hill's comment: Implemented exception handling to catch 
    // out of range exception.

    if (index < cur_size_){
        data_[index] = value;
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

void Array::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    
    // RESPONSE to Dr. Hill's comment: Added check to see if new_size is greater than max_size_.
    
    if (new_size > max_size_){
        cur_size_ = max_size_;
        char *new_data_ = new char[cur_size_];
        for (int i = 0; i < cur_size_; i++){
            new_data_[i] = data_[i];
        }
        delete [] data_;
        data_ = new_data_;
        max_size_ = new_size;
    }
    else {
        cur_size_ = new_size;
    }
}

int Array::find (char ch) const
{
    for (int i = 0; i < cur_size_; i++){
        if (data_[i] == ch){
            return i;
        }
        else{return -1;}
    }
}

int Array::find (char ch, size_t start) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.

    // RESPONSE to Dr. Hill's comment: Implemented exception handling to catch 
    // out of range exception.

    if (start < cur_size_){
        for (int i = start; i < cur_size_; i++){
            if (data_[i] == ch){
                return i;
            }
            else{ return -1;}
        }
    }
    else {
        throw std::out_of_range("Error: Given start index out of range");
    }
}

bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.

    // RESPONSE to Dr. Hill's comment: added the check to see if rhs is the Array itself 
   
    bool check = true;

    if (rhs == *this){
        return check;
    }

    else if (cur_size_ == rhs.cur_size_){
        for (int i = 0; i < cur_size_; i++){
            if (data_[i] != rhs.get(i)){
                check = false;
            } 
        }
    }
    else {check = false;}
    return check;
}

bool Array::operator != (const Array & rhs) const
{
    // COMMENT You can define operator != in terms of operator ==.

    // RESPONSE to Dr. Hill's comment: Will be using the NOT of the 
    // value returned by operator == .

    if (*this == rhs){
        return false;
    }
    else {
        return true;
    }
}

void Array::fill (char ch)
{
    for (int i = 0; i < cur_size_; i++){
        data_[i] = ch;
    }
}

void Array::shrink (void)
{
    // COMMENT Do not use the resize() method to shrink the array. This is
    // because resize() should only change the array size when cur_size_
    // is greater the max_size_. Otherwise, you are defeating the purpose
    // of the memory allocation optimizations.

    // RESPONSE to Dr. Hill's comment: Implemented the method differently
    // without using resize(). Just need to change max_size_.
    
    max_size_ = cur_size_;
}

void Array::reverse (void)
{
  int mid;
  mid = (cur_size_/2 + cur_size_%2);
  for (int i = 0; i < mid; i++){
      char temp = data_[cur_size_-i-1];
      data_[cur_size_-i-1] = data_[i];
      data_[i] = temp;

  }
}

Array Array::slice (size_t begin) const
{
  int slice_size = cur_size_ - begin;  
  Array sliced_string(slice_size);
  for (int i = 0; i < slice_size; i++){
      sliced_string.data_[i] = data_[begin + i]; 
  }
  return sliced_string;
}

Array Array::slice (size_t begin, size_t end) const
{
  int slice_size = end - begin;  
  Array sliced_string(slice_size);
  for (int i = 0; i < slice_size; i++){
      sliced_string.data_[i] = data_[begin + i]; 
  }
  return sliced_string;
}


void Array::printArray() const {
    for (int i=0; i<cur_size_; i++) {
        std::cout << data_[i];
    }
    std::cout << std::endl;
}

