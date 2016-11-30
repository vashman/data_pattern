//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

#include <type_traits>
#include <iterator>
#include "model.hpp"
#include "bits/map_type.hpp"

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
begin (
  input_model <Device, Map> & _mdl
)
-> decltype (typesystems::get<T> (_mdl.map)(_mdl.device))
{
return typesystems::get<T> (_mdl.map)(_mdl.device);
}

template <typename T, typename Device, typename Map>
auto
cbegin (
  input_model <Device, Map> const & _mdl
)
-> decltype (typesystems::get<const T> (_mdl.map)(_mdl.device))
{
return typesystems::get<const T> (_mdl.map)(_mdl.device);
}

template <typename T, typename Device, typename Map>
auto
end (
  input_model <Device, Map> & _mdl
)
-> decltype ( typesystems::get<end_iterator_tag<T>>
  (_mdl.map)(_mdl.device)
){
return typesystems
::get<end_iterator_tag<T>>(_mdl.map)(_mdl.device);
}

template <typename T, typename Device, typename Map>
auto
cend (
  input_model <Device, Map> const & _mdl
)
-> decltype (typesystems::get<end_iterator_tag<const T>>
  (_mdl.map)(_mdl.device)
){
return typesystems
::get<end_iterator_tag<const T>>(_mdl.map)(_mdl.device);
}

namespace bits {

template <typename T, typename Device, typename Map>
bool
empty (
  input_model <Device, Map> const & _mdl
, std::output_iterator_tag const
){
return true;
}

template <typename T, typename Device, typename Map>
bool
empty (
  input_model <Device, Map> const & _mdl
, std::input_iterator_tag const
){
return cbegin<T>(_mdl) == cend<T>(_mdl);
}

} /* bits */

template <typename T, typename Device, typename Map>
bool
empty (
  input_model <Device, Map> const & _mdl
){
return bits::empty <T>(
  _mdl
,  typename std::iterator_traits<decltype (cbegin<T>(_mdl))>
 ::iterator_category()
);
}

template <typename Device, typename Map, typename Iter>
void
sync (
  input_model <Device, Map> &
, Iter
, Iter
);

/* input value */
template <typename T, typename Device, typename Map>
input_model <Device, Map> &
operator >> (
  input_model <Device, Map> &
, T &
);

///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, signed short &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, unsigned short &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, signed int &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, unsigned int &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, signed long &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, unsigned long &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, float &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, double &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, long double &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, char &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, signed char &
//);
//
///* input value */
//template <typename Device, typename Sync>
//input_model <Device, Sync> &
//operator >> (
//  input_model <Device, Sync> &
//, unsigned char &
//);

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
//#include "bits/string_data_model_shifts.hpp"
#endif

