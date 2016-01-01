//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_IDATA_MODEL_HPP
#define DATA_PATTERN_IDATA_MODEL_HPP

#include <map>
#include <typesystems/qualified_typeid.hpp>
#include <typesystems/writer.hpp>
#include "basic_data_model.hpp"

namespace data_pattern {

/* input data model */
template <
  typename Buffer
, typename MakeOutputIter
, typename MakeInputIter
, typename Reader = std::map <
    typesystems::qualified_typeinfo
  , typesystems::writer_type <
      decltype(begin(Buffer))
    , OutputIter >
  >
, typename GetWriter >
class idata_model {
public:

/* ctor */
idata_model (
  data_model_buffer < Buffer
  , MakeInputIter, MakeOutputIter > *
, GetWriter _get_writer = [](...){}
);

/* dtor */
~idata_model() = default;

/* ctor move */
idata_model (
  idata_model <Container,Reader> &&
) = default;

/* assignment operator move */
idata_model <Container,Reader> &
operator = (
  idata_model <Container,Reader> &&
) = default;

/* ctor copy */
idata_model (
  idata_model <Container,Reader> const &
) = delete;

/* assignment operator copy */
idata_model <Container,Reader> &
operator = (
  idata_model <Container,Reader> const &
) = delete;

GetWriter get_writer;

private:

Reader reader;
bool state;
data_model_buffer < Buffer
  , MakeInputIter, MakeOutputIter >
* buffer;
}; /* idata_model */

/* rewrite input */
template <
  typename T
, typename Container
, typename Reader >
void
rewrite (
  idata_model <Container, Reader> &
, T &
);

/* empty 
  Check if buffer is empty.
*/
template <
  typename T
, typename Container
, typename Reader >
bool
empty (
  idata_model <Container,Reader> const &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> &
, bool &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> &
, signed short &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> &
, unsigned short &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> &
, signed int &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  data_model <Container, Reader> &
, unsigned int &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> &
, signed long &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> &
, unsigned long &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> &
, float &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> &
, double &
);

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> &
, long double &
);

} /* data_pattern */
#include "bits/idata_model.tcc"
#endif
