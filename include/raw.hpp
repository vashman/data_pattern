// represents raw data.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_RAW_HPP
#define DATA_PATTERN_RAW_HPP

#include <memory>
#include <cstring>

namespace data_pattern {

template <
  typename T = unsigned char
, typename Allocator = std::allocator<T> >
class raw {

T * data_ptr;
std::size_t data_size;
Allocator allocator;

public:

/* ctor */
explicit
raw(
  Allocator const & _alloc = Allocator()
);

/* ctor
 * The constructor must gurantee a copy
 * of the data passed into it.
 */
raw (
  T const * const
, std::size_t
, Allocator const & _alloc = Allocator()
);

/* ctor copy */
raw (
  raw<T,Allocator> const &
);

/* copy assignment */
template <typename Alloc>
raw<T,Allocator> &
operator = (
  raw<T,Alloc> const &
);

/* copy assignment */
raw<T,Allocator> &
operator = (
  raw<T,Allocator> const &
);

/* move ctor */
raw (
  raw<T,Allocator> &&
);

/* move operator */
raw<T,Allocator>
operator = (
  raw<T,Allocator> &&
);

/* dtor */
~raw();

std::size_t
size () const;

T * const
data () const;

Allocator
get_allocator() const;

}; /* raw */

template <typename T, typename Allocator>
Allocator
raw<T,Allocator>::get_allocator (
) const {
return this->allocator;
}

/* default ctor */
template <typename T, typename Allocator>
raw<T,Allocator>::raw (
  Allocator const & _alloc
)
: data_ptr (nullptr)
, data_size (0)
, allocator (_alloc){ 
}

/* copy ctor */
template <typename T, typename Allocator>
raw<T,Allocator>::raw (
  raw<T,Allocator> const & _other
)
: data_ptr (nullptr)
, data_size (_other.data_size)
, allocator (_other.allocator) {
  if (this != &_other){
  this->data_ptr =
    this->allocator.allocate (_other.data_size);
  memcpy (data_ptr, _other.data_ptr, _other.data_size);
  this->data_size = _other.data_size;
  }
}

/* ctor */
template <typename T, typename Allocator>
raw<T,Allocator>::raw (
  T const * const _data
, std::size_t _size
, Allocator const & _alloc
)
: data_ptr (nullptr)
, data_size (_size)
, allocator (_alloc) {
this->data_ptr = this->allocator.allocate(_size);
memcpy(data_ptr, _data, _size);
}

/* dtor */
template <typename T, typename Allocator>
raw<T,Allocator>::~raw (
){
this->allocator.deallocate(this->data_ptr, this->data_size);
}

/* size */
template <typename T, typename Allocator>
std::size_t
raw<T,Allocator>::size (
) const {
return this->data_size;
}

/**/
template <typename T, typename Allocator>
T * const
raw<T,Allocator>::data (
) const {
return this->data_ptr;
}

/* copy assignment */
template <typename T, typename Allocator>
template <typename Alloc>
raw<T,Allocator> &
raw<T,Allocator>::operator = (
  raw<T,Alloc> const & _rhs
){
  if (this != &_rhs){
  this->data_ptr =
    this->allocator.allocate (_rhs.data_size);
  memcpy (data_ptr, _rhs.data_ptr, _rhs.data_size);
  this->data_size = _rhs.data_size;
  }
return *this;
}

/* copy assignment */
template <typename T, typename Allocator>
raw<T,Allocator> &
raw<T,Allocator>::operator = (
  raw<T,Allocator> const & _rhs
){
  if (this != &_rhs){
  this->data_ptr =
    this->allocator.allocate (_rhs.data_size);
  memcpy (data_ptr, _rhs.data_ptr, _rhs.data_size);
  this->data_size = _rhs.data_size;
  }
return *this;
}

} /* data_pattern */
#include "bits/raw_data_model_shifts.hpp"
#endif

