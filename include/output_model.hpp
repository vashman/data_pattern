//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_HPP
#define DATA_PATTERN_OUTPUT_MODEL_HPP

namespace data_pattern {

/* output model */
template <
  typename Buffer, typename OutputIter >
class output_model;

template <
  typename Buffer, typename OutputIter >
output_model<Buffer,OutputIter>
make_omodel (
  Buffer
, OutputIter
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer,OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, bool const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer,OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, signed short const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer,OutputIter> &
operator << (
  output_model <Buffer,OutputIter> &
, unsigned short const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, signed int const &
);

/* output value */
template <
  typename Buffer
, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, unsigned int const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, signed long const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, unsigned long const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, float const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, double const &
);

/* output value */
template <
  typename Buffer, typename OutputIter >
output_model <Buffer, OutputIter> &
operator << (
  output_model <Buffer, OutputIter> &
, long double const &
);

/* output model */
template <
  typename Buffer, typename OutputIter >
struct output_model {
OutputIter output_iterator;
Buffer buffer;

/* ctor */
virtual
~output_model() = default;

/* ctor */
explicit
output_model(
  Buffer
, OutputIter
);

/* ctor move */
output_model (
  output_model <Buffer,OutputIter> &&
) = default;

/* assignment operator move */
output_model <Buffer,OutputIter> &
operator = (
  output_model <Buffer,OutputIter> &&
) = default;

/* ctor copy */
output_model (
  output_model <Buffer,OutputIter>
  const &
) = delete;

/* assignment operator copy */
output_model <Buffer,OutputIter> &
operator = (
  output_model <Buffer,OutputIter>
  const &
) = delete;

}; /* odata_model */

} /* data_pattern */
#include "bits/output_model.tcc"
#endif
