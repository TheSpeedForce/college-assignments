// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
:size_(0),
 front_(0),
 data_(0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
:size_(queue.size()),
 front_(0)
{
    data_ = queue.data_;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    data_.resize(size_+1);
    data_.set(size_, element); 
    size_++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    if (size_ > 0)
    {
        // COMMENT This design is OK, but it is not the best design. This will be
        // a very expensive array to use if you are dequeing a lot of elements. This
        // is because you are copying N elements each time you dequeue 1 element.
        // Instead, you only want to copy element when necessary. Come up with a better
        // design that is not as expensive for the client to use.
        
        // RESPONSE to Dr. Hill's comment:
        // Added variable front that returns the front element.
        T value = data_.get(front_);
        size_--;
        front_++;
        return value;
    }
    else
    {   
        throw empty_exception();
    }
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    // COMMENT Always check for self-assignment first.

    // RESPONSE to Dr. Hill's comment:
    // Added self comparison
    
    if (this != &rhs){
        size_ = rhs.size_;
        data_ = rhs.data_;
    }
    return * this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    // COMMENT This works, but is a very expensive operation. You should find a
    // way to just reset the state without having to dequeue every element.

    // RESPONSE to Dr. Hill's comment:
    // Reset data varaibles without dequeing.
    size_ = 0; 
    front_ = 0;
    Array<T> new_data_(0);
    data_ = new_data_;
  

}

template <typename T>
void Queue <T>::print(void)
{
    data_.print();
}
