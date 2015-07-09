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
template <typename Container>
sqlite::sqlite (
  char const * _file
)
: data_model ()
, db (NULL)
, zErrMsg (NULL)
, result (NULL) {
bits::sqlite::check_error(
  sqlite3_open(_file, &this->db)
);
  typesystems
::set_typebuffer
<sqlite_statement, Container>
(this->buffer);

/* Add input writers */
  typesystems
::add_writer<
  bits::sqlite_rw::type_writer<int>
>(this->iwriter);

  typesystems
::add_writer<
  bits::sqlite_rw::type_writer<double>
>(this->iwriter);

typesystems::add_writer<
    bits
  ::sqlite_rw::type_writer<std::string>
>(this->iwriter);

typesystems::add_writer<
  bits::sqlite_rw::type_writer<raw>
>(this->iwriter);

/* Add output writers */
  typesystems
::add_writer<
  bits::sqlite_rw::type_writer<int>
>(this->owriter);

  typesystems
::add_writer<
  bits::sqlite_rw::type_writer<double>
>(this->owriter);

  typesystems
::add_writer<
    bits
  ::sqlite_rw::type_writer<std::string>
>(this->owriter);

typesystems::add_writer<
  bits::sqlite_rw::type_writer<raw>
>(this->owriter);
}

} /* data_pattern */
#endif
