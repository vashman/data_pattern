// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_REWRITE_TYPE_HPP
#define DATA_PATTERN_REWRITE_TYPE_HPP

#include <typesystems/writer.hpp>
#include "data_model.hpp"

namespace data_pattern {
namespace bits {

/* owrrite type */
template <
  typename Iter, typename Writer >
struct owrite_type;

/* owrite type << output_model */
template <
  typename Iter
, typename Writer
, typename Buffer
, typename MakeIter >
output_model<Buffer,MakeIter> &
operator << (
  output_model<Buffer,MakeIter> &
, owrite_type<Iter,Writer> &
);

/* iwrite type */
template <typename T, typename Writer>
struct iwrite_type;

/* iwrite type >> input */
template <
  typename Iter
, typename Writer
, typename Buffer
, typename MakeIter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> &
, iwrite_type<Buffer,Writer> &
);

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::owrite_type
rewrite_output (
  T const & // input buffer
, Writer
);

/* rewrite input */
template <typename T, typename Writer>
bits::iwrite_type <T, Writer>
rewrite_input (
  T &
, Writer
);

/* rewrite iterator */
template <
  typename... Ts
  typename Iterator
, typename T
  = typesystems::writer_function >
class rewrite_iterator  {

Iterator iterator;
typesystems::type_map<T,Ts...> map;

/* assignment operator */
template <typename U>
operator = (
  U const &
);

/* cast operator */
template <typename U>
operator U();

rewrite_iterator<Ts...,Iterator,T> &
operator * ();

rewrite_iterator<Ts...,Iterator,T> * 
operator -> ();
}; /* rewrite_iterator */

/* make rewrite iterator */
template <
  typename... Ts
, typename Iterator
, typename T >
rewrite_iterator<Ts..., Iterator, T>
make_rewrite_iterator (
  Iterator _iter
){
return
rewrite_iterator<Ts..., Iterator, T>
(iter);
}

} /* data_pattern */
#include "./bits/rewrite_type.tcc"
#endif

