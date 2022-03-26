/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Adds a new \a element to the Queue. The element is added
   * at the end of the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the front-most element from the Queue.
   *
   * @return         Element at the front of the queue
   * @exception      empty_exception    The Queue is empty.
   */
  T dequeue (void);

  /**
   * Test if the Queue is empty
   *
   * @retval         true          The Queue is empty
   * @retval         false         The Queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Queue.
   *
   * @return         Size of the Queue.
   */
  size_t size (void) const;

  /// Remove all elements from the Queue.
  void clear (void);

  /// Print the Queue.
  void print(void);

private:
  // add member variable here
    
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.

    // RESPONSE to Dr. Hill's comment:
    // Allocated the variable to stack memory.
  Array<T> data_;
  size_t size_;
  int front_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _QUEUE_H_
