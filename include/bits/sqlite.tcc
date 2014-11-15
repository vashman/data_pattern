//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_SQLITE_TCC
#define DATA_PATTERN_SQLITE_TCC

#include <typesystems/typesystem.hpp>

namespace data_pattern {

/* sqlite ctor */
template <typename container>
sqlite<container>::sqlite(
  char const * _file
)
  : data_model ()
  , db (nullptr) {
this->zErrMsg = nullptr;
int rc = sqlite3_open(url, &this->db);
	if (rc > 0){
	throw runtime_error("Database open error");
	}
typesystems::set_typebuffer<sqlite_statement, container>(this->typesys);
}

sqlite_statement
sqlite::create(
  char const * _query
, int _size
, char const **
){
sqlite_statement stmt();
stmt->state = sqlite_3_prepare_v2(this->db, _query, _size, &stmt->stmt, 0);
return stmt;
}

/* sqlite bind_int */
void
sqlite_statement::bind_int(
  int _var
, int _index
){
this-state = sqlite3_bind_int(&this->stmt, _index, _var);
}

/* sqlite bind_blob */
void
sqlite_statement::bind_blob(
  stmt_type *
, int
){
}

/* sqlite bind_text */
void
sqlite_statement::bind_text(
  int _index
, char const * _str
){
this->state = sqlite3_bind_text(&this->_stmt, _index, _str
              , std::char_traits<char>::length(_str), SQLITE_TRANSIENT);
}

int
sqlite::get_text(
  stmt_type _stmt
, int _index
){
static_cast<char*>(sqlite3_column_text(_stmt, _index));
}

void
sqlite::step(
  sqlite_statement const & _stmt
){
_stmt.state = sqlite3_step(_stmt.stmt);
}

void
sqlite::finalize(
  sqlite_statement const & _stmt
){
sqlite3_finilize(_stmt.stmt);
}

/* */
bool
int_put_rewriter::do_rewrite(
  int const & _var
, typesystems::typebuffer_container const & _con
) const {
typesystems::typebuffer_interface<sqlite_statement> & buff
  = typesystems::use_typebuffer<sqlite_statement>(_con);
auto stmt = buff.next();
stmt.bind_int(_var, stmt.index++);
}

} /* data_pattern */
#endif
