//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_ITERATOR_HPP
#define TYPESYSTEMS_REWRITE_ITERATOR_HPP

namespace data_pattern {

/* rewrite iterator */
template <
  typename MakeOutputIterator
, typename OutputIterator
, typename MakeInputIterator
, typename InputIterator
, typename... Ts >
class rewrite_iterator
: public
  orewrite_iterator <
    MakeOutputIterator
  , OutputIterator
  , Ts... >
, irewrite_iterator <
    MakeInputIterator
  , InputIterator
  , Ts... >
{
public:

/* ctor */
rewrite_iterator (
  orewrite_iterator <
    MakeOutputIterator
  , OutputIterator
  , Ts... >
, irewrite_iterator <
    MakeInputIterator
  , InputIterator
  , Ts... >
);

/* ctor copy */
rewrite_iterator (
  rewrite_iterator <
    OutputIterator
  , InputIterator
  , Ts... >
  const &
) = default;

/* operator copy assignment */
rewrite_iterator <
  OutputIterator,InputIterator,Ts... > &
operator = (
  rewrite_iterator <
    OutputIterator,InputIterator,Ts... >
  const &
) = default;

/* ctor move */
rewrite_iterator (
  rewrite_iterator <
    OutputIterator,InputIterator,Ts... > &&
) = default;

/* operator move assignment */
rewrite_iterator <
  OutputIterator,InputIterator,Ts... > &
operator = (
  rewrite_iterator <
    OutputIterator,InputIterator,Ts... > &&
) = default;

/* dtor */
~rewrite_iterator () = default;

/* rewrite iterator assignment
  operator. */
template <typename U>
rewrite_iterator <
  OutputIterator,InputIterator,Ts... > &
operator = (
  U const &
);

template <typename U>
operator U ();

rewrite_iterator <
  OutputIterator,InputIterator,Ts... > &
operator * ();

rewrite_iterator <
  OutputIterator,InputIterator,Ts... > * 
operator -> ();
}; /* rewrite_iterator */

/* make rewrite iterator */
template <
  typename OutputIterator
, typename InputIterator, typename... Ts >
rewrite_iterator <
  OutputIterator, InputIterator, Ts... >
make_rewrite_iterator (
  orewrite_iterator<OutputIterator,Ts...>
, irewrite_iterator<InputIterator,Ts...>
);

} /*  data_pattern */
#endif

