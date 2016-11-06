//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_ITERATOR_TCC
#define TYPESYSTEMS_REWRITE_ITERATOR_TCC

namespace data_pattern {

/* ctor */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
  input_rewrite_iterator <T, Writer, Check, Model>
::input_rewrite_iterator (
  Writer & _writer
, Check & _check
, Model & _model
)
: bits::rewrite_iterator <T, Writer, Check, Model>
  (_writer, _check, _model)
{
this->temp = this->writer (this->model->iterator_map());
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
T &
  input_rewrite_iterator <T, Writer, Check, Model>
::operator * (
){
return this->temp;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
T *
  input_rewrite_iterator <T, Writer, Check, Model>
::operator -> (
){
return &this->temp;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
input_rewrite_iterator <T, Writer, Check, Model> &
  input_rewrite_iterator <T, Writer, Check, Model>
::operator ++ (
){
this->temp = this->writer (this->map);s
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
input_rewrite_iterator <T, Writer, Check, Model> &
  input_rewrite_iterator <T, Writer, Check, Model>
::operator ++ (
  int
){
auto temp_iter = *this;
this->temp = this->writer (this->map);
return temp_iter;
}

/* ctor */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
  output_rewrite_iterator <T, Writer, Check, Model>
::output_rewrite_iterator (
  Writer & _writer
, Check & _check
, Model & _sync_map
)
: bits::rewrite_iterator <T, Writer, Check, Model>
  (_writer, _check, _sync_map)
{}

/* rewriter iterator assignment operator. */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model> &
  output_rewrite_iterator <T, Writer, Check, Model>
::operator = (
  T const & _val
){
this->writer (_val, this->map);
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model> &
  output_rewrite_iterator <T, Writer, Check, Model>
::operator ++ (
){
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model> &
  output_rewrite_iterator <T, Writer, Check, Model>
::operator ++ (
  int
){
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model> &
  output_rewrite_iterator <T, Writer, Check, Model>
::operator * (
){
return *this;
}

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
input_rewrite_iterator <T, Writer, Check, Model>
make_input_rewrite_iterator (
  Writer & _writer
, Check & _check
, Model & _map
){
return input_rewrite_iterator <T, Writer, Check, Model>
(_writer, _check, _map);
}

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model>
make_output_rewrite_iterator (
  Writer & _writer
, Check & _check
, Model & _map
){
return output_rewrite_iterator <T, Writer, Check, Model>
(_writer, _check, _map);
}

namespace bits {

/* ctor */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
  rewrite_iterator <T, Writer, Check, Model>
::rewrite_iterator (
  Writer & _writer
, Check & _check
, Model & _sync_map
)
: temp()
, writer (& _writer)
, check (& _check)
, sync_map (& _sync_map)
{}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
bool
  rewrite_iterator <T, Writer, Check, Model>
::operator == (
  rewrite_iterator <T, Writer, Check, Model> const & _rhs
) const {
  if (
     (this->sync_map != _rhs.sync_map)
  || (this->check != _rhs.check)){
  return false;
return *this->check (*this->sync_map);
}
}

template <
  typename T
, typename Writer
, typename Check
, typename Model >
bool
  rewrite_iterator <T, Writer, Check, Model>
::operator != (
  rewrite_iterator <T, Writer, Check, Model> const & _rhs
) const {
return !(*this==_rhs);
}

} /* bits */ } /* data_pattern */
#endif

