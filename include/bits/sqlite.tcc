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
  , db (nullptr)
  , state (SQLITE_OK) {
this->zErrMsg = nullptr;
int rc = sqlite3_open(url, &this->db);
	if (rc > 0){
	throw runtime_error("Database open error");
	}
typesystems::set_typebuffer<sqlite_statement, container>(this->typesys);
}

int
sqlite::get_text(
  stmt_type _stmt
, int _index
){
static_cast<char*>(sqlite3_column_text(_stmt, _index));
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
return (stmt.bind_int(_var, stmt.index++) == SQLITE_OK);
}

} /* data_pattern */
#endif
