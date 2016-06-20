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
class sqlite_statement
: public std::iterator <
  void, std::input_iterator_tag >{

std::shared_ptr<sqlite3_stmt> stmt;
std::shared_ptr<sqlite3> db;

/* When a statement runs, set this to
  max column.
*/
std::shared_ptr<int> max_col;

public:

/* Column counter used to keep track
  of which column in the current
  table is currently active.
*/
int index;

/* ctor */
explicit
sqlite_statement (
  char const * // query
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

/* operator = */
sqlite_statement &
operator = (
  sqlite_statement const &
) = default;

/* dtor */
~sqlite_statement() = default;

sqlite_statement &
operator ++ ();

sqlite_statement
operator ++ (int);

sqlite_statement &
operator * ();

sqlite_statement *
operator -> ();

operator int ();

operator double ();

explicit
operator std::string ();

operator raw ();

sqlite_statement &
operator = (
  int
);

sqlite_statement &
operator = (
  double
);

sqlite_statement &
operator = (
  std::string
);

sqlite_statement &
operator = (
  raw
);

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

bool
operator == (
  sqlite_statement const &
) const;

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
~sqlite () = default;

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

/* step */
void
step (
  sqlite_statement &&
);


private:

std::shared_ptr<sqlite3> db;
std::unique_ptr<char> zErrMsg;
std::unique_ptr<char> result;
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
#include "bits/sqlite.tcc"
#endif

