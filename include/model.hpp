//

#ifndef DATA_PATTERN_MODEL_HPP
#define DATA_PATTERN_MODEL_HPP

#include <utility>

namespace data_pattern {

template <typename Device>
struct model;

enum class model_state {
  operable // Device is in good io state.
, inoperable // Device is inoperable, but io may contuinue.
};

template <typename T>
struct end_iterator_tag;

template <typename T>
struct sync_iterator_tag;

template <typename Device>
struct model {

Device device;
model_state state;

template <typename DeviceType>
model (
  DeviceType &&
);

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

virtual
~model() = default;

bool
is_operable () const;

}; /* model */

template <typename Device>
template <typename DeviceType>
model<Device>::model (
  DeviceType && _device
)
: device (std::forward<DeviceType>(_device))
, state (model_state::operable)
{}

template <typename Device>
bool
model<Device>::is_operable (
) const {
return model_state::operable == this->state;
}

} /* data pattern */
#endif

