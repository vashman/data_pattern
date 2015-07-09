// wrapper around sqlite3

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_HPP
#define DATA_PATTERN_SQLITE_HPP

extern "C"{
#include <sqlite3.h>
}
#include <stdexcept>
#include <typesystems/typebuffer_queue.hpp>
#include "data_model.hpp"
#include <string>
#include "raw.hpp"

namespace data_pattern {

class sqlite_statement;
class sqlite;
class sqlite_exception;

/* sqlite exception */
class sqlite_exception
: public std::runtime_error {
public:
  explicit
  sqlite_exception(
    const char *
  , int
  );

  int const rv;
};

/* query_statement wraps an sqlite
  statement and does some book keeping.
*/
class sqlite_statement {
public:
  /* ctor */
  sqlite_statement (
    char const *
  , sqlite &
  );

  /* ctor copy */
  sqlite_statement (
    sqlite_statement const &
  );

  /* ctor move */
  sqlite_statement (
    sqlite_statement &&
  );

  /**/
  sqlite_statement &
  operator=(
    sqlite_statement const &
  );

  /* dtor */
  ~sqlite_statement(
  );

  /* bind double */
  void
  bind(
    int
  , double
  );

  /* bind int */
  void
  bind(
    int
  , int
  );

  /* bind void * */
  void
  bind(
    int
  , void const *
  , int
  );

  /* bind null */
  void
  bind(
    int
  );

  /* bind char * */
  void
  bind(
    int
  , char const *
  );

  /* column_int */
  int
  column_int(
    int
  );

  sqlite3_int64
  column_int64(
    int
  );

  /* column_double */
  double
  column_double(
   int
  );

  const void *
  column_blob(
    int
  );

  int
  column_bytes(int);

  int
  column_bytes16(int);

  const unsigned char *
  column_text(int);

  const void *
  column_text16(int);

  int
  column_type(int);

  sqlite3_value *
  column_value(int);

  operator int();
  operator double();
  operator std::string();
  operator raw();

  /* Column counter used to keep track
    of which column in the current
    table is currently active.
  */
  int index;

private:
  sqlite3_stmt * stmt;
  int * ref_count;

  /* When a statement runs, set this to
    max column.
  */
  int max_col;

  friend sqlite;
};

/* sqlite */
class sqlite : public data_model {
public:
	/* ctor
    Takes char* to database location.
  */
  template <
    typename Container = typesystems
    ::typebuffer_queue<sqlite_statement>
  >
	sqlite(
    char const *
  );

  /* dtor */
	~sqlite(
  );

#if __cplusplus >= 201103L
  /* copy ctor */
  sqlite(
    sqlite const &
  ) = delete;

  /* operator = */
  sqlite &
  operator=(
    sqlite const &
  ) = delete;

  /* move ctor */
  sqlite(
    sqlite &&
  ) = default;

  /* move operator = */
  sqlite &
  operator=(
    sqlite &&
  ) = default;
#endif

  /* create */
  sqlite_statement
  create(
    char const * _query
  );

  /* step */
  void
  step(
    sqlite_statement &
  );

  /* step
    Step through next statement in
    the buffer.
  */
  void
  step();

private:
  sqlite3 * db;
  char * zErrMsg;
  char * result;
  friend sqlite_statement;
};

data_model &
operator<<(
  data_model &
, sqlite_statement const &
);

namespace bits {
namespace sqlite {
/* check_error
  Throws an exception for an sqlite
  error code.
*/
void
check_error(
  int
);
} /* sqlite */ } /* bits */

} /* data_pattern */
#include "bits/sqlite.tcc"
#endif
