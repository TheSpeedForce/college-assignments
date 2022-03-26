// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.



//
// Array Iterator
//
template <typename T>
Array_Iterator<T>::Array_Iterator(Array <T> & a)
: a_ (a),
  curr_ (0)
{}


//
// is_done
//
template <typename T>
bool Array_Iterator<T>::is_done(void)
{
    return this->curr_ >= this->a_.size();
}

//
// advance
//
template <typename T>
void Array_Iterator<T>::advance(void)
{
    ++ this->curr_;
}

//
// operator *
//
template <typename T>
T & Array_Iterator<T>::operator * (void)
{
    T temp = this->a_.get(this->curr_);
    T& elem = temp;
    return elem;
}

//
// operator ->
//
template <typename T>
T * Array_Iterator<T>::operator -> (void)
{
    return &this->a_.get(this->curr_);
}


//
// ~Array Iterator
//
template <typename T>
Array_Iterator<T>::~Array_Iterator(void)
{}

