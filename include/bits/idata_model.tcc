//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_IDATA_MODEL_TCC
#define DATA_PATTERN_IDATA_MODEL_TCC

#include <iterator>
#include "iterator_decorator/iterator.hpp"

namespace data_pattern {

/* rewrite input */
template <
  typename T
, typename Container
, typename Reader >
void
rewrite (
  idata_model <Container, Reader> & _mdl
, T & _var
){
  if ( ! typesystems::rewrite (
      _var
    , begin<T>(_mdl.con)
    , end<T>(_mdl.con)
    , begin(_mdl.reader)
    , end(_mdl.reader)
    , Container::type)
   ) _mdl.setstate ();
return _mdl;
}

/* empty 
  Check if buffer is empty.
*/
template <
  typename T
, typename Container
, typename Reader >
bool
empty (
  idata_model <Container,Reader>
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
