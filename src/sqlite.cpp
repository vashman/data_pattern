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

/* sqlite dtor */
sqlite::~sqlite(
){
sqlite3_close(this->db);
delete zErrMsg;
delete result;
}

/**/
void
sqlite::set_state(
  int _rv
){
switch (_rv){
  case SQLITE_OK:
    this->rdstate(data_model::good);
    break;
  case SQLITE_ERROR:
  case SQLITE_BUSY:
  case SQLITE_AUTH:
  default:
    this->rdstate(data_model::bad);
}
}

/* sqlite step */
void
sqlite::step (
  sqlite_statement & _stmt
){
_stmt.state = sqlite3_step(_stmt.stmt);
  if (_stmt.state == SQLITE_OK){
    _stmt.max_col
  = sqlite3_column_count(_stmt.stmt);
  _stmt.index = 0;
  }
}

/* step */
void
sqlite::step(
){
  auto & buff
= typesystems
::use_typebuffer<sqlite_statement>(
  this->typesys
);
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
: index (0) 
, max_col (0) 
, ref (new unsigned int(1)) {
this->state = sqlite3_prepare_v2(
  _db.db
, _query
  /* Query should be null terminated. */
, -1 
, & this->stmt
  /* There is never an unused portion of
    the statement.
  */
, 0
);
}

/* ctor copy */
sqlite_statement::sqlite_statement(
  sqlite_statement const & _stmt
)
: index (_stmt.index)
, state (_stmt.state)
, max_col (_stmt.max_col)
, ref (_stmt.ref) {
++(*ref);
this->stmt = _stmt.stmt;
}

/* dtor */
sqlite_statement::~sqlite_statement(
){
  if (0 == (*ref)--)
  sqlite3_finalize(stmt);
}

/* sqlite_statement bind_int */
void
sqlite_statement::bind(
  int _index
, int _var
){
this->state = sqlite3_bind_int(
  this->stmt
, _index
, _var
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
this->state = sqlite3_bind_blob(
  this->stmt
, _index
, _blob
, _size
, sqlite_dtor_data
);
}

/* sqlite_statement bind */
void
sqlite_statement::bind (
  int _index
, char const * _str
){
this->state = sqlite3_bind_text(
  this->stmt
, _index
, _str
, static_cast<int>(
    std::char_traits<char>::length(_str)
  )
, sqlite_dtor_data
);
}

/* sqlite_statement bind */
void
sqlite_statement::bind (
  int _index
, double _var
){
this->state = sqlite3_bind_double(
  this->stmt
, _index
, _var
);
}

/* sqlite bind null */
void
sqlite_statement::bind (
  int _index
){
this->state = sqlite3_bind_null(
  this->stmt
, _index
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

/* sqlite_statement get_state */
signed int
sqlite_statement::get_state (
) const {
return this->state;
}

} /* data_pattern */
#endif
