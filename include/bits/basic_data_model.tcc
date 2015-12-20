//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BASIC_DATA_MODEL_TCC
#define DATA_PATTERN_BASIC_DATA_MODEL_TCC

namespace data_pattern {
template <typename Container>
void
basic_data_model<Container>::set_state(
  bool _state
){
this->state = _state;
}

template <typename Container>
bool
basic_data_model<Container>::get_state(
) const {
return this->state;
}

} /* data_pattern */
#endif
