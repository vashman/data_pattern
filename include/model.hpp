//

#ifndef DATA_PATTERN_MODEL_HPP
#define DATA_PATTERN_MODEL_HPP

#include <utility>

namespace data_pattern {

template <typename Device>
struct model;

enum class model_state {
  good // Device is in good io state.
, end // Device is standing by at end of file.
, sync // ask the model to sync.
};

template <typename Device>
model<Device> &
sync (
 model <Device> &
);

template <typename Device>
model<Device> &
operator << (
  model<Device> &
, model<Device> & (*pf)(model<Device> &)
);

template <typename Device>
model<Device> &
operator >> (
  model<Device> &
, model<Device> & (*pf)(model<Device> &)
);

template <typename Device>
struct model {
Device device;
model_state state;

template <typename T>
model (
  T &&
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

}; /* model */

template <typename Device>
template <typename T>
model<Device>::model (
  T && _device
)
: device (std::forward<T>(_device))
, state (model_state::good)
{}

template <typename Device>
model<Device> &
sync (
  model<Device> & _mdl
){
_mdl.state = model_state::sync;
return _mdl;
}

template <typename Device>
model<Device> &
operator << (
  model<Device> & _mdl
, model<Device> & (*pf)(model<Device> &)
){
return pf(_mdl);
}

template <typename Device>
model<Device> &
operator >> (
  model<Device> & _mdl
, model<Device> & (*pf)(model<Device> &)
){
return pf(_mdl);
}

} /* data pattern */
#endif

