// sqlite re-writers implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_REWRITERS_CPP
#define DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_REWRITERS_CPP

#include <iostream>
#include "../include/sqlite.hpp"
#include "../include/bits/sqlite_rewriters.hpp"

namespace data_pattern {
namespace bits {
namespace sqlite_rw {

template <>
void
type_writer<std::string>::do_put(
  value_type const & _value
,   typesystems
  ::typebuffer_container const & _buff
,   typesystems
  ::owriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buff);

auto & stmt = buff.back();
stmt.bind(
  stmt.index++
, _value.c_str()
);
}

template <>
void
type_writer<raw>::do_put(
  value_type const & _value
,   typesystems
  ::typebuffer_container const & _buff
,   typesystems
  ::owriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buff);

auto & stmt = buff.back();
stmt.bind(
  stmt.index++
, _value.ptr()
, static_cast<int>(_value.size())
);
}

} /* sqlite_rw */
} /* bits */
} /* data_pattern */
#endif
