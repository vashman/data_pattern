
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_SQLITE_HPP
#define DATA_PATTERN_SQLITE_HPP

extern "C"{
#include <sqlite3.h>
}
#include <vector>
#include <string>
#include "data_model.hpp"

namespace data_pattern {
/* sqlite */
class sqlite : public data_model{
public:
	typedef std::string query_type;
	typedef std::vector query_container_type;
  typedef sqlite_t_stmt stmt_type;

	/* Takes char* to database location. */
  template <
    typename ConT_int = std::vector<int>
  , typename ContT_char = std::vector<char>
  , typename ConT_double = std::vector<double>
  , typename ConT_float = std::vector<float>
  >
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

  int
  bind_blob(
    stmt_type *
  , int
//  , void const *
  , int
  , void(*)(void*)
  );

  int
  bind_double(
    stmt_type *
  , int
  );

  int
  bind_int(
    stmt_type *
  , int
  );

  int
  prepare(
    char const *
  , int
  , sqlite_3_stmt **
  , char const **
  );

private:
	sqlite3 * db;
	char * zErrMsg;
	char * result;
};

database::rv_type sqlite::access(database::access_type _req){
//if (sqlite3_prepare_v2(this->db, this->queries[_req].c_str(), this->queries[_req].size(), &this->statement, 0) == SQLITE_OK){ // Create prepared statment
	size_t statement_var_index = 0;
		while (type_begin != type_end){ // Go through data and bind data arguments if there was data to bind
		++statement_var_index;
		switch(*type_begin){
		case 't':{
			auto buff = use_typebuffer<string>(*this);
			string s = buff_text.next();
			sqlite3_bind_text(this->statement, statement_var_index, s.c_str(), s.size(), SQLITE_TRANSIENT);
			buff_text.pop();
			break;
		}
		case 'd':
			auto buff = use_typebuffer<double>(*this);
			sqlite3_bind_double(this->statement, statement_var_index, buff.next());
			buff.pop();
			break;
		}
		++type_begin;
		}
		// Run prepared statement
		auto rc = sqlite3_step(this->statement);
		auto col_type = type_begin;
		while (rc == SQLITE_ROW){
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
