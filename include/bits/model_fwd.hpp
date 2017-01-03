//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_MODELFWD_HPP
#define DATA_PATTERN_BITS_MODELFWD_HPP

#include <iterator>

namespace data_pattern {

template <typename Device>
struct model;

template <typename T>
struct end_iterator_tag;

template <typename T>
struct sync_iterator_tag;

/* input value */
template <typename T, typename Device, typename Locale>
T
read (
  model<Device> &
, Locale &
);

template <typename T, typename Device, typename Locale>
void
write (
  T const &
, model <Device> &
, Locale &
);

template <
  typename T
, typename Device
, typename Locale
, typename Iterator >
void
sync (
  model<Device> & _mdl
, Locale & _fac
, Iterator _iter
);
/* c++ 14 required to remove trailing returns
template <typename T, typename Device, typename Locale>
auto
begin (
  Device &
, Locale &
);

template <typename T, typename Device, typename Locale>
auto
end (
  Device &
, Locale &
);*/

namespace bits {

template <typename T, typename Device, typename Locale>
bool
empty (
  model<Device> &
, Locale &
, std::output_iterator_tag
);

template <typename T, typename Device, typename Locale>
bool
full (
  model<Device> &
, Locale &
, std::output_iterator_tag
);

template <
  typename T
, typename Device
, typename Locale
, typename IteratorTag >
bool
empty (
  model<Device> &
, Locale &
, IteratorTag
);

template <
  typename T
, typename Device
, typename Locale
, typename IteratorTag >
bool
full (
  model<Device> &
, Locale &
, IteratorTag
);

}/* bits */

template <typename T, typename Device, typename Locale>
bool
empty (
  model<Device> &
, Locale &
);

template <typename T, typename Device, typename Locale>
bool
full (
  model<Device> &
, Locale &
);

template <typename Device, typename Locale>
struct chain_model;

template <typename Device, typename Locale>
chain_model<Device, Locale>
chain (
  model<Device> &
, Locale &
);

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale> &
operator >> (
  chain_model<Device, Locale> & _mdl
, T & _var
);

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale>
operator >> (
  chain_model<Device, Locale> && _mdl
, T & _var
);

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale> &
operator << (
  chain_model<Device, Locale> & _mdl
, T const & _var
);

template <typename T, typename Device, typename Locale>
chain_model<Device, Locale>
operator << (
  chain_model<Device, Locale> && _mdl
, T const & _var
);

} /* data_pattern */
#endif
