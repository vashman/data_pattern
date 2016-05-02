//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_TYPE_TCC
#define TYPESYSTEMS_REWRITE_TYPE_TCC

#include "../variable_iterator.hpp"

namespace data_pattern {
namespace bits {

/* owrrite type */
template <typename T, typename Writer >
struct owrite_type {
T const & var;
Writer const writer;

explicit
owrite_type (
  T const & _var
, Writer const _writer
)
: var (_var)
, writer (_writer) {
}

}; /* owrite type */

/* owrite type << output_model */
template <
  typename T
, typename Writer
, typename Buffer
, typename MakeIter >
output_model<Buffer,MakeIter> &
operator << (
  output_model<Buffer,MakeIter> & _mdl
, owrite_type<T,Writer> const & _writer
){
_writer.writer (
  _writer.var
, _mdl.output_iterator(_mdl.buffer)
);
}

/* iwrite type */
template <typename T, typename Writer>
struct iwrite_type {

T & var;
Writer const writer;

explicit
iwrite_type (
  T & _var
, Writer const _writer
)
: var (_var)
, writer (_writer) {
}

}; /* iwrite type */

/* iwrite type >> input */
template <
  typename T
, typename Writer
, typename Buffer
, typename MakeIter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> & _mdl
, iwrite_type<T,Writer> & _writer
){
_writer.writer (
  _mdl.input_iterator(_mdl.buffer)
, _mdl.input_iterator(_mdl.buffer)
, _writer.var
);
}

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::owrite_type <T,Writer>
rewrite_output (
  T const & _var
, Writer const _writer
){
return bits::owrite_type <T, Writer>
(_var, _writer);
}

/* rewrite input */
template <typename T, typename Writer>
bits::iwrite_type <T, Writer>
rewrite_input (
  T & _var
, Writer const _writer
){
return bits::iwrite_type <T, Writer>
(_var, _writer);
}

} /* data_pattern */
#include "orewrite_iterator.tcc"
#include "irewrite_iterator.tcc"
//#include "rewrite_iterator.tcc"
#endif

