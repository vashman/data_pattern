//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

#include "model.hpp"
#include "bits/map_type.hpp"

namespace data_pattern {

/* input model */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
class input_model;

template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
    Device, GetIteratorMap, Sync >
make_input_model (
  Device &&
, GetIteratorMap &&
, Sync &&
);

template <
  typename T
, typename Device
, typename GetIteratorMap
, typename Sync >
auto
get (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
)
-> decltype ( typesystems::get<T> (
  _mdl.iterator_map(_mdl.device)
  ))
{
return typesystems::get<T> (
  _mdl.iterator_map(_mdl.device)
);}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, bool &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, signed short &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, unsigned short &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, signed int &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync  >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, unsigned int &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, signed long &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, unsigned long &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, float &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, double &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, long double &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, char &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, signed char &
);

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync > &
, unsigned char &
);

/* input model */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
struct input_model
: public virtual 
  model <Device,Sync>
{
GetIteratorMap iterator_map;

/* ctor */
input_model (
  Device &&
, GetIteratorMap &&
, Sync &&
);

/* dtor */
virtual
~input_model() noexcept = default;

/* ctor move */
input_model (
  input_model <
    Device, GetIteratorMap, Sync > &&
) = default;

/* assignment operator move */
input_model <
  Device, GetIteratorMap, Sync > &
operator = (
  input_model <
    Device, GetIteratorMap, Sync > &&
) = default;

/* ctor copy */
input_model (
  input_model <
    Device, GetIteratorMap, Sync >
  const &
) = delete;

/* assignment operator copy */
input_model <
  Device, GetIteratorMap, Sync > &
operator = (
  input_model <
    Device, GetIteratorMap, Sync >
  const &
) = delete;

template <typename T>
class iterator {

typedef std::input_iterator_tag
  iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T* pointer;
typedef T& reference;

input_model <
  Device, GetIteratorMap, Sync >
* input_mdl;

T temp;

public:

explicit
iterator (
  input_model <
    Device, GetIteratorMap, Sync >
 & _mdl
)
: input_mdl (&_mdl)
, temp ()
{
sync(*(this->input_mdl));
*(this->input_mdl) >> this->temp;
}

explicit
iterator ()
: input_mdl (nullptr)
, temp ()
{}

iterator (iterator const &) = default;

iterator &
operator = (iterator const &) = default;

iterator (iterator &&) = default;

iterator &
operator = (iterator &&) = default;

~iterator () = default;

T &
operator * (){
return this->temp;
}

iterator *
operator -> (){
return &this->temp;
}

iterator
operator ++ (int){
sync(*(this->input_mdl));
return *this;
}

iterator &
operator ++ (){
sync(*(this->input_mdl));
return *this;
}

bool
operator == (
  iterator<T> const _rhs
) const {
return (
  this->input_mdl->state
== model_state::end
);}

bool
operator != (
  iterator<T> const _rhs
) const {
return !(_rhs == *this);
}

}; /*  iterator */
}; /* input model */

template <
  typename T
, typename Device
, typename GetIteratorMap
, typename Sync >
  typename input_model <
    Device, GetIteratorMap, Sync >
:: template iterator<T>
make_input_iterator (
  input_model <
    Device, GetIteratorMap, Sync > &
);

template <
  typename T
, typename Device
, typename GetIteratorMap
, typename Sync >
  typename input_model <
    Device, GetIteratorMap, Sync >
:: template iterator<T>
make_end_input_iterator (
  input_model <
    Device, GetIteratorMap, Sync > &
);

} /* data_pattern */
#include "bits/input_model.tcc"
#endif

