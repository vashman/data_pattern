// Basic data model contains container
// and supported types.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_DATA_BUFFER_HPP
#define DATA_PATTERN_DATA_BUFFER_HPP

namespace data_pattern {

/* data model buffer */
template <typename Buffer>
struct data_buffer {
Buffer buffer;

/* dtor */
virtual
~data_buffer() = default;

/* ctor */
explicit
data_buffer () = default;

/* assignment operator move */
data_buffer <Buffer> &
operator = (
  data_buffer <Buffer> &&
) = default;

/* ctor copy */
data_buffer (
  data_buffer <Buffer> const &
) = delete;

/* ctor move */
data_buffer (
  data_buffer <Buffer> &&
) = default;

/* assignment operator copy */
data_buffer <Buffer> const &
operator = (
  data_buffer <Buffer> const &
) = delete;

}; /* data_model_buffer */

} /* data_pattern */
#include "bits/basic_data_model.tcc"
#endif
