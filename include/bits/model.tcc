//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_MODEL_TCC
#define DATA_PATTERN_BITS_MODEL_TCC

#include <utility>
#include <iterator>
#include <tuple> // std::get
#include "map_type.hpp" // typesystems::get

namespace data_pattern {

template <typename Device>
template <typename... Ts>
model<Device>::model (
  Ts... _args
)
: device (std::forward<Ts>(_args)...)
, state (model_state::operable)
{}

template <typename Device>
model<Device>::operator Device(){
return this->device;
}

template <typename Device, typename Locale>
chain_model<Device, Locale>::chain_model (
  model<Device> & _mdl
, Locale & _loc
)
: mdl (_mdl)
, loc (_loc)
{}

template <typename Device>
bool
model<Device>::is_operable (
) const {
return model_state::operable == this->state;
}

template <typename T, typename Device, typename Locale>
auto
begin (
  Device & _device
, Locale & _loc
)
-> decltype (typesystems::get<typename std::decay<T>::type> (_loc)(_device))
{
using typesystems::get;
using type = typename std::decay<T>::type;

return get<type> (_loc)(_device);
}

template <typename T, typename Device, typename Locale>
auto
end (
  Device & _device
, Locale & _loc
)
-> decltype (typesystems::get<end_iterator_tag<typename std::decay<T>::type>>
  (_loc)(_device)
){
using typesystems::get;
using type = typename std::decay<T>::type;

return get<end_iterator_tag<type>>(_loc)(_device);
}

template <
  typename T
, typename Device
, typename Locale
, typename Iterator >
void
sync (
  model<Device> & _mdl
, Locale & _loc
, Iterator _iter
){
using std::get;
using type = typename std::decay<T>::type;

get<sync_iterator_tag<type>>(_loc)(_mdl, _iter);
}

/* input value */
template <typename T, typename Device, typename Locale>
T
read (
  model<Device> & _mdl
, Locale & _loc
){
   if (! _mdl.is_operable()) throw "err";
auto iter = begin<T>(_mdl.device, _loc);
T temp {*iter};
sync <T>(_mdl, _loc, iter);
return temp;
}

template <typename T, typename Device, typename Locale>
void
write (
  T const & _var
, model <Device> & _mdl
, Locale & _loc
){
  if (! _mdl.is_operable()) throw "err";
auto iter = begin<T>(_mdl.device, _loc);
*iter = _var;
sync <T>(_mdl, _loc, iter);
}

template <typename T, typename Device, typename Locale>
bool
empty (
  model<Device> & _mdl
, Locale & _loc
){
using iter_cat = typename std::iterator_traits <
  decltype(begin<T>(_mdl.device, _loc))>::iterator_category;

return bits::empty<T>(_mdl, _loc, iter_cat{});
}

template <typename T, typename Device, typename Locale>
bool
full (
  model<Device> & _mdl
, Locale & _loc
){
using iter_cat = typename std::iterator_traits <
  decltype(begin<T>(_mdl.device, _loc))>::iterator_category;

return bits::full<T>(_mdl, _loc, iter_cat{});
}

template <typename Device, typename Locale>
chain_model<Device, Locale>
chain (
  model<Device> & _mdl
, Locale & _loc
){
return chain_model<Device, Locale>{_mdl, _loc};
}

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale> &
operator >> (
  chain_model<Device, Locale> & _mdl
, T & _var
){
_var = read<T>(_mdl.mdl, _mdl.loc);
return _mdl;
}

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale> &
operator << (
  chain_model<Device, Locale> & _mdl
, T const & _var
){
write(_var, _mdl.mdl, _mdl.loc);
return _mdl;
}

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale>
operator >> (
  chain_model<Device, Locale> && _mdl
, T & _var
){
_var = read<T>(_mdl.mdl, _mdl.loc);
return _mdl;
}

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale>
operator << (
  chain_model<Device, Locale> && _mdl
, T const & _var
){
write(_var, _mdl.mdl, _mdl.loc);
return _mdl;
}

namespace bits {

template <typename T, typename Device, typename Locale>
bool
empty (
  model<Device> &
, Locale &
, std::output_iterator_tag
){
return true;
}

template <typename T, typename Device, typename Locale>
bool
full (
  model<Device> &
, Locale &
, std::output_iterator_tag
){
return false;
}

template <
  typename T
, typename Device
, typename Locale
, typename IteratorTag >
bool
empty (
  model<Device> & _mdl
, Locale & _loc
, IteratorTag
){
return
begin<T>(_mdl.device, _loc) == end<T>(_mdl.device, _loc);
}

template <
  typename T
, typename Device
, typename Locale
, typename IteratorTag >
bool
full (
  model<Device> & _mdl
, Locale & _loc
, IteratorTag
){
return
begin<T>(_mdl.device, _loc) != end<T>(_mdl.device, _loc);
}

}/* bits */ } /* data_pattern */
#endif
