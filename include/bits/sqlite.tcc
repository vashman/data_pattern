// template implementation of sqlite.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_TCC
#define DATA_PATTERN_SQLITE_TCC

namespace data_pattern {

/* sqlite ctor */
sqlite::sqlite (
  char const * _file
)
: db (nullptr, sqlite3_close)
, zErrMsg (nullptr)
, result (nullptr) {
sqlite3 * temp;
  bits::sqlite
::check_error (
  sqlite3_open(_file, &temp) );
this->db.reset(temp, sqlite3_close);
}

} /* data_pattern */
#include "string_data_model_shifts.hpp"
#endif

