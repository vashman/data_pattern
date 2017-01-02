//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

#include <type_traits>
#include "model.hpp"

namespace data_pattern {

/* input model */
template <typename Device, typename Map>
class input_model;

template <typename Device, typename Map>
input_model <Device, Map>
make_input_model (
  Device &&
, Map &&
);

template <typename T, typename Device, typename Map>
auto
input_begin (
  input_model <Device, Map> & _mdl
)
-> decltype (begin<T>(_mdl.device, _mdl.map))
{
return begin<T>(_mdl.device, _mdl.map);
}

template <typename T, typename Device, typename Map>
auto
input_end (
  input_model <Device, Map> & _mdl
)
-> decltype (end<T>(_mdl.device, _mdl.map)
){
return end<T>(_mdl.device, _mdl.map);
}

template <typename T, typename Device, typename Map>
bool
empty (
  input_model <Device, Map> & _mdl
){
return input_begin<T>(_mdl) == input_end<T>(_mdl);
}

template <
  typename T, typename Device, typename Map, typename Iter >
void
sync (
  input_model <Device, Map> &
, Iter
);

/* input value */
template <typename T, typename Device, typename Map>
T
read (
  input_model <Device, Map> &
);

/* input value */
template <typename T, typename Device, typename Map>
input_model <Device, Map> &
operator >> (
  input_model <Device, Map> &
, T &
);

/* input model */
template <typename Device, typename Map>
struct input_model
: public virtual  model <Device>
{

Map map;

/* ctor */
input_model (
  Device &&
, Map &&
);

/* dtor */
virtual
~input_model() noexcept = default;

/* ctor move */
input_model (
  input_model<Device, Map> &&
) = default;

/* assignment operator move */
input_model <Device, Map> &
operator = (
  input_model<Device, Map> &&
) = default;

/* ctor copy */
input_model (
  input_model <Device, Map> const &
) = delete;

/* assignment operator copy */
input_model <Device, Map> &
operator = (
  input_model <Device, Map> const &
) = delete;

}; /* input model */

} /* data_pattern */
#include "bits/input_model.tcc"
#endif

