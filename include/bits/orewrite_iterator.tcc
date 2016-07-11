//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OREWRITE_ITERATOR_TCC
#define TYPESYSTEMS_OREWRITE_ITERATOR_TCC

namespace data_pattern {

/* orewrite iterator ctor */
template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
template <
  typename Device, typename... Writers >
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
::orewrite_iterator (
  MakeIterator _mkiter
, Device & _buffer
, Writers... _writers
)
: make_iterator (_mkiter)
, iterator (_mkiter(_buffer))
, map (  typesystems::make_owriter <
    Ts, Iterator >
  (_writers)... ) {
}

/* orewriter iterator assignment
  operator. */
template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
template <typename U>
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
::operator = (
  U const & _val
){
using typesystems::get;
using typesystems::use_owriter;

  if (! use_owriter (
      _val
    , this->iterator
    , get<U>(this->map) )
  ){
 throw "unable to write type.";
 }
return *this;
}

/**/
template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
::operator * (
){
return *this;
}

/**/
template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
orewrite_iterator <
  MakeIterator, Iterator, Ts... > *
  orewrite_iterator <
  MakeIterator, Iterator, Ts... >
::operator -> (
){
return this;
}

template <
  typename MakeIterator
, typename Iterator
, typename... Ts >
template <typename Device>
orewrite_iterator <
  MakeIterator, Iterator, Ts... > &
  orewrite_iterator <
    MakeIterator, Iterator, Ts... >
::operator ()(
  Device & _buffer
){
this->iterator
  = this->make_iterator(_buffer);
return *this;
}

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
, Ts... > {
return orewrite_iterator <
  MakeIterator
, decltype(_makeiter(_buffer))
, Ts... >
(_makeiter, _buffer, _writers...);
}

} /* data_pattern */
#endif

