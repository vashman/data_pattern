//

#ifndef DATA_PATTERN_RAW_HPP
#define DATA_PATTERN_RAW_HPP

#include <memory>
#include <cstring>

namespace data_pattern {

template <
  typename T
, typename
  allocator = std::allocator<T*>
>
class raw_data {
public:
  /* ctor */
  raw_data();

  /* ctor
    The constructor must gurantee a copy
    of the data passed into it.
  */
  raw_data(T const *, std::size_t);

  /* ctor copy */
  template <typename alloc>
  raw_data(
    raw_data<T,alloc> const &
  );

  /* copy assignment */
  template <typename alloc>
  raw_data<T,allocator> &
  operator=(
    raw_data<T,alloc> const &
  );

  std::size_t
  size() const;

  T *
  ptr() const;

  /* pull
    Pull data from stream.
  */
//  pull();

  /* push
    Push data to the stream.
  */
//  push();

  /* page
    Page through the stream.
  */
//  page();
private:
  T * data;
  std::size_t data_size;
};

template <typename T, typename allocator>
raw_data<T,allocator>::raw_data(
)
: data (nullptr)
, data_size(0){
}

template <typename T, typename allocator>
template <typename alloc>
raw_data<T,allocator>::raw_data(
  raw_data<T,alloc> const & _other
)
: data (nullptr)
, data_size(_other.data_size){

}

/* ctor */
template <typename T, typename allocator>
raw_data<T,allocator>::raw_data(
  T const * _data
, std::size_t _size
)
: data (nullptr)
, data_size(_size) {
allocator alloc;
this->data = alloc.allocate(_size, 0);
memcpy(data, _data, _size);
}

/**/
template <typename T, typename allocator>
std::size_t
raw_data<T,allocator>::size(
) const {
return this->data_size;
}

/**/
template <typename T, typename allocator>
T *
raw_data<T,allocator>::ptr(
) const {
return this->data;
}

/* copy assignment */
template <typename T, typename allocator>
template <typename alloc>
raw_data<T,allocator> &
raw_data<T,allocator>::operator=(
  raw_data<T,alloc> const & _rhs
){
  if (true){
  allocator Alloc;
  this->data
    = Alloc.allocate(_rhs.data_size, 0);
  memcpy(
    data
  , _rhs.data
  , _rhs.data_size
  );
  this->data_size = _rhs.data_size;
  }
return *this;
}

typedef raw_data<void> raw;

} /* data_pattern */
#include "bits/raw_data_model_shifts.hpp"
#endif
