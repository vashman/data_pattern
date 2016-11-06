// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_REWRITE_TYPE_HPP
#define DATA_PATTERN_REWRITE_TYPE_HPP

#include <typesystems/writer.hpp>
#include <typesystems/type_map.hpp>
#include "data_model.hpp"

namespace data_pattern {
namespace bits {

/* owrrite type */
template <typename Iterator, typename Writer>
struct output_rewrite_type;

/* owrite type << output_model */
template <
  typename T
, typename Writer
, typename Device
, typename Sync >
output_model <Device, Sync> &
operator << (
  output_model <Device, Sync> &
, output_rewrite_type <T, Writer> &&
);

/* iwrite type */
template <typename T, typename Writer>
struct input_rewrite_type;

/* iwrite type >> input */
template <
  typename T
, typename Writer
, typename Device
, typename Sync >
input_model <Device, Sync> &
operator >> (
  input_model <Device, Sync> &
, input_rewrite_type <T, Writer> &&
);

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::output_rewrite_type <T, Writer>
rewrite_output (
  T const & // input buffer
, Writer const
);

/* rewrite input */
template <typename T, typename Writer>
bits::input_rewrite_type <T, Writer>
rewrite_input (
  T &
, Writer const
);

} /* data_pattern */
#include "bits/rewrite_type.tcc"
#include "bits/rewrite_iterator.hpp"
#endif

