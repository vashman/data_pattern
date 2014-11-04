// data model base to provide interface for io, and hold the typesystem.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_MODEL_HPP
#define DATA_PATTERN_MODEL_HPP

#include <typesystems/typesystem.hpp>

namespace data_pattern {
/* data_model

Base class for all databases, providing a way to register supported types.
As well provide the client with a means to convert incompatable types if
not supported.
*/
class data_model {
public:
#if __cplusplus >= 201103L
  data_model() = default;

  data_model(data_model &&) = default;

  data_model &
  operator=(data_model &&) = default;

  data_model(data_model const &) = delete;

  data_model &
  operator=(data_model const &) = delete;
#endif

  virtual
  ~data_model();

protected:
  /* typesys represents the types supported by the database. */
	typesystems::typesystem typesys;

private:
  template <typename T> friend data_model &
  operator<<(data_model &, T const &);

  template <typename T> friend data_model &
  operator>>(data_model &, T &);
};

template <typename T>
bool
empty(
  data_model const &
);

template <typename T>
data_model &
operator<<(
  data_model &
, T const &
);

template <typename T>
data_model &
operator>>(
  data_model &
, T &
);

} /* data_pattern */
#include "bits/data_model.tcc"
#endif
