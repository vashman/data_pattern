// data model base implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_MODEL_CPP
#define DATA_PATTERN_MODEL_CPP

#include "../include/data_model.hpp"

namespace data_pattern {

/* data_model dtor */
data_model::~data_model(
){
}

data_model &
operator<<(
  data_model & _mdl
, int const & _var
){
rewrite(_mdl, _var);
return _mdl;
}

data_model &
operator<<(
  data_model & _mdl
, double const & _var
){
rewrite(_mdl, _var);
return _mdl;
}

data_model &
operator<<(
  data_model & _mdl
, float const & _var
){
rewrite(_mdl, _var);
return _mdl;
}

data_model &
operator>>(
  data_model & _mdl
, int & _var
){
rewrite(_mdl, _var);
return _mdl;
}

data_model &
operator>>(
  data_model & _mdl
, double & _var
){
rewrite(_mdl, _var);
return _mdl;
}

data_model &
operator>>(
  data_model & _mdl
, float & _var
){
rewrite(_mdl, _var);
return _mdl;
}

} /* data_patten */
#endif
