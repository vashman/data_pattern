// data_model sqlite implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_CPP
#define DATA_PATTERN_SQLITE_CPP

#include <string>
#include <iostream>
#include "../include/sqlite.hpp"

namespace data_pattern {
/* sqlite_exception ctor  */
sqlite_exception::sqlite_exception(
  const char * what_arg
, int _rv
)
: std::runtime_error (what_arg)
, rv (_rv) {
}

/* sqlite dtor */
sqlite::~sqlite(
){
sqlite3_close(this->db);
delete zErrMsg;
delete result;
}

namespace bits {
namespace sqlite {
/**/
void
check_error(
  int _rv
){
switch (_rv){
  case SQLITE_DONE:
  case SQLITE_ROW:
  case SQLITE_OK: return;
  case SQLITE_ERROR:
    throw sqlite_exception(
      "Sqlite: SQL error or missing database."
    , _rv
    );
  case SQLITE_BUSY:
    throw sqlite_exception(
      "Sqlite: The database file is locked."
    , _rv
    );
  case SQLITE_AUTH:
    throw sqlite_exception(
      "Sqlite: Authorization denied."
    , _rv
    );
  case SQLITE_TOOBIG:
    throw sqlite_exception(
      "Sqlite: String or BLOB exceeds size limit."
    , _rv
    );
  case SQLITE_RANGE:
    throw sqlite_exception(
      "Sqlite: 2nd parameter to sqlite3_bind out of range."
    , _rv
    );
  case SQLITE_CONSTRAINT:
    throw sqlite_exception(
      "Sqlite: Abort due to constraint violation."
    , _rv
    );
  case SQLITE_INTERNAL:
    throw sqlite_exception(
      "Sqlite: Internal logic error in SQLite."
    , _rv
    );
  case SQLITE_PERM:
    throw sqlite_exception(
      "Sqlite: Access permission denied."
    , _rv
    );
  case SQLITE_ABORT:
          throw sqlite_exception(
      "Sqlite: Callback routine requested an abort."
    , _rv
    );
  case SQLITE_LOCKED:
          throw sqlite_exception(
      "Sqlite: A table in the database is locked."
    , _rv
    );
  case SQLITE_NOMEM:
          throw sqlite_exception(
      "Sqlite: A malloc() failed."
    , _rv
    );
  case SQLITE_READONLY:
            throw sqlite_exception(
      "Sqlite: Attempt to write a readonly database."
    , _rv
    );
  case SQLITE_INTERRUPT:
            throw sqlite_exception(
      "Sqlite: Operation terminated by sqlite3_interrupt()."
    , _rv
    );
  case SQLITE_IOERR:
          throw sqlite_exception(
      "Sqlite: Some kind of disk I/O error occurred."
    , _rv
    );
  case SQLITE_CORRUPT:
    throw sqlite_exception(
      "Sqlite: The database disk image is malformed."
    , _rv
    );
  case SQLITE_NOTFOUND:
    throw sqlite_exception(
      "Sqlite: Unknown opcode in sqlite3_file_control()."
    , _rv
    );
  case SQLITE_FULL:
    throw sqlite_exception(
      "Sqlite: Insertion failed because database is full."
    , _rv
    );
  case SQLITE_CANTOPEN:
    throw sqlite_exception(
      "Sqlite: Unable to open the database file."
    , _rv
    );
  case SQLITE_PROTOCOL:
    throw sqlite_exception(
      "Sqlite: Database lock protocol error."
    , _rv
    );
  case SQLITE_EMPTY:
    throw sqlite_exception(
      "Sqlite: Database is empty."
    , _rv
    );
  case SQLITE_SCHEMA:
    throw sqlite_exception(
      "Sqlite: The database schema changed."
    , _rv
    );
  case SQLITE_MISMATCH:
    throw sqlite_exception(
      "Sqlite: Data type mismatch."
    , _rv
    );
  case SQLITE_MISUSE:
    throw sqlite_exception(
      "Sqlite: Library used incorrectly."
    , _rv
    );
  case SQLITE_NOLFS:
    throw sqlite_exception(
      "Sqlite: Uses OS features not supported on host."
    , _rv
    );
  case SQLITE_NOTADB:
    throw sqlite_exception(
      "Sqlite: File opened that is not a database file."
    , _rv
    );
  case SQLITE_FORMAT:
    throw sqlite_exception(
      "Sqlite: Auxiliary database format error."
    , _rv
    );
  default:
    throw sqlite_exception(
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
bits::sqlite::check_error(
  sqlite3_step(_stmt.stmt)
);
_stmt.max_col
  = sqlite3_column_count(_stmt.stmt);
_stmt.index = 0;
}

/* step */
void
sqlite::step(){
auto &
buff = typesystems::use_typebuffer<
  sqlite_statement
>(this->typesys);

auto stmt (buff.next());
this->step(stmt);
}

/* sqlite create */
sqlite_statement
sqlite::create (
  char const * _query
){
return sqlite_statement(_query, *this);
}

/* sqlite_statement */
/* ctor */
sqlite_statement::sqlite_statement(
  char const * _query
, sqlite & _db
)
/* index starts at 1 and then >1 */
: index (1) 
, stmt ()
, ref_count (new int(1))
, max_col (0) {
bits::sqlite::check_error(
  sqlite3_prepare_v2(
    _db.db
  , _query
  /* Query should be null terminated. */
  , -1 
  , & this->stmt
  /* There is never an unused portion of
    the statement.
  */
  , 0
  )
);
}

/* ctor move */
sqlite_statement::sqlite_statement(
  sqlite_statement && _other
)
: index (_other.index)
, stmt (_other.stmt)
, ref_count (_other.ref_count)
, max_col (_other.max_col) {
std::clog << "Moved sql stmt from: "
<< _other.stmt << " to: " << stmt
<< std::endl;
}

/* ctor copy */
sqlite_statement::sqlite_statement(
  sqlite_statement const & _other
)
: index (_other.index)
, stmt (_other.stmt)
, ref_count (_other.ref_count)
, max_col (_other.max_col) {
++(*ref_count);
std::clog << "Copied sql stmt from: "
<< _other.stmt << " to: " << stmt
<< std::endl;
}

/* copy assingment operator */
sqlite_statement &
sqlite_statement::operator=(
  sqlite_statement const & _rhs
){
  if (this != &_rhs){
  this->index = _rhs.index;
  this->stmt = _rhs.stmt;
  this->ref_count = _rhs.ref_count;
  this->max_col = _rhs.max_col;
  ++(*ref_count);
  }
std::clog << "Assigned sql stmt from: "
<< _rhs.stmt << " to: " << stmt
<< std::endl;
return *this;
}

/* dtor */
sqlite_statement::~sqlite_statement(
){
  if ((--ref_count) == 0){
  //finilize
  }
}

/* sqlite_statement bind_int */
void
sqlite_statement::bind(
  int _index
, int _var
){
bits::sqlite::check_error(
  sqlite3_bind_int(
    this->stmt
  , _index
  , _var
  )
);
}

/* */
void
sqlite_dtor_data(
  void *
);

void
sqlite_dtor_data(
  void * _data
){
// do nothing
}

/* sqlite_statement bind_blob */
void
sqlite_statement::bind (
  int _index
, void const * _blob
, int _size
){
bits::sqlite::check_error(
  sqlite3_bind_blob(
    this->stmt
  , _index
  , _blob
  , _size
  , sqlite_dtor_data
  )
);
}

/* sqlite_statement bind string */
void
sqlite_statement::bind (
  int _index
, char const * _str
){
bits::sqlite::check_error(
  sqlite3_bind_text(
    this->stmt
  , _index
  , _str
  , static_cast<int>(
        std
      ::char_traits<char>::length(_str)
    )
  , sqlite_dtor_data
  )
);
}

/* sqlite_statement bind double */
void
sqlite_statement::bind (
  int _index
, double _var
){
bits::sqlite::check_error(
  sqlite3_bind_double(
    this->stmt
  , _index
  , _var
  )
);
}

/* sqlite bind null */
void
sqlite_statement::bind (
  int _index
){
bits::sqlite::check_error(
  sqlite3_bind_null(
    this->stmt
  , _index
  )
);
}

/* sqlite_statement column_int */
int
sqlite_statement::column_int (
  int _index
){
  if (_index > this->max_col){
  throw ;
  }
return sqlite3_column_int(
  this->stmt
, _index
);
}

/* sqlite_statement column_double */
double
sqlite_statement::column_double(
  int _index
){
  if (_index > this->max_col){
  throw ;
  }
return sqlite3_column_double(
  this->stmt
, _index
);
}

} /* data_pattern */
#endif
