//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_TCC
#define DATA_PATTERN_INPUT_MODEL_TCC

namespace data_pattern {

/* ctor */
template <
  typename Buffer, typename InputIter >
  input_model <Buffer, InputIter>
::input_model (
  Buffer _buffer
, InputIter _input_iter
)
: input_iterator (_input_iter)
, buffer (_buffer) {
}

/* make input model */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter>
make_imodel (
  Buffer _buffer
, InputIter _input_iter
){
return
input_model<Buffer,InputIter> (
  _buffer
, _input_iter );
}

/* empty 
  Check if buffer is empty.
*/
template <
  typename T
, typename Buffer
, typename InputIter >
bool
empty (
  input_model <Buffer, InputIter>
  const & _mdl
){
return empty<T>(_mdl.buffer);
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model <Buffer,InputIter> & _mdl
, bool & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model <Buffer,InputIter> & _mdl
, signed short & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, unsigned short & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, signed int & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, unsigned int & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, signed long & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, unsigned long & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, float & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter> & _mdl
, double & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

/* input value */
template <
  typename Buffer, typename InputIter >
input_model<Buffer,InputIter> &
operator >> (
  input_model<Buffer,InputIter>
  & _mdl
, long double & _var
){
_var
  = *_mdl.input_iterator(_mdl.buffer)++;
return _mdl;
}

} /* data_pattern */
#endif
