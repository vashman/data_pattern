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
  typename T
, typename Allocator
  = std::allocator<T*> >
class raw_data {

T * data;
std::size_t data_size;
Allocator allocator;

public:

/* ctor */
explicit
raw_data(
  Allocator const & _alloc = Allocator()
);

/* ctor
 * The constructor must gurantee a copy
 * of the data passed into it.
 */
raw_data (
  T const *
, std::size_t
, Allocator const & _alloc = Allocator()
);

/* ctor copy */
raw_data (
  raw_data<T,Allocator> const &
);

/* copy assignment */
raw_data<T,Allocator> &
operator = (
  raw_data<T,Allocator> const &
);

/* move ctor */
raw_data (
  raw_data<T,Allocator> &&
);

raw_data<T,Allocator>
operator = (
  raw_data<T,Allocator> &&
);

std::size_t
size () const;

T *
data () const;

Allocator
get_allocator() const;

}; /* raw */

template <typename T, typename Allocator>
raw_data<T,Allocator>::get_allocator (
) const {
return this->allocator;
}

/* default ctor */
template <typename T, typename Allocator>
raw_data<T,Allocator>::raw_data (
  Allocator const & _alloc
)
: data (nullptr)
, data_size (0)
, allocator (_alloc){ 
}

/* copy ctor */
template <typename T, typename Allocator>
raw_data<T,Allocator>::raw_data (
  raw_data<T,Allocator> const & _other
)
: data (nullptr)
, data_size (_other.data_size)
, Allocator (_other.allocator) {
}

/* ctor */
template <typename T, typename Allocator>
raw_data<T,Allocator>::raw_data (
  T const * _data
, std::size_t _size
, Allocator const & _alloc
)
: data (nullptr)
, data_size (_size)
, allocator (_alloc) {
this->data = this->allocator.allocate(_size, 0);
memcpy(data, _data, _size);
}

/**/
template <
  typename T, typename Allocator >
std::size_t
raw_data<T,Allocator>::size (
) const {
return this->data_size;
}

/**/
template <typename T, typename Allocator>
T *
raw_data<T,Allocator>::ptr (
) const {
return this->data;
}

/* copy assignment */
template <typename T, typename Allocator>
template <typename Alloc>
raw_data<T,Allocator> &
raw_data<T,Allocator>::operator = (
  raw_data<T,Alloc> const & _rhs
){
  if (true){
  this->data = this->allocator.allocate (
    _rhs.data_size, 0 );
  memcpy (data, _rhs.data, _rhs.data_size);
  this->data_size = _rhs.data_size;
  }
return *this;
}

using raw = raw_data <void>;

} /* data_pattern */
#include "bits/raw_data_model_shifts.hpp"
#endif

