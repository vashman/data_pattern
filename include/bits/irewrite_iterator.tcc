//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IREWRITE_ITERATOR_TCC
#define TYPESYSTEMS_IREWRITE_ITERATOR_TCC

namespace data_pattern {

/* irewrite iterator ctor */
template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
template <
  typename Device, typename... Writers >
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... >
::irewrite_iterator (
  MakeBeginIterator _make_iterator
, MakeEndIterator _make_end_iterator
, Device & _buffer
, Writers... _writers
)
: make_iterator (_make_iterator)
, make_end_iterator (_make_end_iterator)
, begin (_make_iterator(_buffer))
, end (_make_end_iterator(_buffer))
, map ( typesystems::make_iwriter <
    Ts, Iterator >
  (_writers)... ) {
}

/* irewriter iterator cast operator. */
template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
template <
  typename U
, typename >
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... >
::operator U (){
using typesystems::get;
using typesystems::use_iwriter;
U var;

  if (! use_iwriter (
      var
    , this->begin
    , this->end
    , get<U>(this->map) )
  ){
  throw "unable to write type.";
  }
return var;
}

template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... >
::operator * (
){
return *this;
}

template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > *
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... >
::operator -> (
){
return this;
}

/* operator () */
template <
  typename MakeBeginIterator
, typename MakeEndIterator
, typename Iterator
, typename... Ts >
template <typename Device>
irewrite_iterator <
  MakeBeginIterator
, MakeEndIterator
, Iterator
, Ts... > &
  irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , Iterator
  , Ts... >
::operator () (
  Device & _buffer
){
this->begin
  = this->make_iterator (_buffer);
this->end
  = this->make_end_iterator (_buffer);
return *this;
}

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
  , Ts... >
{
return irewrite_iterator <
    MakeBeginIterator
  , MakeEndIterator
  , decltype(_make_iterator(_buffer))
  , Ts... >
(
  _make_iterator
, _make_end_iterator
, _buffer
, _writers...
); 
}

} /* data_pattern */
#endif

