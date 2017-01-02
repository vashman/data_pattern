//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_HPP
#define DATA_PATTERN_OUTPUT_MODEL_HPP

//#include <iterator>
#include "model.hpp"
#include "bits/map_type.hpp"

namespace data_pattern {

/* output model */
template <typename Device, typename Map>
class output_model;

template <typename Device, typename Map>
output_model <Device, Map>
make_output_model (
  Device &&
, Map &&
);

template <typename T, typename Device, typename Map>
auto
output_begin (
  output_model <Device, Map> & _mdl
)
-> decltype (typesystems::get<typename std::decay<T>::type> (_mdl.map)(_mdl.device))
{
using std::get;
using type = typename std::decay<T>::type;

return get<type> (_mdl.map)(_mdl.device);
}

template <typename T>
struct is_output_iterator :
std::is_same <
  std::output_iterator_tag
, typename std::iterator_traits<T>::iterator_category > 
{};

namespace bits {

template <typename T, typename Device, typename Map>
struct iterator_type : is_output_iterator <
  decltype(
    output_begin<T>(
      std::declval<output_model<Device, Map>&>() )
  )>
{};

} /* bits */

template <typename T, typename Device, typename Map>
auto
output_end (
  output_model <Device, Map> & _mdl
)
-> decltype (typesystems::get <
     end_iterator_tag<typename std::decay<T>::type> >
  (_mdl.map)(_mdl.device)
){
using typesystems::get;
using type = typename std::decay<T>::type;

return get<end_iterator_tag<type>>(_mdl.map)(_mdl.device);
}

template <typename T, typename Device, typename Map>
typename std::enable_if <
  ! bits::iterator_type <T, Device, Map>::value, bool >::type
full (
  output_model <Device, Map> & _mdl
);

template <typename T, typename Device, typename Map>
typename std::enable_if <
  bits::iterator_type <T, Device, Map>::value, bool >::type
full (
  output_model <Device, Map> const & _mdl
);

template <
  typename T, typename Device, typename Map, typename Iter >
void
sync (
  output_model<Device, Map> &
, Iter
);

template <typename T, typename Device, typename Map>
void
write (
  output_model <Device, Map> &
, T const &
);

/* output value */
template <typename T, typename Device, typename Map>
output_model <Device, Map> &
operator << (
  output_model <Device, Map> &
, T const &
);

/* output model */
template <typename Device, typename Map>
struct output_model
: public virtual model <Device>
{

Map map;

/* dtor */
virtual
~output_model() noexcept = default;

/* ctor */
output_model (
  Device &&
, Map &&
);

/* ctor move */
output_model (
  output_model <Device, Map> &&
) = default;

/* assignment operator move */
output_model <Device, Map> &
operator = (
  output_model <Device, Map> &&
) = default;

/* ctor copy */
output_model (
  output_model <Device, Map>
  const &
) = delete;

/* assignment operator copy */
output_model <Device, Map> &
operator = (
  output_model <Device, Map>
  const &
) = delete;

}; /* odata_model */

} /* data_pattern */
#include "bits/output_model.tcc"
#endif

