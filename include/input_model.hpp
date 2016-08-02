//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

#include "model.hpp"

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
  Device
, GetIteratorMap
, Sync
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
  Device
, GetIteratorMap
, Sync
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

class iterator
: public
  std::iterator <
    std::input_iterator_tag, iterator >{

input_model <
  Device, GetIteratorMap, Sync >
* input_mdl;

public:

explicit
iterator (
  input_model <
    Device, GetIteratorMap, Sync >
 & _mdl
)
: input_mdl (&_mdl)
{}

explicit
iterator () : input_mdl (nullptr){}

iterator (iterator const &) = default;

iterator &
operator = (iterator const &) = default;

iterator (iterator &&) = default;

iterator &
operator = (iterator &&) = default;

~iterator () = default;

iterator &
operator * (){
return *this;
}

iterator &
operator -> (){
return this;
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

template <typename T>
operator T(){
T temp;
*(this->input_mdl) >> temp;
return temp;
}

bool
operator == (
  iterator const &
) const {
return (
  this->input_mdl->state
== model_state::end
);
}

bool
operator != (
  iterator const & _lhs
) const {
return !(*this == _lhs);
}

}; /*  iterator */
}; /* input model */

template <
  typename Device
, typename GetIteratorMap
, typename Sync >
  typename input_model <
    Device, GetIteratorMap, Sync >
::iterator
begin (
  input_model <
    Device, GetIteratorMap, Sync > &
);

template <
  typename Device
, typename GetIteratorMap
, typename Sync >
  typename input_model <
    Device, GetIteratorMap, Sync >
::iterator
end (
  input_model <
    Device, GetIteratorMap, Sync >
  const &
);

} /* data_pattern */
#include "bits/input_model.tcc"
#endif

