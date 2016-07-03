//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_TCC
#define DATA_PATTERN_OUTPUT_MODEL_TCC

#include <utility>

namespace data_pattern {

/* ctor */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
::output_model (
  Device _device
, MakeOutputIterator _output_iter
, Sync _sync
)
: model <Device,Sync> (
    std::move(_device)
  , std::move(_sync) )
, output_iterator (
    std::move(_output_iter) )
{}

/* make output model */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync >
make_output_model (
  Device _device
, MakeOutputIterator _output_iter
, Sync _sync
){
return output_model <
  Device, MakeOutputIterator, Sync > (
  std::move(_device)
, std::move(_output_iter)
, std::move(_sync) );
}

template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
  typename output_model <
    Device, MakeOutputIterator, Sync >
::iterator
make_output_iterator (
  output_model <
    Device, MakeOutputIterator, Sync >
& _mdl
){
return typename output_model <
  Device, MakeOutputIterator, Sync >
::iterator(_mdl);
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, bool const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, signed short const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, unsigned short const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, signed int const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, unsigned int const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, signed long const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, unsigned long const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
 output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, float const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, double const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, long double const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, signed char const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

/* output value */
template <
  typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <
  Device
, MakeOutputIterator
, Sync > &
operator << (
  output_model <
    Device
  , MakeOutputIterator
  , Sync >
  & _mdl
, unsigned char const & _var
){
*_mdl.output_iterator(_mdl.device)++
  = _var;
return _mdl;
}

} /* data_pattern */
#endif

