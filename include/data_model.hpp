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
, typename GetOutputMap >
struct data_model
: public
  input_model <Device,GetInputMap>
, output_model <Device,GetOutputMap>
{

/* dtor */
~data_model() noexcept = default;

/* ctor */
data_model (
  Device
, GetInputMap
, GetOutputMap
);

/* ctor move */
data_model (
  data_model <
    Device
  , GetInputMap
  , GetOutputMap > &&
) = default;

/* assignment operator move */
data_model <
  Device, GetInputMap, GetOutputMap > &
operator = (
  data_model <
    Device, GetInputMap, GetOutputMap > &&
) = default;

/* ctor copy */
data_model (
  data_model <
    Device, GetInputMap, GetOutputMap >
  const &
) = delete;

/* assignment operator copy */
data_model <
  Device, GetInputMap, GetOutputMap > &
operator = (
  data_model <
    Device, GetInputMap, GetOutputMap >
  const &
) = delete;

class iterator
: public
  std::iterator <
    std::input_iterator_tag, iterator >{

data_model <
    Device
  , GetInputMap
  , GetOutputMap >
* mdl;

public:

explicit
iterator (
  data_model <
     Device
   , GetInputMap
   , GetOutputMap >
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
, typename GetOutputMap >
data_model <Device,GetInputMap,GetOutputMap>
make_data_model (
  Device
, GetInputMap
, GetOutputMap
);

/* ctor */
template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
  data_model <
    Device
  , GetInputMap
  , GetOutputMap >
::data_model (
  Device _device
, GetInputMap _input_iter
, GetOutputMap _output_iter
)
: model <Device> (std::move(_device))
, input_model <
      Device
    , GetInputMap >
  (
    std::move(_device)
  , std::move(_input_iter)
  )
, output_model <Device, GetOutputMap> (
    std::move(_device)
  , std::move(_output_iter) )
{
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
data_model <Device,GetInputMap,GetOutputMap>
make_data_model (
  Device _device
, GetInputMap _in_iter
, GetOutputMap _out_iter
){
return
data_model <
  Device
, GetInputMap
, GetOutputMap >
( std::move(_device)
, std::move(_in_iter)
, std::move(_out_iter) );
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
  typename data_model <
    Device, GetInputMap, GetOutputMap >
::iterator
begin (
  data_model <
    Device, GetInputMap, GetOutputMap > &
);

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
  typename data_model <
    Device, GetInputMap, GetOutputMap >
::iterator
end (
   data_model <
    Device, GetInputMap, GetOutputMap > const &
);

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
  typename data_model <
    Device, GetInputMap, GetOutputMap >
::iterator
begin (
  data_model <
    Device, GetInputMap, GetOutputMap > & _mdl
){
return typename data_model <Device,GetInputMap,GetOutputMap,>
::iterator (_mdl);
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
  typename data_model <
    Device, GetInputMap, GetOutputMap >
::iterator
end (
 data_model <
    Device, GetInputMap, GetOutputMap > const &
){
return typename data_model <Device,GetInputMap,GetOutputMap>
::iterator ();
}

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
data_model <
  Device,GetInputMap,GetOutputMap > &
sync (
data_model <
  Device,GetInputMap,GetOutputMap >
  & _mdl
);

template <
  typename Device
, typename GetInputMap
, typename GetOutputMap >
data_model <
  Device,GetInputMap,GetOutputMap > &
sync (
data_model <
  Device,GetInputMap,GetOutputMap >
  & _mdl
){
_mdl.state = model_state::sync;
static_cast<output_model<Device,GetOutputMap>&>(_mdl)
  .iterator_map(_mdl);
_mdl.state = model_state::sync;
static_cast<Input_model<Device,GetInputMap>&>(_mdl)
  .iterator_map(_mdl);
return _mdl;
}

} /* data_pattern */
#endif

