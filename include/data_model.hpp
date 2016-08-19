// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_IO_MODEL_HPP
#define DATA_PATTERN_IO_MODEL_HPP

#include <utility>
#include "output_model.hpp"
#include "input_model.hpp"

namespace data_pattern {

/* data_model */
template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
struct data_model
: public
  input_model <Device,GetInputMap,Sync>
, output_model <Device,GetOutputMap,Sync>
{

/* dtor */
~data_model() noexcept = default;

/* ctor */
data_model (
  Device
, GetInputMap
, GetOutputMap
, Sync
);

/* ctor move */
data_model (
  data_model <
    Device
  , GetInputMap
  , GetOutputMap
  , Sync > &&
) = default;

/* assignment operator move */
data_model <
  Device, GetInputMap, GetOutputMap, Sync > &
operator = (
  data_model <
    Device, GetInputMap, GetOutputMap, Sync > &&
) = default;

/* ctor copy */
data_model (
  data_model <
    Device, GetInputMap, GetOutputMap, Sync >
  const &
) = delete;

/* assignment operator copy */
data_model <
  Device, GetInputMap, GetOutputMap, Sync > &
operator = (
  data_model <
    Device, GetInputMap, GetOutputMap, Sync >
  const &
) = delete;

class iterator
: public
  std::iterator <
    std::input_iterator_tag, iterator >{

data_model <
    Device
  , GetInputMap
  , GetOutputMap
  , Sync >
* mdl;

public:

explicit
iterator (
  data_model <
     Device
   , GetInputMap
   , GetOutputMap
   , Sync >
  & _mdl
)
: mdl (&_mdl)
{}

explicit
iterator () : mdl (nullptr){}

iterator (iterator const &) = default;

iterator &
operator = (iterator const &) = default;

iterator (iterator &&) = default;

iterator &
operator = (iterator &&) = default;

~iterator () = default;

iterator &
operator * (){
return *this;
}

iterator &
operator -> (){
return this;
}

iterator
operator ++ (int){
sync(*(this->mdl));
return *this;
}

iterator &
operator ++ (){
sync(*(this->mdl));
return *this;
}

template <typename T>
operator T(){
T temp;
*(this->mdl) >> temp;
return temp;
}

template <typename T>
void
operator = (
  T const & _var
){
*(this->mdl) << _var;
}

bool
operator == (
  iterator const &
) const {
return (
   this->mdl->state == model_state::end
);}

bool
operator != (
  iterator const & _lhs
) const {
return !(*this == _lhs);
}

}; /*  iterator */
}; /* data model */

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
data_model <Device,GetInputMap,GetOutputMap, Sync>
make_data_model (
  Device
, GetInputMap
, GetOutputMap
, Sync
);

/* ctor */
template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
  data_model <
    Device
  , GetInputMap
  , GetOutputMap
  , Sync >
::data_model (
  Device _device
, GetInputMap _input_iter
, GetOutputMap _output_iter
, Sync _sync
)
: model <Device,Sync> (
    std::move(_device)
  , std::move(_sync) )
, input_model <
      Device
    , GetInputMap
    , Sync >
  (
    std::move(_device)
  , std::move(_input_iter)
  , std::move(_sync)
  )
, output_model <Device, GetOutputMap, Sync> (
    std::move(_device)
  , std::move(_output_iter)
  , std::move(_sync) )
{
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
data_model <Device,GetInputMap,GetOutputMap,Sync>
make_data_model (
  Device _device
, GetInputMap _in_iter
, GetOutputMap _out_iter
, Sync _sync
){
return
data_model <
  Device
, GetInputMap
, GetOutputMap
, Sync >
( std::move(_device)
, std::move(_in_iter)
, std::move(_out_iter)
, std::move(_sync) );
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
  typename data_model <
    Device, GetInputMap, GetOutputMap, Sync >
::iterator
begin (
  data_model <
    Device, GetInputMap, GetOutputMap, Sync > &
);

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
  typename data_model <
    Device, GetInputMap, GetOutputMap, Sync >
::iterator
end (
   data_model <
    Device, GetInputMap, GetOutputMap, Sync > const &
);

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
  typename data_model <
    Device, GetInputMap, GetOutputMap, Sync >
::iterator
begin (
  data_model <
    Device, GetInputMap, GetOutputMap, Sync > & _mdl
){
return typename data_model <Device,GetInputMap,GetOutputMap,Sync>
::iterator (_mdl);
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap
, typename Sync >
  typename data_model <
    Device, GetInputMap, GetOutputMap, Sync >
::iterator
end (
 data_model <
    Device, GetInputMap, GetOutputMap, Sync > const &
){
return typename data_model <Device,GetInputMap,GetOutputMap,Sync>
::iterator ();
}

} /* data_pattern */
#endif

