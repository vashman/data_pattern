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
#include <string>
#include <vector>
#include "data_model.hpp"

namespace data_pattern {

class sqlite;

/* query_statement wraps an sqlite statement and does some book keeping */
class sqlite_statement {
public:
  void
  bind(
    int
  , double
  );

  void
  bind(
    int
  , int
  );

  void
  bind(
    int
  , void const *
  , int
  );

  void
  bind(
    int
  );

  void
  bind(
    int
  , char const *
  );

  int
  column_int(
    int
  );

  double
  column_double(
   int
  );

  int index;

  signed int
  get_state(
  ) const;

private:
  sqlite3_stmt * stmt;

  signed int state;

  /* when statement runs, set this to max column */
  int max_col;

  friend sqlite;
};

/* sqlite */
class sqlite : public data_model {
public:
	/* Takes char* to database location. */
  template <typename container = std::vector<sqlite_statement> >
	sqlite(
    char const *
  );

	~sqlite(
  );

#if __cplusplus >= 201103L
  sqlite(
    sqlite const &
  ) = delete;

  sqlite &
  operator=(
    sqlite const &
  ) = delete;

  sqlite(
    sqlite &&
  );

  sqlite &
  operator=(
    sqlite &&
  );
#endif

  sqlite_statement
  create(
    char const *
  , int
  , char const **
  );

  void
  finalize(
    sqlite_statement const &
  );

  void
  step(
    sqlite_statement &
  );

private:
	sqlite3 * db;
	char * zErrMsg;
	char * result;
  signed int state;
};

} /* data_pattern */
#include "bits/sqlite.tcc"
#include "bits/sqlite_rewriters.hpp"
#endif
