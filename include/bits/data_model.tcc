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
//	if (!typesystems::has_put_rewriter<T>(_mdl.tysys)){
//	_mdl.setstate(typesystem::failbit);
//	return _mdl;
//	}
//  if (!_mdl.tysys.put_rewrite(_var)){
  // setstate
//  };
return _mdl;
}

/* data_model right shift operation */
template <typename T>
data_model &
operator>>(
  data_model & _mdl
, T & _var
){
//	if (! typesystems::has_get_rewriter<T>(_mdl.tysys)){
//	_mdl.setstate(typesystems::failbit);
//	return _mdl;
//	}
//  if (!_mdl.tysys.get_rewrite(_var)){
  // setstate
//  }
return _mdl;
}

} /* data_pattern */
#endif
