// represents raw data.

//          Copyright Sundeep S. Sangha 2013 - 2017.
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
  raw const &
);

/* copy assignment */
template <typename Alloc>
raw &
operator = (
  raw<T,Alloc> const &
);

/* copy assignment */
raw &
operator = (
  raw const &
);

/* move ctor */
raw (
  raw &&
);

/* move operator */
raw
operator = (
  raw &&
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

} /* data_pattern */
#endif
#include "bits/raw.tcc"

