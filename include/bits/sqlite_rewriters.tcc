// rewriters for pod sqlite types

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_OWRITER_TCC
#define DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_OWRITER_TCC

namespace data_pattern {
namespace bits {
namespace sqlite_rw {
/* do_put
  No need to check for type buffers
  since the assumption is sqlite always
  uses sqlite_statements internally.
*/
template <typename T>
void
type_writer<T>::do_put(
  value_type const & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::owriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
stmt.bind(stmt.index++, _value);
}

/* do_get */
template <typename T>
void
type_writer<T>::do_get(
  value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
_value = static_cast<T>(stmt);
}

/* do_empty */
template <typename T>
bool
type_writer<T>::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return true;
}

} /* sqlite_rw */
} /* bits */
} /* data_patten */
#include "sqlite_rewriters.tcc"
#endif
