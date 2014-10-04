
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_CPPDB_TCC
#define DATA_PATTERN_CPPDB_TCC

#include "../include/cppdb.hpp"

namespace data_pattern {

#if __cplusplus >= 201103L
/* set_typebuffers
Recursive function to add all types to typesystem.
*/
template <typename T, typename Container>
set_typebuffers(typesystems::typesystem & _typesys){
typesystems::set_typebuffer<T, Container>(_typesys);
}

template <typename T, typename Container, typename... Ts>
set_typebuffers(typesystems::typesystem & _typesys){
typesystems::set_typebuffer<T, Container>(_typesys);
set_typebuffers<Ts...>(_typesys);
}

/* cppdb ctor */
template <typename... Ts>
cppdb::cppdb(
)
  : data_model() {
static_assert((sizeof...(Ts) / 2) == 0
, "Odd number of template types, you are missing a container type.");
set_typebuffers<Ts...>(this->typesys);
}
#endif

template <typename T, typename Container>
void
cppdb::add_type(
){
typesystems::set_typebuffer<T, Contaner>();
}

} /* data_pattern */
#endif
