//

//          Copyright Sundeep S. Sangha 2013 - 2014.

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

int
sqlite::prepare(
  char const * _zsql
, int _nbyte
, sqlite_3_stmt ** _ppstmt
, char const ** _pztail
){
return sqlite3_prepare_v2(this->db, _zsql, _nbyte, _ppstmt, __pztail);
}

int
sqlite::step( 
){
sqlite3_step(this->statement);
}

} /* data_pattern */
#endif
