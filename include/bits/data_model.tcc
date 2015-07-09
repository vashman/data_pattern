// data model template implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_DATA_MODEL_TCC
#define DATA_PATTERN_DATA_MODEL_TCC

#include <stdexcept>

namespace data_pattern {
template <typename T>
void
rewrite(
  data_model & _mdl
, T const & _var
){
typesystems::rewrite(
  _var
, _mdl.buffer
, _mdl.owriter
);
}

template <typename T>
void
rewrite(
  data_model & _mdl
, T & _var
){
typesystems::rewrite(
  _var
, _mdl.buffer
, _mdl.iwriter
);
}

template <typename T>
bool
empty(
  data_model const & _mdl
){
return
  typesystems
::empty<T>(_mdl.buffer, _mdl.iwriter);
}

template <typename Writer>
bool
data_model::set_iwriter(
){
  if (typesystems::has_typebuffer<
      typename Writer::value_type
     >(this->buffer)
  ){
  return false;
  }
typesystems::add_writer<Writer>
(this->iwriter);
return true;
}

template <typename Writer>
bool
data_model::set_owriter(
){
  if (typesystems::has_typebuffer<
      typename Writer::value_type
     >(this->buffer)
  ){
  return false;
  }
typesystems::add_writer<Writer>
(this->owriter);
return true;
}

} /* data_pattern */
#endif
