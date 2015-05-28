// data model base implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_MODEL_CPP
#define DATA_PATTERN_MODEL_CPP

#include "../include/data_model.hpp"

namespace data_pattern {

/* data_model ctor */
data_model::data_model(
)
: state (data_model::good) {
}

/* data_model dtor */
data_model::~data_model(
){
}

/**/
bool
data_model::is_good(
) const {
return
(this->state == data_model::good);
}

/**/
bool
data_model::is_bad(
) const {
return !(this->is_good());
}

/**/
data_model::state_type
data_model::rdstate(
) const {
return this->state;
}

/**/
data_model::state_type
data_model::rdstate(
  data_model::state_type _state
){
auto t = this->state;
this->state == _state;
return t;
}

} /* data_patten */
#endif
