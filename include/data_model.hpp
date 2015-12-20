// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_DATA_MODEL_HPP
#define DATA_PATTERN_DATA_MODEL_HPP

#include <map>
#include <typesystems/qualified_typeid.hpp>
#include <typesystems/writer.hpp>

#include "odata_model.hpp"
#include "idata_model.hpp"

namespace data_pattern {
/* data_model
  Base class for all databases,
  providing a way to register supported
  types. As well provide the client with
  a means to convert incompatible types
  if not supported.
*/
template <
  typename Container
, template <typename> class OutputIter
, typename Writer = std::map <
    typesystems::qualified_typeinfo
  , typesystems::owriter_base_type >
, typename Reader = std::map <
    typesystems::qualified_typeinfo
  , typesystems::iwriter_base_type >
>
class data_model
: public idata_model <Container,Reader>
, odata_model <
    Container,OutputIter,Writer >
{
public:

/* ctor */
virtual
~data_model() = default;

/* ctor */
data_model() = default;

/* ctor move */
data_model (
  data_model <
    Container,OutputIter,Writer,Reader >
  &&
) = default;

/* assignment operator move */
data_model <
  Container,OutoutIter,Writer,Reader > &
operator = (
  data_model <
    Container,OutputIter,Writer,Reader >
  &&
) = default;

/* ctor copy */
data_model (
  data_model <
    Container,OutputIter,Writer,Reader >
  const &
) = delete;

/* assignment operator copy */
data_model <
  Container,OutputIter,Writer,Reader > &
operator = (
  data_model <
    Container,OutputIter,Writer,Reader >
  const &
) = delete;

}; /* data_model */

} /* data_pattern */
#include "bits/raw_data_model_shifts.hpp"
#include "bits/string_data_model_shifts.hpp"
#endif
