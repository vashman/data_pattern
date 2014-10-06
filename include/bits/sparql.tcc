//

//

#ifndef DATA_PATTERN_SPARQL_TCC
#define DATA_PATTERN_SPARQL_TCC

#include <vector>
#include <string>

namespace data_pattern {

template <typename Model, typename sparql_traits>
void
do_interpret(
  Model & _model
, char const * const _data
){
model_store<Model> store;
std::vector<std::string> prefix;
std::size_t pos = 0;
/* prase prefix */
while (_data[pos] == 'P' || _data[pos] == 'P'){
  /* check entire prefix statment and find end via '\n' */
  if (){
  std::size_t name_end;
  prefix.push_back(std::string(_data[pos + 8], _data[name_end]));
  std::size_t prefix_end;
  prefix.push_back(std::string(_data[name_end + 1], _data[prefix_end]));
}
/* determine the query type */
switch(_data[pos]){
  case 'S':
  case 's':
  case 'C':
  case 'c':
  case 'A':
  case 'a':
  case 'D':
  case 'd':
  default:
    /* error prasing statment */
    return ;
}
}

}/* data_pattern */
#endif
