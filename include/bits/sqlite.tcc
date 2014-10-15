//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_SQLITE_TCC
#define DATA_PATTERN_SQLITE_TCC

#include <typesystems/typesystem.hpp>

namespace data_pattern {

/* sqlite ctor */
template <
  typename ConT_int
, typename ConT_char
, typename ConT_double
>
sqlite<>::sqlite(
  char const * _file
)
  : data_model ()
  , db (nullptr) {
this->zErrMsg = nullptr;
int rc = sqlite3_open(url, &this->db);
	if (rc > 0){
	throw runtime_error("Database open error");
	}
typesystems::set_typebuffer<int, ConT_int>(this->typesys);
typesystems::set_typebuffer<char, ContT_char>(this->typesys);
typesystems::set_typebuffer<double, ContT_double>(this->typesys);
typesystems::set_typebuffer<float, ContT_float>(this->typesys);
typesystems::set_typebuffer<bool, ContT_bool>(this->typesys);
typesystems::set_typebuffer<char *, ContT_char_ptr>(this->typesys);
typesystems::set_typebuffer<void *, ContT_void_ptr>(this->typesys);
}

} /* data_pattern */
#endif
