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
template <
  typename... Ts
, typename T
, typename OutputIter
, typename WriterIter
, typename GetWriter >
struct itype_rewrite {

itype_rewrite (
  OutputIter
, WriterIter
, WriterIter
, GetWriter );

private:
GetWriter get_writer;
WriterIter begin;
WriterIter end;
OutputIter output;
};

/**/
template <
  typename... Ts
, typename T
, typename BufferIter
, typename WriterIter
, typename GetWriter >
struct otype_rewrite {

otype_rewrite (
  BufferIter
, BufferIter
, WriterIter
, WriterIter
, GetWriter );

private:
GetWriter get_writer;
WriterIter writer_begin;
WriterIter writer_end;
BufferIter buffer_begin;
BufferIter buffer_endl
};

/**/
template <
  typename... Ts
, typename T
, typename OutputIter
, typename WriterIter
, typename GetWriter
, typename Buffer
, typename MakeIter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> & _mdl
, itype_rewrite <
    Ts..., T, OutputIter, WriterIter
  , GetWriter > & _typeinfo
){
  typesystems
::rewrite<Ts...,T> (
  begin(_mdl.buffer), end(_mdl.buffer)
, 
, _typeinfo.begin, _typeinfo.end );
}

/**/
template <
  typename... Ts
, typename T
, typename BufferIter
, typename WriterIter
, typename GetWriter
, typename Buffer
, typename MakeIter >
output_model<Buffer,MakeIter> &
operator >> (
  output_model<Buffer,MakeIter> & _mdl
, otype_rewrite <
    Ts..., T, BufferIter, WriterIter
  , GetWriter > & _typeinfo
){
typesystems::rewrite<Ts...,T> (
  begin(_mdl.buffer)
, end(_mdl.buffer)
, 
, _typeinfo.begin
, _typeinfo.end );
}

} /* bits */

/* rewrite type on input */
template <
  typename... Ts
, typename T
, typename OutputIter
, typename WriterIter
, typename GetWriter >
itype_rewrite<Ts...,T> &
rewrite_type (
  OutputIter _output_iter
, WriterIter _writer_begin
, WriterIter _writer_end
, GetWriter _get_writer
){
return
itype_rewrite<Ts...,T> (
  _output_iter
, _writer_begin
, _writer_end
, _get_writer );
}

/* rewrite type on output */
template <
  typename... Ts
, typename T
, typename BufferIter
, typename WriterIter
, typename GetWriter >
otype_rewrite<Ts...,T> &
rewrite_type (
  BufferIter _buffer_begin
, BufferIter _buffer_end
, WriterIter _writer_begin
, WriterIter _writer_end
, GetWriter _get_writer
){
return
otype_rewrite<Ts...,T> (
  _buffer_begin
, _buffer_end
, _writer_begin
, _writer_end
, _get_writer );
}

} /* data_pattern */
#endif
