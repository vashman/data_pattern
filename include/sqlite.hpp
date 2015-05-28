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
#include <vector>
#include "data_model.hpp"

namespace data_pattern {

class sqlite;

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

  /* bind void* */
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

  /* bind char* */
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

  /* column_double */
  double
  column_double(
   int
  );

  /* Coulunm counter used to keep track
    of which column in the current
    table is currently active.
  */
  int index;

  /* get_state */
  signed int
  get_state(
  ) const;

private:
  sqlite3_stmt * stmt;

  /* Sqlite error code.*/
  signed int state;

  /* When a statement runs, set this to
    max column.
  */
  int max_col;

  unsigned int * ref;

  friend sqlite;
};

/* sqlite */
class sqlite : public data_model {
public:
	/* ctor
    Takes char* to database location.
  */
  template <
      typename container
    = std::vector<sqlite_statement>
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
    Step through next statment in
    the buffer.
  */
  void
  step();

private:
	sqlite3 * db;
	char * zErrMsg;
	char * result;
  /* Sqlite error code. */
  signed int state;

  /* set_state */
  void
  set_state(
    int
  );

  friend sqlite_statement;
};

} /* data_pattern */
#include "bits/sqlite.tcc"
#include "bits/sqlite_rewriters.hpp"
#endif
