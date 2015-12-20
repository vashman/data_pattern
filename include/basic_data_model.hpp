//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BASIC_DATA_MODEL_HPP
#define DATA_PATTERN_BASIC_DATA_MODEL_HPP

namespace data_pattern {
/* base data model */
template <typename Container>
class basic_data_model {
public:

/* ctor */
virtual
~basic_data_model() = default;

/* ctor */
basic_data_model() = default;

/* ctor move */
basic_data_model (
  basic_data_model <Container> &&
) = default;

/* assignment operator move */
basic_data_model <Container> &
operator = (
  basic_data_model <Container> &&
) = default;

/* ctor copy */
basic_data_model (
  basic_data_model <Container> const &
) = delete;

/* assignment operator copy */
basic_data_model <Container> &
operator = (
  basic_data_model <Container> const &
) = delete;

void
set_state(bool);

bool
get_state() const;

Container con;

private:

bool state;
};

} /* data_pattern */
#include "bits/basic_data_model.tcc"
#endif
