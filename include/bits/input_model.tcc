//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_TCC
#define DATA_PATTERN_INPUT_MODEL_TCC

#include <utility>

namespace data_pattern {

/* ctor */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
  input_model <
  Device
, MakeInputIterator
, Sync >
::input_model (
  Device _device
, MakeInputIterator _input_iter
, Sync _sync
)
: model <Device,Sync> (
    std::move(_device)
  , std::move(_sync) )
, input_iterator (
  std::move(_input_iter) )
{}

template <
  typename Device
, typename MakeInputIterator
, typename Sync >
  typename input_model <
    Device, MakeInputIterator, Sync >
::iterator
begin (
  input_model <
    Device, MakeInputIterator, Sync >
  & _mdl
){
return typename input_model <
    Device, MakeInputIterator, Sync >
::iterator (_mdl);
}

template <
  typename Device
, typename MakeInputIterator
, typename Sync >
  typename input_model <
    Device, MakeInputIterator, Sync >
::iterator
end (
  input_model <
    Device, MakeInputIterator, Sync >
  & _mdl
){
return typename input_model <
    Device, MakeInputIterator, Sync >
::iterator(_mdl);
}

/* make input model */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model<
  Device
, MakeInputIterator
, Sync >
make_input_model (
  Device _device
, MakeInputIterator _input_iter
, Sync _sync
){
return input_model <
Device, MakeInputIterator, Sync > (
  std::move(_device)
, std::move(_input_iter)
, std::move(_sync) );
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device, MakeInputIterator, Sync >
  & _mdl
, bool & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, signed short & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, unsigned short & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, signed int & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, unsigned int & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, signed long & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, unsigned long & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, float & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
    Device
  , MakeInputIterator
  , Sync >
  & _mdl
, double & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
  Device
, MakeInputIterator
, Sync >
  & _mdl
, long double & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

/* input value */
template <
  typename Device
, typename MakeInputIterator
, typename Sync >
input_model <
  Device
, MakeInputIterator
, Sync > &
operator >> (
  input_model <
  Device
, MakeInputIterator
, Sync >
  & _mdl
, char & _var
){
_var
  = *_mdl.input_iterator(_mdl.device)++;
return _mdl;
}

} /* data_pattern */
#endif

