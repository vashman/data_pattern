//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ODATA_MODEL_HPP
#define DATA_PATTERN_ODATA_MODEL_HPP

#include <map>
#include <typesystems/qualified_typeid.hpp>
#include <typesystems/writer.hpp>
#include "basic_data_model.hpp"

namespace data_pattern {
/* odata_model */
template <
  typename Container
, typename OutputerIter
, typename Writer = std::map <
    typesystems::qualified_typeinfo
  , typesystems::owriter_base_type >
>
class odata_model
: public virtual
  basic_data_model <Container>
{
public:

/* ctor */
virtual
~odata_model() = default;

/* ctor */
odata_model() = default;

/* ctor move */
odata_model (
  odata_model <
    Container,OutputIter,Writer > &&
) = default;

/* assignment operator move */
odata_model <
  Container,OutoutIter,Writer > &
operator = (
  odata_model <
    Container,OutputIter,Writer > &&
) = default;

/* ctor copy */
odata_model (
  odata_model <
    Container,OutputIter,Writer > const&
) = delete;

/* assignment operator copy */
odata_model <
  Container,OutputIter,Writer > &
operator = (
  odata_model <
    Container,OutputIter,Writer > const&
) = delete;

Writer writer;
};

/* rewrite output */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
void
rewrite (
  odata_model <
    Container, OutputIter, Writer > &
, T const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, bool const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, signed short const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > &
, unsigned short const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, signed int const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, unsigned int const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, signed long const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, unsigned long const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, float const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, double const &
);

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container, OutputIter, Writer > &
, long double const &
);

} /* data_pattern */
#include "bits/odata_model.tcc"
#endif
