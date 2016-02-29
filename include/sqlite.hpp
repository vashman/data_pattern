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
#include <string>
#include "raw.hpp"
#include <memory>
#include <iterator>

namespace data_pattern {

class sqlite_statement;
class sqlite_exception;
class sqlite;

/* sqlite exception */
class sqlite_exception
: public std::runtime_error {
public:
  
explicit
sqlite_exception (
  const char *
, int
);

int const rv;
}; /* sqlite exception */

/* query_statement wraps an sqlite
  statement and does some book keeping.
*/
class sqlite_statement {
public:

/* ctor */
explicit
sqlite_statement (
  char const *
, sqlite &
);

/* ctor copy */
sqlite_statement (
  sqlite_statement const &
) = default;

/* ctor move */
sqlite_statement (
  sqlite_statement &&
) = default;

/**/
sqlite_statement &
operator = (
  sqlite_statement const &
) = default;

/* dtor */
~sqlite_statement() = default;

/* bind double */
void
bind (
  int
, double
);

/* bind int */
void
bind (
  int
, int
);

/* bind void * */
void
bind (
  int
, void const *
, int
);

/* bind null */
void
bind (
  int
);

/* bind char * */
void
bind (
  int
, char const *
);

/* column_int */
int
column_int (
  int
);

sqlite3_int64
column_int64 (
  int
);

/* column_double */
double
column_double (
 int
);

const void *
column_blob (
  int
);

int
column_bytes (
  int
);

int
column_bytes16 (
  int
);

const unsigned char *
column_text (
  int
);

const void *
column_text16 (
  int
);

int
column_type (
  int
);

sqlite3_value *
column_value (
  int
);

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

std::shared_ptr<sqlite3_stmt> stmt;

/* When a statement runs, set this to
  max column.
*/
int max_col;
friend class sqlite;
}; /* sqlite satemenmt */

/* sqlite */
class sqlite {
public:

/* ctor
  Takes the filepath "char const *" to
  database location.
*/
explicit
sqlite (
  char const *
);

/* dtor */
~sqlite ();

#if __cplusplus >= 201103L
/* copy ctor */
sqlite (
  sqlite const &
) = delete;

/* operator = */
sqlite &
operator = (
  sqlite const &
) = delete;

/* move ctor */
sqlite (
  sqlite &&
) = default;

/* move operator = */
sqlite &
operator = (
  sqlite &&
) = default;
#endif

/* create */
sqlite_statement
create (
  char const * _query
);

/* step */
void
step (
  sqlite_statement &
);

/* step
  Step through next statement in
  the buffer.
*/
void
step();

/* iterator */
class iterator
: std::iterator <
    sqlite::iterator
  , std::input_iterator_tag
  >
{
sqlite * db;

public:

/* ctor */
explicit
iterator (
  sqlite &
);

/* ctor copy */
iterator (
  iterator const &
) = default;

iterator &
operator = (
  iterator const &
) = default;

/* ctor move */
iterator (
  iterator &&
) = default;

iterator &
operator = (
  iterator &&
) = default;

/* dtor */
~iterator() = default;

/* step statement */
iterator &
operator = (
  sqlite_statement &
);

iterator &
operator ++ ();

iterator &
operator ++ (
  int
);

iterator &
operator * ();

iterator *
operator -> ();
} /* iterator */

private:

sqlite3 * db;
char * zErrMsg;
char * result;
friend sqlite_statement;
}; /* sqlite  */

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
#include "bits/sqlite_statement.tcc"
#include "bits/sqlite.tcc"
#endif
