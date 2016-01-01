//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_IDATA_MODEL_TCC
#define DATA_PATTERN_IDATA_MODEL_TCC

#include <iterator>
#include <typesystems/type_traits.hpp>
#include "iterator_decorator/iterator.hpp"

namespace data_pattern {

template <
  typename Buffer
, typename MakeOutputIter
, typename MakeInputIter
, typename Reader
, typename GetWriter >
  idata_model <
    Buffer, Reader, OutputIter
  , GetWriter >
::idata_model (
  data_model_buffer <
    Buffer, MakeInputIter
  , MakeOutputIter > * _buffer
, GetWriter _get_writer
)
: get_writer (_get_writer)
, reader ()
, state ()
, buffer (_buffer) {
}

/* rewrite input */
template <
  typename T
, typename Buffer
, typename MakeOutputIter
, typename MakeInputIter
, typename Reader
, typename GetWriter >
idata_model <
  Buffer, MakeOutputIter, MakeInputIter
, Reader, GetWriter > &
rewrite (
  T & _var
, idata_model <
    Buffer, MakeOutputIter
  , MakeInputIter,Reader,GetWriter >
  & _mdl
){
auto stop (
  typesystems::qualified_typeid<void>()
);
  
auto rv (
  typesystems::qualified_typeid<void>()
);

do {
rv = typesystems::rewrite <,T> (
  begin(*_mdl.buffer), end(*_mdl.buffer)
, _mdl.buffer.make_output_iter()
, begin(_mdl.reader), end(_mdl.reader)
, _mdl.get_writer
)
} while (rv != stop);

return _mdl;
}

/* empty 
  Check if buffer is empty.
*/
template <
  typename T
, typename Container
, typename Reader
, typename Find >
bool
empty (
  idata_model <Container,Reader, Find>
  const & _mdl
){
return
begin<T>(_mdl.con) == end<T>(_mdl.con);
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, bool & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Contaner, Reader> & _mdl
, signed short & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, unsigned short & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, signed int & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  data_model <Container, Reader> & _mdl
, unsigned int & _var
){
rewrite (_mdl,_var);
return _mdl;  
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model<Container,Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, signed long & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, unsigned long & _var
){
rewrite (_mdl,_var);
return _mdl;  
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, float & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, double & _var
){
rewrite (_mdl,_var);
return _mdl;
}

/* input value */
template <
  typename T
, typename Container
, typename Reader >
idata_model <Container, Reader> &
operator >> (
  idata_model <Container, Reader> & _mdl
, long double & _var
){
rewrite (_mdl,_var);
return _mdl;
}

} /* data_pattern */
#endif
