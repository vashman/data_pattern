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
  typename Device, typename InputMap, typename OutputMap >
struct data_model
: public
  input_model <Device, InputMap>
, output_model <Device, OutputMap>
{

/* dtor */
~data_model() = default;

/* ctor */
data_model (
  Device &&
, InputMap &&
, OutputMap &&
);

/* ctor move */
data_model (
  data_model <Device, InputMap, OutputMap> &&
) = default;

/* assignment operator move */
data_model <Device, InputMap, OutputMap> &
operator = (
  data_model <Device, InputMap, OutputMap> &&
) = default;

/* ctor copy */
data_model (
  data_model <Device, InputMap, OutputMap> const &
) = delete;

/* assignment operator copy */
data_model <Device, InputMap, OutputMap> &
operator = (
  data_model <Device, InputMap, OutputMap> const &
) = delete;

}; /* data model */

template <
  typename Device, typename InputMap, typename OutputMap >
data_model <Device, InputMap, OutputMap>
make_data_model (
  Device &&
, InputMap &&
, OutputMap &&
);

/* ctor */
template <
  typename Device, typename InputMap, typename OutputMap >
data_model <Device, InputMap, OutputMap>::data_model (
  Device && _device
, InputMap && _input_iter
, OutputMap && _output_iter
)
: model <Device> (std::forward<Device>(_device))
, input_model <Device, InputMap> (
    std::forward <Device>(_device)
  , std::forward <InputMap>(_input_iter)
  )
, output_model <Device, OutputMap> (
    std::forward <Device>(_device)
  , std::forward <OutputMap>(_output_iter)
  )
{
}

template <
  typename Device, typename InputMap, typename OutputMap >
data_model <Device, InputMap, OutputMap>
make_data_model (
  Device && _device
, InputMap && _in_iter
, OutputMap && _out_iter
){
return data_model <Device, InputMap, OutputMap> (
  std::forward<Device>(_device)
, std::forward<InputMap>(_in_iter)
, std::forward<OutputMap>(_out_iter)
);
}

} /* data_pattern */
#endif

