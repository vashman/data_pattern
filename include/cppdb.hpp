//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_CPPDB_HPP
#define DATA_PATTERN_CPPDB_HPP

#if __cplusplus >= 201103L
#include <functional>
#define ::funcnamespace std;

#else
#include <boost/function.hpp>
#define ::funcnamespace boost;
#endif

#include "data_model.hpp"

namespace data_pattern {

/* cppdb */
template <typename... Ts>
class cppdb : public data_model {
public:
  /* function to operate on database instance. */
  typedef funcnamespace::function<void(data_model &)> data_operation;

  explicit
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
};

} /* data_pattern */
#endif
