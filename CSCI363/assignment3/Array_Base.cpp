// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>         // for std::out_of_bounds exception

#include <iostream>          // for cout

#define MAX 30               // for max size

//
//Array_Base
//
template <typename T>
Array_Base<T>::Array_Base(void)
:cur_size_(0),
 max_size_(MAX),
 data_(new T[MAX])
{}

//
//Array_Base (size_t)
//
template <typename T>
Array_Base<T>::Array_Base(size_t length)
:cur_size_(length), 
 max_size_(MAX),
 data_(new T[length])
{}

//
// Array_Base (size_t, T)
//
template <typename T>
Array_Base<T>::Array_Base(size_t length, T fill)
:cur_size_(length), 
 max_size_(MAX),
 data_(new T[length])
{
    for(int i = 0; i < length; i++) 
    {   
        data_[i] = fill;
    }
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base<T>::Array_Base(const Array_Base & arr)
:cur_size_(arr.cur_size_), 
 max_size_(arr.max_size_),
 data_(new T[arr.cur_size_])
{
    for(int i = 0; i < cur_size_; i++)
    {
      data_[i] = arr[i];
    }
}

// ~Array_Base
template <typename T>
Array_Base<T>::~Array_Base(void)
{
    delete [] data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
    if (this != &rhs){
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        delete [] data_;
        T * new_data_ = new T[max_size_];
        for(int i = 0; i < cur_size_; i++)
        {
            new_data_[i] = rhs.data_[i];
        }
        data_ = new_data_;
    }
    return * this;
}
//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range");
    }
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{  
    if (index < cur_size_){
        return data_[index];
    }
    else {
        throw std::out_of_range("Error: Given index out of range for get");
    }
}


//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index < max_size_){
        data_[index] = value;
    }
    else {
        throw std::out_of_range("Error: Given index out of range for set");
    };
}

//
// find (T)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{   
    for (int i = 0; i < cur_size_; i++){
        if (data_[i] == value){
             return i;
        }
    }
    return -1;
}

//
// find (T, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    for (int i = 0; i < cur_size_; i++){
        if (data_[start+i] == val){
             return (start+i);
        }
    }
    return -1;
}


//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    bool check = true;
    if (this != &rhs){
        if (cur_size_ != rhs.cur_size_)
        {
            check = false;
        }
        else{
            for (int i = 0; i < cur_size_; i++){
                if (data_[i] != rhs.get(i)){
                    check = false;
                } 
            }
        }
    }
    return check;

}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    bool check = true;
    if (*this == rhs){
        check = false;
    }
    return check;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (int i = 0; i < cur_size_; i++){
        data_[i] = value;
    }
}


template <typename T>
void Array_Base <T>::reverse (void)
{
  int mid;
  mid = (cur_size_/2 + cur_size_%2);
  for (int i = 0; i < mid; i++){
      T temp = data_[cur_size_-i-1];
      data_[cur_size_-i-1] = data_[i];
      data_[i] = temp;

  }
}
template <typename T>
Array_Base<T> Array_Base <T>::slice (size_t begin) const
{
  size_t slice_size = cur_size_ - begin;  
  Array_Base <T> sliced_string(slice_size);
  for (int i = 0; i < slice_size; i++){
      sliced_string.data_[i] = data_[begin + i]; 
  }
  return sliced_string;
}

template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const
{
  size_t slice_size = end - begin;  
  Array_Base <T> sliced_string(slice_size);
  for (int i = 0; i < slice_size; i++){
      sliced_string.data_[i] = data_[begin + i]; 
  }
  return sliced_string;
}



template <typename T>
void Array_Base <T>::print(){
    std::cout << std::endl << "Current size:" << cur_size_ << std::endl;
    std::cout << "[";
    for (int i=0; i < cur_size_; i++){
        std::cout << data_[i] << " ";
    }
    std::cout << "]" << std::endl;
}
