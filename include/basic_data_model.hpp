// Basic data model contains container
// and supported types.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BASIC_DATA_MODEL_HPP
#define DATA_PATTERN_BASIC_DATA_MODEL_HPP

namespace data_pattern {
/* data model buffer */
template <
  typename Buffer
, typename MakeInputIter
, typename MakeOutputIter >
struct data_model_buffer {
Buffer buffer;
MakeInputIter make_input_iter;
MakeOutputIter make_output_iter;

/* dtor */
virtual
~data_model_buffer() = default;

/* ctor */
explicit
data_model_buffer (
  MakeInputIter
, MakeOutputIter
);

/* assignment operator move */
data_model_buffer <
  Buffer, MakeInputIter, MakeOutputIter
> &
operator = (
  data_model_buffer <
    Buffer, MakeInputIter
  , MakeOutputIter > &&
) = default;

/* ctor copy */
data_model_buffer (
  data_model_buffer <
    Buffer, MakeInputIter
  , MakeOutputIter > const &
) = delete;

/* ctor move */
data_model_buffer (
  data_model_buffer <
    Buffer, MakeInputIter
  , MakeOutputIter > &&
) = default;

/* assignment operator copy */
data_model_buffer <
  Buffer, MakeInputIter, MakeOutputIter
> const &
operator = (
  data_model_buffer <
    Buffer, MakeInputIter
  , MakeOutputIter > const &
) = delete;

}; /* data_model_buffer */

} /* data_pattern */
#include "bits/basic_data_model.tcc"
#endif
