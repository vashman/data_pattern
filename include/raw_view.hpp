// represents raw data.

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_RAW_VIEW_HPP
#define DATA_PATTERN_RAW_VIEW_HPP

#include "raw.hpp"

namespace data_pattern {

class raw_view;

class raw_view {

raw<>::data_type * data_begin_ptr;
raw<>::data_type * data_end_ptr;

public:

template <typename Allocator>
raw_view (
  raw<Allocator> const & _raw
, std::size_t _size
);

template <typename Allocator>
raw_view (
  raw<Allocator> const & _raw
);

template <typename Allocator>
raw_view &
operator = (
  raw<Allocator> const & _raw
);

raw_view (raw_view const &) = default;
raw_view (raw_view &&) = default;
~raw_view() = default;

raw_view &
operator = (raw_view const &) = default;

raw_view &
operator = (raw_view &&) = default;

raw<>::data_type const *
data() const ;

raw<>::data_type const *
data_end() const ;

std::size_t
size() const;

bool
operator == (
  raw_view const &
) const;

}; /* raw_view */

bool
operator != (
  raw_view const &
, raw_view const &
);

std::size_t
size (
  raw_view const &
);

raw<>::data_type const *
begin (
  raw_view const &
);

raw<>::data_type const *
end (
  raw_view const &
);

raw<>::data_type const *
cbegin (
  raw_view const &
);

raw<>::data_type const *
cend (
  raw_view const &
);

template <typename Allocator>
raw_view::raw_view (
  raw<Allocator> const & _raw
, std::size_t _size
)
: data_begin_ptr (_raw.data())
, data_end_ptr (_raw.data() + _size)
{}

template <typename Allocator>
raw_view::raw_view (
  raw<Allocator> const & _raw
)
: data_begin_ptr (_raw.data())
, data_end_ptr (_raw.data() + _raw.size())
{}

template <typename Allocator>
raw_view &
raw_view::operator = (
  raw<Allocator> const & _raw
){
this->data_begin_ptr = _raw.data();
this->data_end_ptr = (_raw.data() + _raw.size());
return *this;
}

raw<>::data_type const *
raw_view::data (
) const {
return this->data_begin_ptr;
}

raw<>::data_type const *
raw_view::data_end (
) const {
return this->data_end_ptr;
}

std::size_t
raw_view::size (
) const {
return this->data_end_ptr - this->data_begin_ptr;
}

std::size_t
size (
  raw_view const & _raw
){
return _raw.size();
}

raw<>::data_type const *
begin (
  raw_view const & _raw
){
return _raw.data();
}

raw<>::data_type const *
end (
  raw_view const & _raw
){
return _raw.data_end();
}

raw<>::data_type const *
cbegin (
  raw_view const & _raw
){
return _raw.data();
}

raw<>::data_type const *
cend (
  raw_view const & _raw
){
return _raw.data_end();
}

bool
raw_view::operator == (
  raw_view const & _rhs
) const {
using data_pattern::size;

  if (size(*this) != size(_rhs)) return false;
return std::equal(begin(*this), end(*this), begin(_rhs));
}

bool
operator != (
  raw_view const & _lhs
, raw_view const & _rhs
){
return !(_lhs == _rhs);
}

} /* data_pattern */
#endif
