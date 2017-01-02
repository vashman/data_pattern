//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_TCC
#define DATA_PATTERN_OUTPUT_MODEL_TCC

#include <utility>
#include <type_traits>

namespace data_pattern {

/* ctor */
template <typename Device, typename Map>
output_model <Device, Map>::output_model (
  Device && _device
, Map && _map
)
: model <Device> (std::forward<Device>(_device))
, map (std::forward<Map>(_map))
{}

/* make output model */
template <typename Device, typename Map>
output_model <Device, Map>
make_output_model (
  Device && _device
, Map && _map
){
return output_model <Device, Map> (
  std::forward<Device>(_device), std::forward<Map>(_map) );
}

/* output value */
template <typename T, typename Device, typename Map>
void
write (
  output_model <Device, Map> & _mdl
, T const & _var
){
  if (_mdl.state == model_state::inoperable) throw "err";
auto iter = output_begin<T>(_mdl);
*iter = _var;
sync<T>(_mdl, iter);
}

/* output value */
template <typename T, typename Device, typename Map>
output_model <Device, Map> &
operator << (
  output_model <Device, Map> & _mdl
, T const & _var
){
write(_mdl, _var);
return _mdl;
}

template <typename T, typename Device, typename Map>
typename std::enable_if <
  ! bits::iterator_type <T, Device, Map>::value, bool >::type
full (
  output_model <Device, Map> & _mdl
){
using type = typename std::decay<T>::type;

return output_begin<type>(_mdl) == output_end<type>(_mdl);
}

template <typename T, typename Device, typename Map>
typename std::enable_if <
  bits::iterator_type <T, Device, Map>::value, bool >::type
full (
  output_model <Device, Map> const & _mdl
){
return false;
}

template <
  typename T, typename Device, typename Map, typename Iter >
void
sync (
  output_model<Device, Map> & _mdl
, Iter _iter
){
sync<T>(_mdl, _mdl.map, _iter);
}

} /* data_pattern */
#endif

