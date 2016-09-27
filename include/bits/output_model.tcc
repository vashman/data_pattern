//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_TCC
#define DATA_PATTERN_OUTPUT_MODEL_TCC

#include <utility>

namespace data_pattern {

/* ctor */
template <
  typename Device
, typename GetIteratorMap
 >
  output_model <Device, GetIteratorMap>
::output_model (
  Device && _device
, GetIteratorMap && _output_iter
)
: model <Device> (
    std::forward<Device>(_device)
  )
, iterator_map (std::forward<GetIteratorMap>(_output_iter))
{}

/* make output model */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap>
make_output_model (
  Device && _device
, GetIteratorMap && _iter_map
){
return output_model <Device, GetIteratorMap> (
  std::forward<Device>(_device)
, std::forward<GetIteratorMap>(_iter_map));
}

template <
  typename T
, typename Device
, typename GetIteratorMap >
  typename output_model <Device, GetIteratorMap>
:: template iterator<T>
make_output_iterator (
  output_model <Device, GetIteratorMap>
  & _mdl
){
return typename output_model <Device, GetIteratorMap>
:: template iterator<T> (_mdl);
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, bool const & _var
){
auto && iter = get<bool>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, signed short const & _var
){
auto && iter = get<signed short>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, unsigned short const & _var
){
auto && iter = get<unsigned short>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, signed int const & _var
){
auto && iter = get<signed int>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, unsigned int const & _var
){
auto && iter = get<unsigned int>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, signed long const & _var
){
auto & iter = get<signed long>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, unsigned long const & _var
){
auto && iter = get<unsigned long>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
 output_model <Device, GetIteratorMap>
  & _mdl
, float const & _var
){
auto && iter = get<float>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, double const & _var
){
auto && iter = get<double>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, long double const & _var
){
auto && iter = get<long double>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, signed char const & _var
){
auto && iter = get<signed char>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, unsigned char const & _var
){
auto && iter = get<unsigned char>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap>
  & _mdl
, char const & _var
){
using data_pattern::get;
auto && iter = get<char>(_mdl);
*iter = _var;
++iter;
return _mdl;
}

} /* data_pattern */
#endif

