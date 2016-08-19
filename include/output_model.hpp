//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_MODEL_HPP
#define DATA_PATTERN_OUTPUT_MODEL_HPP

#include "model.hpp"
#include "bits/map_type.hpp"

namespace data_pattern {

/* output model */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
class output_model;

template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
    Device, GetIteratorMap, Sync >
make_output_model (
  Device &&
, GetIteratorMap &&
, Sync &&
);

template <
  typename T
, typename Device
, typename GetIteratorMap
, typename Sync >
auto
get (
  output_model <
    Device, GetIteratorMap, Sync >
  & _mdl
)
-> decltype ( typesystems::get<T> (
  _mdl.iterator_map(_mdl.device)
  ))
{
return typesystems::get<T> (
  _mdl.iterator_map(_mdl.device)
);}

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
    Device, GetIteratorMap, Sync > &
operator << (
  output_model <
      Device, GetIteratorMap, Sync > &
, bool const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, signed short const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync> &
, unsigned short const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, signed int const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, unsigned int const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, signed long const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, unsigned long const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, float const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, double const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, long double const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, unsigned char const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, signed char const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync > &
, char const &
);

/* output model */
template <
  typename Device
, typename GetIteratorMap
, typename Sync >
struct output_model
: public virtual
  model <Device, Sync>
{

GetIteratorMap iterator_map;

/* dtor */
virtual
~output_model() noexcept = default;

/* ctor */
output_model (
  Device &&
, GetIteratorMap &&
, Sync &&
);

/* ctor move */
output_model (
  output_model <
    Device,GetIteratorMap,Sync > &&
) = default;

/* assignment operator move */
output_model <
  Device, GetIteratorMap, Sync > &
operator = (
  output_model <
    Device, GetIteratorMap, Sync > &&
) = default;

/* ctor copy */
output_model (
  output_model <
    Device, GetIteratorMap, Sync >
  const &
) = delete;

/* assignment operator copy */
output_model <
  Device, GetIteratorMap, Sync > &
operator = (
  output_model <
    Device, GetIteratorMap, Sync >
  const &
) = delete;

template <typename T>
class iterator {
typedef std::output_iterator_tag
  iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef void pointer;
typedef void reference;

output_model <
  Device, GetIteratorMap, Sync >
* output_mdl;

public:

explicit
iterator (
  output_model <
    Device, GetIteratorMap, Sync >
 & _mdl
)
: output_mdl (& _mdl)
{}

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
sync(*(this->output_mdl));
return *this;
}

iterator &
operator ++ (){
sync(*(this->output_mdl));
return *this;
}

void
operator = (
  T const & _var
){
*(this->output_mdl) << _var;
}

bool
operator == (
  iterator const &
) const {
return (
   this->input_mdl->state
== model_state::end
);
}

bool
operator != (
  iterator const & _lhs
) const {
return !(*this == _lhs);
}

}; /*  iterator */
}; /* odata_model */

template <
  typename T
, typename Device
, typename GetIteratorMap
, typename Sync >
  typename output_model <
    Device, GetIteratorMap, Sync >
:: template iterator<T>
make_output_iterator (
  output_model <
    Device, GetIteratorMap, Sync > &
);

} /* data_pattern */
#include "bits/output_model.tcc"
#endif

