// template implementation of sqlite.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_TCC
#define DATA_PATTERN_SQLITE_TCC

#include "sqlite_rewriters.hpp"

namespace data_pattern {

/* sqlite ctor */
sqlite::sqlite (
  char const * _file
)
: db (NULL)
, zErrMsg (NULL)
, result (NULL) {
  bits::sqlite
::check_error (
  sqlite3_open(_file, &this->db) );
};

} /* data_pattern */
#endif
