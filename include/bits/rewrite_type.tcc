//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_TYPE_TCC
#define TYPESYSTEMS_REWRITE_TYPE_TCC

#include "variable_iterator.hpp"

namespace data_pattern {
namespace bits {

/* owrrite type */
template <
  typename Iter, typename Writer >
struct owrite_type {
Iter buffer_begin, buffer_end;
Writer writer;

explicit
owrite_type (
  Iter _begin
, Iter _end
, Writer _writer
)
: buffer_begin (_begin)
, buffer_end (_end)
, writer (_writer) {
}

}; /* owrite type */

/* owrite type << output_model */
template <
  typename Iter
, typename Writer
, typename Buffer
, typename MakeIter >
output_model<Buffer,MakeIter> &
operator << (
  output_model<Buffer,MakeIter> & _mdl
, owrite_type<Iter,Writer> & _writer
){
_writer.writer (
  _writer.buffer_begin
, _writer.buffer_end
, _mdl.output_iterator(_mdl.buffer)
);
}

/* iwrite type */
template <typename T, typename Writer>
struct iwrite_type {

variable_iterator<T> iterator;
Writer writer;

explicit
iwrite_type (
  T & _var
, Writer _writer
)
: iterator (_var)
, writer (_writer) {
}

}; / iwrite type /

/* iwrite type >> input */
template <
  typename Iter
, typename Writer
, typename Buffer
, typename MakeIter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> & _mdl
, iwrite_type<Buffer,Writer> & _writer
){
_writer.writer (
  _mdl.input_iterator(_mdl.buffer)
, _mdl.input_iterator(_mdl.buffer)
, _writer.iterator
);
}

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::owrite_type
rewrite_output (
  T const & _var // input buffer
, Writer _writer
){
T * var_begin (& _var);
T * var_end (var);
return
bits::owrite_type <T*, Writer>
(_var_begin, ++_var_end, _writer);
}

/* rewrite input */
template <typename T, typename Writer>
bits::iwrite_type <T, Writer>
rewrite_input (
  T & _var // output variable
, Writer _writer
){
return bits::iwrite_type <T, Writer>
(_var, _writer);
}

/* rewriter iterator assignment operator
*/
template <
  typename... Ts
, typename Iterator
, typename T >
template <typename U>
void
operator = (
  U const & _val
){
auto & writer = get<U>(this->map);
writer(_val); 
}

/* rewriter iterator cast operator */
template <
  typename... Ts
, typename Iterator
, typename T >
template <typename U>
  rewrite_iterator<Ts...,Iterator,T>
::operator U (){
auto writer = get<U>(this->writer);
return writer(*iter);
}

} /* data_pattern */
#endif

