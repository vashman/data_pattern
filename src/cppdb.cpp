//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_CPPDB_HPP
#define DATA_PATTERN_CPPDB_HPP

namespace data_pattern {

/* cppdb access */
void
cppdb::access(
  typename cppdb::data_operation _operation
){
_operation(this->typesys);
}

} /* data_pattern */
#endif
