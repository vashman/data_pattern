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

typesystems::explicit_typeid_type const int_put::array[]
  = {
      typesystems::explicit_typeid<sqlite_statement>::raw_typeid()
    };

/* int_put ctor */
int_put::int_put(
  std::size_t _refs
)
  : typesystems::put_rewriter<int> (
        array
      , static_cast<std::size_t>(1)
      , _refs
    ) {
}

/* int_put::do_rewrite */
bool
int_put::do_rewrite(
  int const & _var
, typesystems::typebuffer_container const & _con
) const {
typesystems::typebuffer_interface<sqlite_statement> & buff
    = typesystems::use_typebuffer<sqlite_statement>(_con);
sqlite_statement stmt = buff.next();
stmt.bind(stmt.index++, _var);
buff.push(stmt);
return (stmt.get_state() == SQLITE_OK);
}

} /* sqlite_rw */ } /* bits */ } /* data_pattern */
#endif
