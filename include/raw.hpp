// represents raw data.

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_RAW_HPP
#define DATA_PATTERN_RAW_HPP

#include <memory>
#include <cstring>
#include <stdint.h>

namespace data_pattern {

template <typename Allocator = std::allocator<uint8_t>>
class raw {

uint8_t * data_ptr;
std::size_t data_size;
Allocator allocator;

public:

typedef uint8_t data_type;

/* ctor */
explicit
raw (
  Allocator const & _alloc = Allocator()
);

/* ctor
 * The constructor must gurantee a copy
 * of the data passed into it.
 */
raw (
  data_type const * const
, std::size_t
, Allocator const & _alloc = Allocator()
);

template <typename T>
raw (
  T const &
, Allocator const & _alloc = Allocator()
);

raw (raw const &);
raw (raw &&);
~raw();

/* copy assignment */
template <typename Alloc>
raw &
operator = (raw<Alloc> const &);

raw &
operator = (raw const &);

raw
operator = (raw &&);

std::size_t
size () const;

data_type * const
data () const;

Allocator
get_allocator() const;

}; /* raw */

template <typename Allocator>
std::size_t
size (
  raw<Allocator> const &
);

template <typename Allocator>
Allocator
get_allocator (
  raw<Allocator> const &
);

template <typename Allocator>
typename raw<Allocator>::data_type * const
begin (
  raw<Allocator> &
);

template <typename Allocator>
typename raw<Allocator>::data_type * const
end (
  raw<Allocator> &
);

template <typename Allocator>
typename raw<Allocator>::data_type const * const
cbegin (
  raw<Allocator> const &
);

template <typename Allocator>
typename raw<Allocator>::data_type const * const
cend (
  raw<Allocator> const &
);

} /* data_pattern */
#endif
#include "bits/raw.tcc"

