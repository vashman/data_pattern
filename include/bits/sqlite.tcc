// template implementation of sqlite data_model

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_TCC
#define DATA_PATTERN_SQLITE_TCC

#include <stdexcept>
#include <typesystems/typesystem.hpp>

namespace data_pattern {

/* sqlite ctor */
template <typename container>
sqlite::sqlite(
  char const * _file
)
  : data_model ()
  , db (nullptr)
  , state (SQLITE_OK) {
this->zErrMsg = NULL;
int rc = sqlite3_open(_file, &this->db);
	if (rc > 0){
	throw std::runtime_error("Database open error");
	}
typesystems::set_typebuffer<sqlite_statement, container>(this->typesys);
}

} /* data_pattern */
#endif
