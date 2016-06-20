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
, typename MakeInputIterator
, typename MakeOutputIterator
, typename Sync >
struct data_model
: public
  input_model <Device,MakeInputIterator,Sync>
, output_model <Device,MakeOutputIterator,Sync>
{

/* dtor */
~data_model() noexcept = default;

/* ctor */
data_model (
  Device
, MakeInputIterator
, MakeOutputIterator
, Sync
);

/* ctor move */
data_model (
  data_model <
    Device
  , MakeInputIterator
  , MakeOutputIterator
  , Sync > &&
) = default;

/* assignment operator move */
data_model <
  Device, MakeInputIterator, MakeOutputIterator, Sync > &
operator = (
  data_model <
    Device, MakeInputIterator, MakeOutputIterator, Sync > &&
) = default;

/* ctor copy */
data_model (
  data_model <
    Device, MakeInputIterator, MakeOutputIterator, Sync >
  const &
) = delete;

/* assignment operator copy */
data_model <
  Device, MakeInputIterator, MakeOutputIterator, Sync > &
operator = (
  data_model <
    Device, MakeInputIterator, MakeOutputIterator, Sync >
  const &
) = delete;

}; /* data model */

template <
  typename Device
, typename MakeInputIterator
, typename MakeOutputIterator
, typename Sync >
data_model <Device,MakeInputIterator,MakeOutputIterator, Sync>
make_data_model (
  Device
, MakeInputIterator
, MakeOutputIterator
, Sync
);

/* ctor */
template <
  typename Device
, typename MakeInputIterator
, typename MakeOutputIterator
, typename Sync >
  data_model <
    Device, MakeInputIterator, MakeOutputIterator, Sync >
::data_model(
  Device _device
, MakeInputIterator _input_iter
, MakeOutputIterator _output_iter
, Sync _sync
)
: model <Device,Sync> (
    std::move(_device)
  , std::move(_sync) )
, input_model <Device, MakeInputIterator, Sync> (
    std::move(_device)
  , std::move(_input_iter)
  , std::move(_sync) )
, output_model <Device, MakeOutputIterator, Sync> (
    std::move(_device)
  , std::move(_output_iter)
  , std::move(_sync) )
{
}

template <
  typename Device
, typename MakeInputIterator
, typename MakeOutputIterator
, typename Sync >
data_model <Device,MakeInputIterator,MakeOutputIterator,Sync>
make_data_model (
  Device _device
, MakeInputIterator _in_iter
, MakeOutputIterator _out_iter
, Sync _sync
){
return
data_model <
  Device
, MakeInputIterator
, MakeOutputIterator
, Sync > (
  std::move(_device)
, std::move(_in_iter)
, std::move(_out_iter)
, std::move(_sync) );
}

} /* data_pattern */
#endif

