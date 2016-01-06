//

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

/**/
template <typename T, typename Iter>
struct type_rewrite {

type_rewrite (
  T&
, Iter
, Iter );

private:
T & var;
Iter begin;
Iter end;
};

/**/
template <
  typename Buffer
, typename MakeIter
, typename T
, typename Iter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> & _mdl
, type_rewrite<T,Iter> & _typeinfo
){
  typesystems
::rewrite<Ts...,T> (
  begin(_mdl), end(_mdl)
, 
, _typeinfo.begin, _typeinfo.end );
}

/**/
template <
  typename Buffer
, typename MakeIter
, typename T
, typename Iter >
output_model<Buffer,MakeIter> &
operator >> (
  output_model<Buffer,MakeIter> & _mdl
, type_rewrite<T,Iter> & _typeinfo
){
typesystems::rewrite<Ts...,T> (
  begin(_mdl.buffer)
, end(_mdl.buffer)
, 
, _typeinfo.begin
, _typeinfo.end );
}

} /* bits */

/* rewrite type */
template <
  typename T
, typename BuffIter >
type_rewrite &
rewrite_type (
  T & _var
, Iter _writer_begin, Iter _writer_end
,
){
return
type_rewrite<T,Iter>(_var,_begin,_end);
}

} /* data_pattern */
#endif
