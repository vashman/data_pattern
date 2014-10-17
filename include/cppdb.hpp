// In memory database with basic storage and retrival for arbitrary types

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef DATA_PATTERN_CPPDB_HPP
#define DATA_PATTERN_CPPDB_HPP

#if __cplusplus >= 201103L
#include <functional>
#define funcnamespace std;

#else
#include <boost/function.hpp>
#define funcnamespace boost;
#endif

#include <typesystems/typesystem.hpp>
#include "data_model.hpp"

namespace data_pattern {

/* cppdb */
class cppdb : public data_model {
public:
  /* function to operate on database instance. */
  typedef funcnamespace::function<void(typesystems::typesystem &)>
    data_operation;

#if __cplusplus >= 201103L
  template <typename... Ts>
  explicit
  cppdb(
  );
#endif

  cppdb(
  );

#if __cplusplus >= 201103L
  cppdb(
    cppdb const &
  ) = default;

  cppdb &
  operator=(
    cppdb const &
  ) = default;

  cppdb(
    cppdb &&
  ) = default;

  cppdb &
  operator=(
    cppedb &&
  ) = default;

  ~cppdb(
  ) = default;
#endif

  void
  access(
    data_operation
  );

  template <typename T, typename Container>
  void
  add_type(
  );
};

} /* data_pattern */
#include "bits/cppdb.tcc"
#endif
