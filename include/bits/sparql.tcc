//

//

#ifndef DATA_PATTERN_SPARQL_TCC
#define DATA_PATTERN_SPARQL_TCC

namespace data_pattern {

template <typename Model, typename sparql_traits>
void
do_interpret(
  Model & _model
, char const * const _data
){
/* determine the query type */
switch(_data[0]){
  case 'P':
  case 'p':
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
