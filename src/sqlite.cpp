// data_model sqlite implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_CPP
#define DATA_PATTERN_SQLITE_CPP

#include "../include/sqlite.hpp"

namespace data_pattern {

/* sqlite dtor */
sqlite::~sqlite(
){
sqlite3_close(this->db);
delete zErrMsg;
}

void
sqlite::step(
  sqlite_statement const & _stmt
){
_stmt.state = sqlite3_step(_stmt.stmt);
  if (_stmt.state == SQLITE_OK){
  _stmt.max_col = sqlite3_column_count();
  }
}

void
sqlite::finalize(
  sqlite_statement const & _stmt
){
sqlite3_finilize(_stmt.stmt);
}

/* sqlite create */
sqlite_statement
sqlite::create(
  char const * _query
, int _size
, char const **
){
sqlite_statement stmt();
stmt.state = sqlite_3_prepare_v2(this->db, _query, _size, &stmt->stmt, 0);
return stmt;
}

/* sqlite_statement */
/* sqlite_statement bind_int */
void
sqlite_statement::bind(
  int _index
, int _var
){
this->state = sqlite3_bind_int(&this->stmt, _index, _var);
}

/* sqlite_statement bind_blob */
void
sqlite_statement::bind(
  int _index
, void const * _blob
, int _size
){
this->state = sqlite3_bind_blob(&this->stmt, _index, _blob, _size
              , SQLITE_TRANSIENT);
}

/* sqlite_statement bind */
void
sqlite_statement::bind(
  int _index
, char const * _str
){
this->state = sqlite3_bind_text(&this->stmt, _index, _str
              , std::char_traits<char>::length(_str), SQLITE_TRANSIENT);
}

/* sqlite_statement bind */
void
sqlite_statement::bind(
  int _index
, double _var
){
this->state = sqlite3_bind_double(&this->stmt, _index, _var);
}

void
sqlite_statement::bind(
  int _index
){
this->state = sqlite3_bind_null(&this->stmt, _index);
}

/* sqlite_statement column_int */
int
sqlite_statement::column_int(
  int _index
){
  if (_index > this->max_col){
  throw ;
  }
return sqlite3_column_int(&this->stmt, _index);
}

/* sqlite_statement column_double */
double
sqlite_statement::column_double(
  int _index
){
  if (_index > this->max_col){
  throw ;
  }
return sqlite3_column_double(&this->stmt, _index);
}

/* sqlite rewriters */

} /* data_pattern */
#endif
