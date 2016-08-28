//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_TCC
#define DATA_PATTERN_INPUT_MODEL_TCC

#include <utility>

namespace data_pattern {

/* ctor */
template <
  typename Device
, typename GetIteratorMap >
  input_model <
  Device, GetIteratorMap >
::input_model (
  Device && _device
, GetIteratorMap && _map
)
: model <Device> (
    std::forward<Device>(_device)
  )
, iterator_map (std::forward<GetIteratorMap>(_map))
{}

template <
  typename T
, typename Device
, typename GetIteratorMap >
  typename input_model
  <Device, GetIteratorMap>
:: template iterator<T>
make_input_iterator (
  input_model <Device, GetIteratorMap>
  & _mdl
){
return typename input_model
  <Device, GetIteratorMap>
:: template iterator<T> (_mdl);
}

template <
  typename T
, typename Device
, typename GetIteratorMap >
  typename input_model
  <Device, GetIteratorMap>
:: template iterator<T>
make_end_input_iterator (
  input_model <Device, GetIteratorMap>
  & _mdl
){
return typename input_model
  <Device, GetIteratorMap>
:: template iterator<T> (_mdl);
}

/* make input model */
template <
  typename Device
, typename GetIteratorMap >
input_model<Device, GetIteratorMap>
make_input_model (
  Device && _device
, GetIteratorMap && _map
){
return input_model 
<Device, GetIteratorMap> (
  std::forward<Device>(_device)
, std::forward<GetIteratorMap>(_map)
);
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, bool & _var
){
auto & iter =
  get<bool>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, signed short & _var
){
auto & iter = get<signed short>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, unsigned short & _var
){
auto & iter = get<unsigned short>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, signed int & _var
){
auto & iter = get<signed int>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, unsigned int & _var
){
auto & iter = get<unsigned int>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, signed long & _var
){
auto & iter = get<signed long>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, unsigned long & _var
){
auto & iter = get<unsigned long>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, float & _var
){
auto & iter = get<float>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, double & _var
){
auto & iter = get<double>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, long double & _var
){
auto & iter = get<long double>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, char & _var
){
using data_pattern::get;
auto & iter = data_pattern::get<char>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, signed char & _var
){
auto & iter = get<signed char>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap > &
operator >> (
  input_model <Device, GetIteratorMap>
  & _mdl
, unsigned char & _var
){
auto & iter = get<unsigned char>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

} /* data_pattern */
#endif

