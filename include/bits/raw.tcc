// represents raw data.

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_RAW_TCC
#define DATA_PATTERN_BITS_RAW_TCC

namespace data_pattern {

template <typename Allocator>
Allocator
raw<Allocator>::get_allocator (
) const {
return this->allocator;
}

/* default ctor */
template <typename Allocator>
raw<Allocator>::raw (
  Allocator const & _alloc
)
: data_ptr (nullptr)
, data_size (0)
, allocator (_alloc)
{}

/* copy ctor */
template <typename Allocator>
raw<Allocator>::raw (
  raw<Allocator> const & _other
)
: data_ptr (nullptr)
, data_size (_other.data_size)
, allocator (_other.allocator)
{
  if (this != &_other){
  this->data_ptr =
    this->allocator.allocate (_other.data_size);
  memcpy (data_ptr, _other.data_ptr, _other.data_size);
  this->data_size = _other.data_size;
  }
}

/* ctor */
template <typename Allocator>
template <typename T>
raw<Allocator>::raw (
  T const & _src
, std::size_t _size
, Allocator const & _alloc
)
: data_ptr (nullptr)
, data_size (_size)
, allocator (_alloc)
{
this->data_ptr = this->allocator.allocate(_size);
memcpy(data_ptr, & _src, _size);
}

/* dtor */
template <typename Allocator>
raw<Allocator>::~raw (
){
  if (this->data_ptr == nullptr) return;
this->allocator.deallocate(this->data_ptr, this->data_size);
}

/* size */
template <typename Allocator>
std::size_t
raw<Allocator>::size (
) const {
return this->data_size;
}

template <typename Allocator>
std::size_t
size (
  raw<Allocator> const & _raw
){
return _raw.size();
}

/**/
template <typename Allocator>
typename raw<Allocator>::data_type *
raw<Allocator>::data (
) const {
return this->data_ptr;
}

/* copy assignment */
template <typename Allocator>
template <typename Alloc>
raw<Allocator> &
raw<Allocator>::operator = (
  raw<Alloc> const & _rhs
){
  if (this != &_rhs){
  this->data_ptr = this->allocator.allocate(_rhs.data_size);
  memcpy (data_ptr, _rhs.data_ptr, _rhs.data_size);
  this->data_size = _rhs.data_size;
  }
return *this;
}

/* copy assignment */
template <typename Allocator>
raw<Allocator> &
raw<Allocator>::operator = (
  raw<Allocator> const & _rhs
){
  if (this != &_rhs){
  this->data_ptr = this->allocator.allocate(_rhs.data_size);
  memcpy (data_ptr, _rhs.data_ptr, _rhs.data_size);
  this->data_size = _rhs.data_size;
  }
return *this;
}

/* move assignment */
template <typename Allocator>
raw<Allocator> &
raw<Allocator>::operator = (
  raw<Allocator> && _rhs
){
//propagate_on_container_move_assignmen ??
  if (this != &_rhs){
  this->data_size = std::move(_rhs.data_size);
  this->data_ptr = std::move(_rhs.data_ptr);
  _rhs.data_ptr = nullptr;
  }
return *this;
}

template <typename Allocator>
raw<Allocator>::raw(
  raw<Allocator> && _other
)
: data_ptr (std::move(_other.data_ptr))
, data_size (std::move(_other.data_size))
, allocator (std::move(_other.allocator))
{
_other.data_ptr = nullptr;
}

template <typename Allocator>
template <typename Allocator2>
bool
raw<Allocator>::operator == (
  raw<Allocator2> const & _rhs
) const {
  if (this->size() != _rhs.size()) return false;
return std::equal(begin(*this), end(*this), begin(_rhs));
}

template <typename Allocator1, typename Allocator2>
bool
operator != (
  raw<Allocator1> const & _lhs
, raw<Allocator2> const & _rhs
){
return !(_lhs == _rhs);
}

template <typename Allocator>
typename raw<Allocator>::data_type *
begin (
  raw<Allocator> & _raw
){
return _raw.data();
}

template <typename Allocator>
typename raw<Allocator>::data_type *
end (
  raw<Allocator> & _raw
){
typename raw<Allocator>::data_type * temp = _raw.data();
return temp += _raw.size();
}

template <typename Allocator>
typename raw<Allocator>::data_type const *
cbegin (
  raw<Allocator> const & _raw
){
return _raw.data();
}

template <typename Allocator>
typename raw<Allocator>::data_type const *
cend (
  raw<Allocator> const & _raw
){
typename raw<Allocator>::data_type * temp = _raw.data();
return temp += _raw.size();
}

} /* data_pattern */
#endif

