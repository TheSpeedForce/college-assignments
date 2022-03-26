// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
:size_(0),
 data_(0)
{}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:size_(stack.size_)
{
    data_ = stack.data_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    data_.resize(size_+1);
    data_.set(size_, element);
    size_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if (size_ > 0)
    {
        // COMMENT There is no need to create a new array just to pop
        // an element from the stack.

        // RESPONSE to Dr. Hill's comment:
        // Resized the original array and changed elements instead of creating new array.

        size_ = size_-1;
        data_.resize(size_);    
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
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // COMMENT Always check for self-assignment first before continuing.

    // RESPONSE to Dr. Hill's comment:
    // Added self comparison check

    // COMMENT It would be easier if you just use the assignment operator
    // on the array to copy things from rhs.

    // RESPONSE to Dr. Hill's comment:
    // Set data_ variable to rhs data_ for easier copy.

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
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.

    // RESPONSE to Dr. Hill's comment:
    // Reset data varaibles without dequeing.
    size_ = 0;
    Array<T> new_data_;
    data_ = new_data_;
}

template <typename T>
void Stack <T>::print(void){
    data_.print();
}
