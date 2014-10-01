
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STDL_DATABASE_SQLITE_HPP
#define STDL_DATABASE_SQLITE_HPP

extern "C"{
#include <sqlite3.h>
}
#include <initializer_list>
#include <vector>
#include <string>
#include <tuple>
#include <stdl/database.hpp>
#include <deque>

namespace stdl{
template <
  template <typename> class C_int =
, template <typename> class C_double =
, template <typename> class C_float = 
>
class sqlite : public database{
public:
	typedef std::string query_type;
	typedef std::vector query_container_type;
	/*
	   + Takes char* to database location, vector of startup queries and schema_type
	   + 
	*/
	sqlite(char const*, std::initializer_list<query_type>);
	~sqlite();
	virtual database::rv_type access(database::access_type);
private:
	sqlite3* db;
	char* zErrMsg;
	sqlite3_stmt *statement;
	char* result;
	vector<string> queries;
};

template <
  template <typename> class C_int =
, template <typename> class C_double =
, template <typename> class C_float = 
>
sqlite::sqlite(char const* _url, vector<string> _queries)
	: database ()
	, queries (_queries){
// Open database.
this->zErrMsg = nullptr;
int rc = sqlite3_open(url, &this->db);
	if (rc > 0){
	throw runtime_error("Database open error");
	}
this->buff_map[typebuffer_interface<int>::type_id] = new typebuffer<int, C_int<int>>();
this->buff_map[typebuffer_interface<double>::type_id] = new typebuffer<double, C_double<double>>();
}

sqlite::~sqlite(){
sqlite3_close(this->db);
delete zErrMsg;
}

database::rv_type sqlite::access(database::access_type _req){
	if (_req > (this->queries.size()/2)){
	return database::noquery_bit;
	}
	if (sqlite3_prepare_v2(this->db, this->queries[_req].c_str(), this->queries[_req].size(), &this->statement, 0) == SQLITE_OK){ // Create prepared statment
	string::const_iterator type_begin = this->queries[_req+1].cbegin();
	string::const_iterator type_end = this->queries[_req+1].cend();
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
		case 'i':
			auto buff = use_typebuffer<int>(*this);
			sqlite3_bind_int(this->statement, statement_var_index, buff.next());
			buff.pop();
			break;
		case 'd':
			auto buff = use_typebuffer<double>(*this);
			sqlite3_bind_double(this->statement, statement_var_index, buff.next());
			buff.pop();
			break;
		case 'b':
			auto buff = use
			//reinterpret_cast<void*>(*data_begin);
			buff.pop();
			break;
		default:
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
}
#endif
