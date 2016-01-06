//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_TCC
#define DATA_PATTERN_OUTPUT_MODEL_TCC

namespace data_pattern {

/* ctor */
template <
  typename Buffer, typename OutputIter >
  output_model<Buffer,OutputIter>
::output_model (
  Buffer _buffer
, OutputIter _output_iter
)
: output_iterator (_output_iter)
, buffer (_buffer) {
}

template <
  typename Buffer, typename OutputIter >
output_model<Buffer,OutputIter>
make_omodel (
  Buffer _buffer
, OutputIter _output_iter
){
return
output_model<Buffer,OutputIter>(
  _buffer
, _output_iter
);
}
  
/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer,OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, bool const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, signed short const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, unsigned short const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, signed int const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, unsigned int const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, signed long const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, unsigned long const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
 output_model <Buffer,OutputIter>
  & _mdl
, float const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, double const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Buffer
, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer,OutputIter>
  & _mdl
, long double const & _var
){
*_mdl.output_iterator(_mdl.buffer)++
  = _var;
return _mdl;
}

} /* data_pattern */
#endif
