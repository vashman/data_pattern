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
template <typename T, typename Buffer>
void
set_typebuffers(
    typesystems
  ::typebuffer_container & _buffer
){
  typesystems
::set_typebuffer<T, Buffer>(_buffer);
}

template <
  typename T
, typename Buffer
, typename... Ts
>
void
set_typebuffers(
  typesystems::typebuffer_container &
  _buffer
){
  typesystems
::set_typebuffer<T,Buffer>(_buffer);
set_typebuffers<Ts...>(_buffer);
}

/* cppdb ctor */
template <typename... Ts>
cppdb::cppdb(
)
: data_model() {
set_typebuffers<Ts...>(this->buffer);
}
#endif

template <typename T, typename Writer>
void
cppdb::set_iwriter(
){
  typesystems
::add_writer<Writer>(this->iwriter);
}

template <typename T, typename Writer>
void
cppdb::set_owriter(
){
  typesystems
::add_writer<Writer>(this->owriter);
}

} /* data_pattern */
#endif
