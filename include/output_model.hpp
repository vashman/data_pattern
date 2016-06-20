//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_HPP
#define DATA_PATTERN_OUTPUT_MODEL_HPP

#include "model.hpp"

namespace data_pattern {

/* output model */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
class output_model;

template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync >
make_output_model (
  Device
, MakeOutputIterator
, Sync
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, bool const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, signed short const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync> &
, unsigned short const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, signed int const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, unsigned int const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, signed long const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, unsigned long const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, float const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, double const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, long double const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, unsigned char const &
);

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync > &
, signed char const &
);

/* output model */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
struct output_model
: public virtual
  model <Device,Sync>
{
MakeOutputIterator output_iterator;

/* dtor */
virtual
~output_model() noexcept = default;

/* ctor */
output_model (
  Device
, MakeOutputIterator
, Sync
);

/* ctor move */
output_model (
  output_model <
    Device,MakeOutputIterator,Sync > &&
) = default;

/* assignment operator move */
output_model <
  Device,MakeOutputIterator,Sync > &
operator = (
  output_model <
    Device,MakeOutputIterator,Sync > &&
) = default;

/* ctor copy */
output_model (
  output_model <
    Device,MakeOutputIterator,Sync >
  const &
) = delete;

/* assignment operator copy */
output_model <
  Device,MakeOutputIterator,Sync > &
operator = (
  output_model <
    Device,MakeOutputIterator,Sync >
  const &
) = delete;

}; /* odata_model */

} /* data_pattern */
#include "bits/output_model.tcc"
#endif

