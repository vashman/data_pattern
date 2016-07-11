//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IREWRITE_ITERATOR_HPP
#define TYPESYSTEMS_IREWRITE_ITERATOR_HPP

#include <type_traits>
#include "is_any.hpp"

namespace data_pattern {

/* irewriter iterator */
template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
class irewrite_iterator
{

MakeBeginIterator make_iterator;
MakeEndIterator make_end_iterator;

Iterator begin, end;

typesystems::type_map < typesystems
  ::iwriter_base, Ts... > map;

public:

/* ctor */
template <
  typename Device, typename... Writers >
irewrite_iterator (
  MakeBeginIterator
, MakeEndIterator
, Device &
, Writers...
);

/* ctor copy*/
irewrite_iterator (
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... > const &
) = default;

/* operator copy assignment */
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
operator = (
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... > const &
) = default;

/* ctor move */
irewrite_iterator (
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... > &&
) = default;

/* operator move assignment */
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
operator = (
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... > &&
) = default;

/* dtor */
~irewrite_iterator () = default;

/* cast operator */
template <
  typename U
, typename = typename std::enable_if <
   bits::is_any<U,Ts...>::value >::type
>
operator U ();

irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
operator * ();

irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > * 
operator -> ();

template <typename Device>
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
operator ()(
  Device &
);

}; /* irewrite iterator */

template <
  typename... Ts
, typename MakeBeginIterator
, typename MakeEndIterator
, typename Device
, typename... Writers >
auto
make_irewrite_iterator (
  MakeBeginIterator _make_iterator
, MakeEndIterator _make_end_iterator
, Device & _buffer
, Writers... _writers
) -> irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , decltype(_make_iterator(_buffer))
  , Ts... >;

} /*  data_pattern */
#endif

