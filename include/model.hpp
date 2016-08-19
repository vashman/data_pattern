//

#ifndef DATA_PATTERN_MODEL_HPP
#define DATA_PATTERN_MODEL_HPP

#include <utility>

namespace data_pattern {

template <
  typename Device, typename Sync >
struct model;

template <
  typename Device, typename Sync >
void
sync (
  model <Device, Sync> &
);

enum class model_state {
  good // Device is in good io state.
, end // Device is standing by at end of file.
};

template <
  typename Device, typename Sync >
struct model {
Device device;
Sync sync;
model_state state;

model (
  Device &&
, Sync &&
);

model (
  model<Device,Sync> const &
) = default;

model (
  model<Device,Sync> &&
) = default;

model<Device,Sync> &
operator = (
  model<Device,Sync> const &
) = default;

model<Device,Sync> &
operator = (
  model<Device,Sync> &&
) = default;

virtual
~model() = default;

}; /* model */

template <
  typename Device, typename Sync >
model<Device,Sync>::model (
  Device && _device
, Sync && _sync
)
: device (std::forward<Device>(_device))
, sync (std::forward<Sync>(_sync))
, state (model_state::good)
{}

template <
  typename Device, typename Sync >
void
sync (
  model <Device, Sync> & _mdl
){
_mdl.sync (_mdl.device, _mdl.state);
}

} /* data pattern */
#endif

