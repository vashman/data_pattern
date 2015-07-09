// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_DATA_MODEL_HPP
#define DATA_PATTERN_DATA_MODEL_HPP

#include <typesystems/typebuffer.hpp>
#include <typesystems/iwriter.hpp>
#include <typesystems/owriter.hpp>

namespace data_pattern {
/* data_model
  Base class for all databases,
  providing a way to register supported
  types. As well provide the client with
  a means to convert incompatible types
  if not supported.
*/
class data_model {
public:
  /* ctor */
  virtual
  ~data_model();

  template <typename Writer>
  bool
  set_iwriter();

  template <typename Writer>
  bool
  set_owriter();

protected:
#if __cplusplus >= 201103L
  /* ctor */
  data_model() = default;

  /* ctor copy */
  data_model(data_model &&) = default;

  /* assignment operator move */
  data_model &
  operator=(data_model &&) = default;

  data_model(
    data_model const &
  ) = delete;

  data_model &
  operator=(
    data_model const &
  ) = delete;
#endif

  /* typesys represents the types
    supported by the database.
  */
	typesystems::typebuffer_container
  buffer;

	typesystems::owriter_container
	owriter;

  typesystems::iwriter_container
  iwriter;

private:
  template <typename T> friend
  void
  rewrite(data_model &, T const &);

  template <typename T> friend
  void
  rewrite(data_model &, T &);

  template <typename T> friend bool
  empty(data_model const &);
};

template <typename T>
bool
empty(
  data_model const &
);

template <typename T>
void
rewrite(
  data_model &
, T const &
);

template <typename T>
void
rewrite(
  data_model &
, T &
);

data_model &
operator<<(
  data_model &
, int const &
);

data_model &
operator<<(
  data_model &
, double const &
);

data_model &
operator<<(
  data_model &
, float const &
);

data_model &
operator>>(
  data_model &
, int &
);

data_model &
operator>>(
  data_model &
, double &
);

data_model &
operator>>(
  data_model &
, float &
);

} /* data_pattern */
#include "bits/data_model.tcc"
#include "bits/raw_data_model_shifts.hpp"
#include "bits/string_data_model_shifts.hpp"
#endif
