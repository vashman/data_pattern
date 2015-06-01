// sqlite reqeriters implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_CPP
#define DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_CPP

#include "../include/sqlite.hpp"
#include "../include/bits/sqlite_rewriters.hpp"

namespace data_pattern {
namespace bits {
namespace sqlite_rw {

  typesystems
::explicit_typeid_type const
int_put::array[] = {
    typesystems
  ::explicit_typeid<sqlite_statement>
  ::raw_typeid()
};

/* ctor */
int_put::int_put(
  std::size_t _refs
)
: typesystems::put_rewriter<int> (
    array
  , static_cast<std::size_t>(1)
  , _refs
) {
}

/* int_put do_rewrite
  No need to check for type buffers
  since the assumption is sqlite always
  uses sqlite_statements internally.
*/
void
int_put::do_rewrite(
  int const & _value
,   typesystems
  ::typebuffer_container const & _buffer
) const {
  typesystems
::typebuffer_interface<sqlite_statement>
  & buff = typesystems
::use_typebuffer<sqlite_statement> (
  _buffer
);

auto stmt = buff.next();
stmt.bind(stmt.index++, _value);
buff.push(stmt);
}

} /* sqlite_rw */
} /* bits */
} /* data_pattern */
#endif
// sqlite reqeriters implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_CPP
#define DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_CPP

#include "../include/sqlite.hpp"
#include "../include/bits/sqlite_rewriters.hpp"

namespace data_pattern {
namespace bits {
namespace sqlite_rw {

  typesystems
::explicit_typeid_type const
int_put::array[] = {
    typesystems
  ::explicit_typeid<sqlite_statement>
  ::raw_typeid()
};

/* ctor */
int_put::int_put(
  sqlite & _db
)
: typesystems::put_rewriter<int> (
    array
  , static_cast<std::size_t>(1)
  , _refs)
, db (&_db) {
}

/* int_put do_rewrite
  No need to check for type buffers
  since the assumption is sqlite always
  uses sqlite_statements internally.
*/
void
int_put::do_rewrite(
  int const & _value
,   typesystems
  ::typebuffer_container const & _buffer
) const {
  typesystems
::typebuffer_interface<sqlite_statement>
  & buff = typesystems
::use_typebuffer<sqlite_statement> (
  _buffer
);

auto stmt = buff.next();
stmt.bind(
  stmt.index++
, _value
, this->db
);
buff.push(stmt);
}

} /* sqlite_rw */
} /* bits */
} /* data_pattern */
#endif
