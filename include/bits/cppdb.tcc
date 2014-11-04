// cppdb template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef DATA_PATTERN_CPPDB_TCC
#define DATA_PATTERN_CPPDB_TCC

namespace data_pattern {

#if __cplusplus >= 201103L
/* set_typebuffers
Recursive function to add all types to typesystem.
*/
template <typename T, typename Container>
void
set_typebuffers(typesystems::typesystem & _typesys){
typesystems::set_typebuffer<T, Container>(_typesys);
}

template <typename T, typename Container, typename... Ts>
void
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
typesystems::set_typebuffer<T, Container>();
}

} /* data_pattern */
#endif
