// data_model sqlite implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_CPP
#define DATA_PATTERN_SQLITE_CPP

#include <string>
#include "../include/sqlite.hpp"

namespace data_pattern {

/* sqlite_exception ctor  */
sqlite_exception::sqlite_exception (
  const char * what_arg
, int _rv
)
: std::runtime_error (what_arg)
, rv (_rv) {
}

namespace bits {
namespace sqlite {
/* check for sqlite error */
void
check_error (
  int _rv
){
switch (_rv){
  case SQLITE_DONE:
  case SQLITE_ROW:
  case SQLITE_OK: return;

  case SQLITE_ERROR:
    throw sqlite_exception (
      "Sqlite: SQL error or missing"
      " database."
    , _rv
    );
  case SQLITE_BUSY:
    throw sqlite_exception (
      "Sqlite: The database file is"
      " locked."
    , _rv
    );
  case SQLITE_AUTH:
    throw sqlite_exception (
      "Sqlite: Authorization denied."
    , _rv
    );
  case SQLITE_TOOBIG:
    throw sqlite_exception(
      "Sqlite: String or BLOB exceeds"
      " size limit."
    , _rv
    );
  case SQLITE_RANGE:
    throw sqlite_exception (
      "Sqlite: Nth parameter to"
      " sqlite3_bind out of range."
    , _rv
    );
  case SQLITE_CONSTRAINT:
    throw sqlite_exception (
      "Sqlite: Abort due to constraint"
      " violation."
    , _rv
    );
  case SQLITE_INTERNAL:
    throw sqlite_exception (
      "Sqlite: Internal logic error in"
      " SQLite."
    , _rv
    );
  case SQLITE_PERM:
    throw sqlite_exception (
      "Sqlite: Access permission"
      " denied."
    , _rv
    );
  case SQLITE_ABORT:
    throw sqlite_exception (
      "Sqlite: Callback routine "
      "requested an abort."
    , _rv
    );
  case SQLITE_LOCKED:
    throw sqlite_exception (
      "Sqlite: A table in the database"
      " is locked."
    , _rv
    );
  case SQLITE_NOMEM:
    throw sqlite_exception (
      "Sqlite: A malloc() failed."
    , _rv
    );
  case SQLITE_READONLY:
    throw sqlite_exception (
      "Sqlite: Attempt to write a "
      "readonly database."
    , _rv
    );
  case SQLITE_INTERRUPT:
    throw sqlite_exception (
      "Sqlite: Operation terminated by"
      " sqlite3_interrupt()."
    , _rv
    );
  case SQLITE_IOERR:
    throw sqlite_exception (
      "Sqlite: Some kind of disk I/O"
      " error occurred."
    , _rv
    );
  case SQLITE_CORRUPT:
    throw sqlite_exception (
      "Sqlite: The database disk image"
      " is malformed."
    , _rv
    );
  case SQLITE_NOTFOUND:
    throw sqlite_exception (
      "Sqlite: Unknown opcode in"
      " sqlite3_file_control()."
    , _rv
    );
  case SQLITE_FULL:
    throw sqlite_exception (
      "Sqlite: Insertion failed because"
      " database is full."
    , _rv
    );
  case SQLITE_CANTOPEN:
    throw sqlite_exception (
      "Sqlite: Unable to open the"
      " database file."
    , _rv
    );
  case SQLITE_PROTOCOL:
    throw sqlite_exception (
      "Sqlite: Database lock protocol"
      " error."
    , _rv
    );
  case SQLITE_EMPTY:
    throw sqlite_exception (
      "Sqlite: Database is empty."
    , _rv
    );
  case SQLITE_SCHEMA:
    throw sqlite_exception (
      "Sqlite: The database schema"
      " changed."
    , _rv
    );
  case SQLITE_MISMATCH:
    throw sqlite_exception (
      "Sqlite: Data type mismatch."
    , _rv
    );
  case SQLITE_MISUSE:
    throw sqlite_exception (
      "Sqlite: Library used"
      " incorrectly."
    , _rv
    );
  case SQLITE_NOLFS:
    throw sqlite_exception (
      "Sqlite: Uses OS features not"
      " supported on host."
    , _rv
    );
  case SQLITE_NOTADB:
    throw sqlite_exception (
      "Sqlite: File opened that is not"
      " a database file."
    , _rv
    );
  case SQLITE_FORMAT:
    throw sqlite_exception (
      "Sqlite: Auxiliary database"
      " format error."
    , _rv
    );
  default:
    throw sqlite_exception (
      "Sqlite error"
    , _rv
    );
}
}
} /* sqlite */ } /* bits */

/* sqlite step */
void
sqlite::step (
  sqlite_statement & _stmt
){
bits::sqlite::check_error (
  sqlite3_step(_stmt.stmt.get()) );
*_stmt.max_col = sqlite3_column_count (
  _stmt.stmt.get() );
_stmt.index = 0;
}

/* sqlite step */
void
sqlite::step (
  sqlite_statement && _stmt
){
bits::sqlite::check_error (
  sqlite3_step(_stmt.stmt.get()) );
*_stmt.max_col = sqlite3_column_count (
  _stmt.stmt.get() );
_stmt.index = 0;
}

/* sqlite create */
sqlite_statement
sqlite::create (
  char const * _query
){
return sqlite_statement(_query, *this);
}

} /* data_pattern */
#include "bits/sqlite_statement.cpp"
#endif

