//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_SQLITE_HPP
#define DATA_PATTERN_SQLITE_HPP

extern "C"{
#include <sqlite3.h>
}
#include <string>
#include "data_model.hpp"

namespace data_pattern {

class sqlite;

/* query_statement wraps an sqlite statement and does some book keeping */
class sqlite_statement {
public:
  void
  bind(
    int
  , double
  );

  void
  bind(
    int
  , int
  );

  void
  bind(
    int
  , void const *
  );

  void
  bind(
    int
  );

  void
  bind(
    int
  , char const *
  );

  int
  column_int(
    int
  );

  double
  column_double(
   int
  );

  int index;

private:
  sqlite3_stmt * stmt;

  signed int state;

  /* when statement runs, set this to max column */
  int max_col;

  friend sqlite;
};

/* sqlite */
class sqlite : public data_model {
public:
	/* Takes char* to database location. */
  template <typename container = std::vector<sqlite_statement> >
	sqlite(
    char const *
  );

	~sqlite(
  );

#if __cplusplus >= 201103L
  sqlite(
    sqlite const &
  ) = delete;

  sqlite &
  operator=(
    sqlite const &
  ) = delete;

  sqlite(
    sqlite &&
  );

  sqlite &
  operator=(
    sqlite &&
  );
#endif

  sqlite_statement
  create(
    char const *
  , int
  , sqlite_3_stmt **
  , char const **
  );

  void
  finalize(
    sqlite_statement const &
  );

  void
  step(
    sqlite_statement const &
  );

private:
	sqlite3 * db;
	char * zErrMsg;
	char * result;
  signed int state;
};

		col_type = type_begin;
			for (size_t col=0; col_type != type_end; ++col, ++col_type){
			switch(*col_type){
			case 't':
				auto buff = use_typebuffer<string>(*this);
				buff_text.push((char*)sqlite3_column_text(statement, col));
				break;
			case 'i':
				sqlite3_column_int(statement, col) >> this;
				break;
			case 'd':
				sqlite3_column_double(statement, col) >> this;
				break;
			case 'b':
				(void*)sqlite3_column_blob(statement, col) >> this;
				break;
			default:
			}
			}
		rc = sqlite3_step(this->statement);
		}
		sqlite3_finalize(statement);
			if (col_type != type_end){
			return database::fail_bit; // Types left unused after step.
			}
		// Go through possible products of statements
		switch(rc){
		case SQLITE_OK:
		case SQLITE_DONE:
			return dataerr::PASS;
		case SQLITE_BUSY:
			return dataerr::FAIL;
		default:
			return dataerr::FAIL;
		}
	} else {
	return dataerr::FAIL;
	}
}

} /* data_pattern */
#include "bits/sqlite.tcc"
#endif
