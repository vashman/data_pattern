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
#include "output_model.hpp"
#include "input_model.hpp"

namespace data_pattern {
namespace bits {

/* owrrite type */
template <
  typename Iter, typename Writer >
struct owrite_type;

/* owrite type << output_model */
template <
  typename T
, typename Writer
, typename Buffer
, typename MakeIter >
output_model<Buffer,MakeIter> &
operator << (
  output_model<Buffer,MakeIter> &
, owrite_type<T,Writer> const &
);

/* iwrite type */
template <typename T, typename Writer>
struct iwrite_type;

/* iwrite type >> input */
template <
  typename T
, typename Writer
, typename Buffer
, typename MakeIter >
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> &
, iwrite_type<T,Writer> &
);

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::owrite_type <T,Writer>
rewrite_output (
  T const & // input buffer
, Writer const
);

/* rewrite input */
template <typename T, typename Writer>
bits::iwrite_type <T, Writer>
rewrite_input (
  T &
, Writer const
);

} /* data_pattern */
#include "bits/irewrite_iterator.hpp"
#include "bits/orewrite_iterator.hpp"
//#include "bits/rewrite_iterator.hpp"
#include "bits/rewrite_type.tcc"
#endif

