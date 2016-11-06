// data model base to provide interface for io, and hold the
// type-system.

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
  typename Device, typename InputSync, typename OutputSync >
struct data_model
: public
  input_model <Device, InputSync>
, output_model <Device, OutputSync>
{

/* dtor */
~data_model() = default;

/* ctor */
data_model (
  Device &&
, InputSync &&
, OutputSync &&
);

/* ctor move */
data_model (
  data_model <Device, InputSync, OutputSync> &&
) = default;

/* assignment operator move */
data_model <Device, InputSync, OutputSync> &
operator = (
  data_model <Device, InputSync, OutputSync> &&
) = default;

/* ctor copy */
data_model (
  data_model <Device, InputSync, OutputSync> const &
) = delete;

/* assignment operator copy */
data_model <Device, InputSync, OutputSync> &
operator = (
  data_model <Device, InputSync, OutputSync> const &
) = delete;

}; /* data model */

template <
  typename Device, typename InputSync, typename OutputSync >
data_model <Device, InputSync, OutputSync>
make_data_model (
  Device
, InputSync
, OutputSync
);

/* ctor */
template <
  typename Device, typename InputSync, typename OutputSync >
data_model <Device, InputSync, OutputSync>::data_model (
  Device && _device
, InputSync && _input_iter
, OutputSync && _output_iter
)
: model <Device> (std::move(_device))
, input_model <Device, InputSync> (
    std::forward <Device>(_device)
  , std::forward <InputSync>(_input_iter)
  )
, output_model <Device, OutputSync> (
    std::forward <Device>(_device)
  , std::forward <OutputSync>(_output_iter)
  )
{
}

template <
  typename Device, typename InputSync, typename OutputSync >
data_model <Device, InputSync, OutputSync>
make_data_model (
  Device _device
, InputSync _in_iter
, OutputSync _out_iter
){
return data_model <Device, InputSync, OutputSync> (
  std::move(_device)
, std::move(_in_iter)
, std::move(_out_iter)
);
}

} /* data_pattern */
#endif

