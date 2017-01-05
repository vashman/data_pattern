//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_MODEL_HPP
#define DATA_PATTERN_BITS_MODEL_HPP

#include  <initializer_list>

namespace data_pattern {

enum class model_state {
  operable // Device is in good io state.
, inoperable // Device is inoperable
};

template <typename Device>
struct model {

Device device;
model_state state;

template <typename... Ts>
model (
  Ts...
);

template <typename T>
model (
  std::initializer_list<T>
);

explicit
operator Device ();

model (
  model<Device> const &
) = default;

model (
  model<Device> &&
) = default;

model<Device> &
operator = (
  model<Device> const &
) = default;

model<Device> &
operator = (
  model<Device> &&
) = default;

~model() = default;

bool
is_operable () const;

}; /* model */

template <typename Device, typename Locale>
struct chain_model {

model<Device> & mdl;
Locale & loc;

chain_model (
  model<Device> &
, Locale &
);

chain_model (
  chain_model<Device, Locale> const &
) = default;

chain_model (
  chain_model<Device, Locale> &&
) = default;

chain_model<Device, Locale> &
operator = (
  chain_model<Device, Locale> const &
) = default;

chain_model<Device, Locale> &
operator = (
  chain_model<Device, Locale> &&
) = default;

~chain_model() = default;

}; /* chain_model */

} /* data_pattern */
#endif
