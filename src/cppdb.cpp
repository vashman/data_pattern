// cppdb source

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_CPPDB_CPP
#define DATA_PATTERN_CPPDB_CPP

#include "../include/cppdb.hpp"

namespace data_pattern {

/* cppdb ctor */
cppdb::cppdb(
){
}

/* cppdb access */
void
cppdb::access(
  typename cppdb::data_operation _operation
){
_operation(this->typesys);
}

} /* data_pattern */
#endif
