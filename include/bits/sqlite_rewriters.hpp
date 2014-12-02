// rewriters for pod sqlite types

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_HPP
#define DATA_PATTERN_BITS_SQLITE_RW_SQLITE_REWRITERS_HPP

#include <typesystems/get_rewriter.hpp>
#include <typesystems/put_rewriter.hpp>

namespace data_pattern {
namespace bits {
namespace sqlite_rw {

class int_put : public typesystems::put_rewriter<int> {
public:
  int_put(
    std::size_t _refs = 0
  );

private:
  virtual bool
  do_rewrite(
    int const &
  , typesystems::typebuffer_container const &
  ) const;

  static typesystems::explicit_typeid_type const array[1];
};

} /* sqlite_rw */ } /* bits */ } /* data_patten */
#endif
