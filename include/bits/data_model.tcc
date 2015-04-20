// data model template implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_DATA_MODEL_TCC
#define DATA_PATTERN_DATA_MODEL_TCC

namespace data_pattern {
/* data_model left shift operation */
template <typename T>
data_model &
operator<<(
  data_model & _mdl
, T const & _var
){
  if (typesystems::has_put_rewriter<T>(_mdl.typesys)){
  _mdl.typesys.put_rewrite(_var);
  }
return _mdl;
}

/* data_model right shift operation */
template <typename T>
data_model &
operator>>(
  data_model & _mdl
, T & _var
){
  if (typesystems::has_get_rewriter<T>(_mdl.typesys)){
  _mdl.typesys.get_rewrite(_var);
  }
return _mdl;
}

template <typename T>
bool
empty(
  data_model const & _mdl
){
return typesystems::empty<T>(_mdl.typesys);
}

} /* data_pattern */
#endif
