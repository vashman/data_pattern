//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_TCC
#define DATA_PATTERN_INPUT_MODEL_TCC

#include <utility>

namespace data_pattern {

/* ctor */
template <typename Device, typename Map>
input_model <Device, Map>::input_model (
  Device && _device
, Map && _map
)
: model <Device> (std::forward<Device>(_device))
, map (std::forward<Map>(_map))
{}

/* make input model */
template <typename Device, typename Map>
input_model<Device, Map>
make_input_model (
  Device && _device
, Map && _map
){
return input_model <Device, Map>
(std::forward<Device>(_device), std::forward<Map>(_map));
}

template <
  typename T, typename Device, typename Map, typename Iter >
void
sync (
  input_model <Device, Map> & _mdl
, Iter _iter
){
sync<T>(_mdl, _mdl.map, _iter);
}

/* input value */
template <typename T, typename Device, typename Map>
T
read (
  input_model <Device, Map> & _mdl
){
  if (_mdl.state == model_state::inoperable) throw "err";
auto iter = input_begin<T>(_mdl);
T temp {*iter};
sync <T>(_mdl, iter);
return temp;
}

/* input value */
template <typename T, typename Device, typename Map>
input_model <Device, Map> &
operator >> (
  input_model <Device, Map> & _mdl
, T & _var
){
_var = read<T>(_mdl);
return _mdl;
}

} /* data_pattern */
#endif

