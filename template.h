 //! Typedefs for the application 
/*!
 * @author diehlpk
 * @date 2012
 */

#ifndef TEMPLATE
#define TEMPLATE

#include <cstdlib>
#include <cassert>

//! Template for a basic array data type.
/*!
 * \param T The datatype or class of the elemtens in the array.
 * \param size The size of the array.
 */
template < class T, size_t size > class Array
{
private:

  //! The elements of the array.
  T coord[size];
public:
  //! Constructor.
  Array (void)
  {

    for (size_t d = 0; d < size; ++d)
      coord[d] = 0;
  }
  //! Destructor.
  ~Array (void)
  {
  }

  //! Operator returns the element with the index index.
  /*!
   * \param index The index of the element.
   */
  T & operator[](size_t index)
  {
    assert (size > index);
    return coord[index];
  }

  //! Operator returns the element with the index index.
  /*!
   * \param index The index of the element.
   */
  const T & operator[] (size_t index) const
  {
    assert (size > index);
    return coord[index];
  }
};


#endif
