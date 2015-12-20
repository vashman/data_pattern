//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ODATA_MODEL_TCC
#define DATA_PATTERN_ODATA_MODEL_TCC

#include <iterator>
#include "iterator_decorator/iterator.hpp"

namespace data_pattern {
/* rewrite output */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
void
rewrite (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, T const & _var
){
/*
static_assert (
  std::is_same<,>::value
, ""
);
*/
  if ( ! typesystems::rewrite (
      _var
    , OutputIter<T>(_mdl.con)
    , begin(_mdl.writer)
    , end(_mdl.writer)
    , Container::type)
  ) _mdl.setstate ();
return _mdl;  
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, bool const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, signed short const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container,OutputIter,Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, unsigned short const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, signed int const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, unsigned int const &
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, signed long const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, unsigned long const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
 odata_model <
    Container,OutputIter,Writer > & _mdl
, float const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, double const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

/* output value */
template <
  typename T
, typename Container
, template <typename> class OutputIter
, typename Writer >
odata_model <
  Container, OutputIter, Writer > &
operator << (
  odata_model <
    Container,OutputIter,Writer > & _mdl
, long double const & _var
){
rewrite(_mdl,_var);
return _mdl;
}

} /* data_pattern */
#endif
