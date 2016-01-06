//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

namespace data_pattern {

/* input model */
template <
/* Buffer needs to support; begin, end
  , empty<T> and MakeInputIter.
*/
  typename Buffer, typename InputIter >
class input_model;

/* empty
  Check if buffer is empty.
*/
template <
  typename T
, typename Buffer
, typename InputIter >
bool
empty (
  input_model <Buffer, InputIter>
  const &
);

template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter>
make_imodel (
  Buffer
, InputIter
);

/* input value */
template <
  typename Buffer, typename InputIter>
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, bool &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, signed short &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, unsigned short &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, signed int &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, unsigned int &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, signed long &
);

/* input value */
template <
  typename Buffer, typename InputIter >
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, unsigned long &
);

/* input value */
template <
  typename Buffer, typename InputIter>
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, float &
);

/* input value */
template <
  typename Buffer, typename InputIter>
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, double &
);

/* input value */
template <
  typename Buffer, typename InputIter>
input_model <Buffer, InputIter> &
operator >> (
  input_model <Buffer, InputIter> &
, long double &
);

/* input model */
template <
/* Buffer needs to support; Begin, End
  , empty<T> and MakeInputIter.
*/
  typename Buffer
, typename InputIter >
struct input_model {
InputIter input_iterator;
Buffer buffer;

/* ctor */
input_model (
  Buffer
, InputIter
);

/* dtor */
virtual
~input_model() = default;

/* ctor move */
input_model (
  input_model <Buffer, InputIter> &&
) = default;

/* assignment operator move */
input_model <Buffer, InputIter> &
operator = (
  input_model <Buffer, InputIter> &&
) = default;

/* ctor copy */
input_model (
  input_model <Buffer, InputIter>
  const &
) = delete;

/* assignment operator copy */
input_model <Buffer, InputIter> &
operator = (
  input_model <Buffer, InputIter>
  const &
) = delete;

}; /* input model */

} /* data_pattern */
#include "bits/input_model.tcc"
#endif
