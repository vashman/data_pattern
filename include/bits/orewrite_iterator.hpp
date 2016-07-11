//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OREWRITE_ITERATOR_HPP
#define TYPESYSTEMS_OREWRITE_ITERATOR_HPP

namespace data_pattern {

/* orewriter iterator */
template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
class orewrite_iterator
{

MakeIterator make_iterator;

Iterator iterator;

typesystems::type_map < typesystems
  ::owriter_base, Ts... > map;

public:

/* ctor */
template <
  typename Device, typename... Writers >
orewrite_iterator (
  MakeIterator
, Device &
, Writers...
);

/* ctor copy*/
orewrite_iterator (
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
  const &
) = default;

/* operator copy assignment */
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
operator = (
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
  const &
) = default;

/* ctor move */
orewrite_iterator (
  orewrite_iterator <
    MakeIterator, Iterator, Ts... > &&
) = default;

/* operator move assignment */
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
operator = (
  orewrite_iterator <
    MakeIterator, Iterator, Ts... > &&
) = default;

/* dtor */
~orewrite_iterator () = default;

/* assignment operator */
template <typename U>
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
operator = (
  U const &
);

orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
operator * ();

orewrite_iterator <
  MakeIterator, Iterator, Ts... > * 
operator -> ();

template <typename Device>
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
operator ()(
  Device &
);

}; /* orewrite_iterator */

template <
  typename... Ts
, typename MakeIterator
, typename Device
, typename... Writers >
auto
make_orewrite_iterator (
  MakeIterator _makeiter
, Device & _buffer
, Writers... _writers
) -> orewrite_iterator <
  MakeIterator
, decltype(_makeiter(_buffer))
, Ts... >;

} /*  data_pattern */
#endif

