//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

/**
 * @class Array_Iterator
 *
 * Array Iterator class to create an iterator object using Array class.
 */
template <typename T>
class Array_Iterator
{
public:

  // Default constructor
  Array_Iterator (Array <T> & a);
  
  // Deconstructor
  ~Array_Iterator (void);

  // Function to check if end is reached
  bool is_done (void);

  // Function to advance to next element
  void advance (void);

  // Function to return element at provided index
  T & operator * (void);

  // Function to return reference to element at the provided index
  T * operator -> (void);


private:
  
  /// Array for iteration
  Array<T> & a_;

  /// Current size of the array.
  size_t curr_;

};

// include the source file since template class
#include "Array_Iterator.cpp"

#endif // !defined _ARRAY_ITERATOR_H_
