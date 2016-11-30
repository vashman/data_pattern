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
, Iter _first
, Iter _last
){
using std::get;

get<sync_iterator_tag<T>>(_mdl)(_mdl, _first, _last);
}

/* input value */
template <typename T, typename Device, typename Map>
input_model <Device, Map> &
operator >> (
  input_model <Device, Map> & _mdl
, T & _var
){
auto iter = begin<T>(_mdl);
_var = *iter;
sync <T>(_mdl, iter, ++iter);
return _mdl;
}
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> & _mdl
//, signed short & _var
//){
//auto && iter = get<signed short>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> & _mdl
//, unsigned short & _var
//){
//auto && iter = get<unsigned short>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> & _mdl
//, signed int & _var
//){
//auto && iter = get<signed int>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> & _mdl
//, unsigned int & _var
//){
//auto && iter = get<unsigned int>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, signed long & _var
//){
//auto && iter = get<signed long>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, unsigned long & _var
//){
//auto && iter = get<unsigned long>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, float & _var
//){
//auto && iter = get<float>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, double & _var
//){
//auto && iter = get<double>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, long double & _var
//){
//auto && iter = get<long double>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, char & _var
//){
//using data_pattern::get;
//auto &&  iter = data_pattern::get<char>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <
//  typename Device
//, typename Sync >
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync>
//  & _mdl
//, signed char & _var
//){
//auto && iter = get<signed char>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync > &
//operator >> (
//  input_model <Device, Sync> & _mdl
//, unsigned char & _var
//){
//auto && iter = get<unsigned char>(_mdl);
//_var = *iter;
//++iter;
//return _mdl;
//}

} /* data_pattern */
#endif

