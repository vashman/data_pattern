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
, typename GetIteratorMap
, typename Sync >
  input_model <
  Device, GetIteratorMap, Sync >
::input_model (
  Device _device
, GetIteratorMap _map
, Sync _sync
)
: model <Device,Sync> (
    std::move(_device)
  , std::move(_sync)
  )
, iterator_map (std::move(_map))
{}

template <
  typename Device
, typename GetIteratorMap
, typename Sync >
  typename input_model <
    Device, GetIteratorMap, Sync >
::iterator
begin (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
){
return typename input_model <
    Device, GetIteratorMap, Sync >
::iterator (_mdl);
}

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
  const & _mdl
){
return typename input_model <
  Device, GetIteratorMap, Sync >
::iterator();
}

/* make input model */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model<
  Device, GetIteratorMap, Sync >
make_input_model (
  Device _device
, GetIteratorMap _map
, Sync _sync
){
return input_model <
  Device, GetIteratorMap, Sync >
(
  std::move(_device)
, std::move(_map)
, std::move(_sync)
);
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, bool & _var
){
auto & iter =
  get<bool>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, signed short & _var
){
auto & iter = get<signed short>
  (_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, unsigned short & _var
){
auto & iter = get<unsigned shor>
  (_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, signed int & _var
){
auto & iter = get<signed int>
  (_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, unsigned int & _var
){
auto & iter = get<unsigned int>
  (_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, signed long & _var
){
auto & iter =
  get<signed long>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, unsigned long & _var
){
auto & iter = get<unsigned long>
  (_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, float & _var
){
auto & iter =
  get<float>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, double & _var
){
auto & iter =
  get<double>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, long double & _var
){
auto & iter =
  get<long double>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

/* input value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, char & _var
){
auto & iter =
  get<char>(_mdl.iterator_map());
_var = *iter;
++iter;
return _mdl;
}

} /* data_pattern */
#endif

