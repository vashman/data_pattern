// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_IO_MODEL_HPP
#define DATA_PATTERN_IO_MODEL_HPP

#include "output_model.hpp"
#include "input_model.hpp"

namespace data_pattern {

/* io_model */
template <
  typename Buffer
, typename InputIter
, typename OutputIter >
struct io_model
: public
  input_model <Buffer,InputIter>
, output_model <Buffer,OutputIter>
{

/* dtor */
~io_model() throw() = default;

/* ctor */
io_model (
  Buffer
, InputIter
, OutputIter
);

/* ctor move */
io_model (
  io_model <
    Buffer, InputIter, OutputIter > &&
) = default;

/* assignment operator move */
io_model <
  Buffer, InputIter, OutputIter > &
operator = (
  io_model <
    Buffer, InputIter, OutputIter > &&
) = default;

/* ctor copy */
io_model (
  io_model <
    Buffer, InputIter, OutputIter >
  const &
) = delete;

/* assignment operator copy */
io_model <
  Buffer, InputIter, OutputIter > &
operator = (
  io_model <
    Buffer, InputIter, OutputIter >
  const &
) = delete;

}; /* io_model */

template <
  typename Buffer
, typename InputIter
, typename OutputIter >
io_model <Buffer,InputIter,OutputIter>
make_iomodel (
  Buffer
, InputIter
, OutputIter
);

/* ctor */
template <
  typename Buffer
, typename InputIter
, typename OutputIter >
  io_model <Buffer,InputIter,OutputIter>
::io_model(
  Buffer _buffer
, InputIter _input_iter
, OutputIter _output_iter
)
: input_model <Buffer, InputIter> (
    _buffer, _input_iter )
, output_model <Buffer, OutputIter> (
    _buffer, _output_iter )
{
}

template <
  typename Buffer
, typename InputIter
, typename OutputIter >
io_model <Buffer,InputIter,OutputIter>
make_iomodel (
  Buffer _buffer
, InputIter _in_iter
, OutputIter _out_iter
){
return
io_model <Buffer,InputIter,OutputIter>
(_buffer, _in_iter, _out_iter);
}

} /* data_pattern */
#endif
