// data model base implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_MODEL_CPP
#define DATA_PATTERN_MODEL_CPP

#include "../include/data_model.hpp"

namespace data_pattern {

/**/
data_model::~data_model(
){
}

/* data_model operations */
template <typename T>
data_model &
operator<<(
  data_model & _mdl
, T const & _var
){
	if (!typesystem::has_put_rewriter<T>(_mdl.tysys)){
//	_mdl.setstate(typesystem::failbit);
	return _mdl;
	}
  if (!_mdl.tysys.put_rewrite(_var)){
  // setstate
  };
return _mdl;
}

/**/
template <typename T>
data_model &
operator>>(
  data_model & _mdl
, T & _var
){
	if (! typesystem::has_get_rewriter<T>(_mdl.tysys)){
	_mdl.setstate(typesystem::failbit);
	return _mdl;
	}
  if (!_mdl.tysys.get_rewrite(_var)){
  // setstate
  }
return _mdl;
}

} /* data_patten */
#endif
