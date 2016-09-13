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
, typename GetIteratorMap >
class output_model;

template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap>
make_output_model (
  Device &&
, GetIteratorMap &&
);

template <
  typename Device
, typename GetIteratorMap >
output_model<Device,GetIteratorMap> &
sync (
  output_model<Device,GetIteratorMap> &
);

template <
  typename Device
, typename GetIteratorMap >
output_model<Device,GetIteratorMap> &
sync (
  output_model<Device,GetIteratorMap> &
  _mdl
){
_mdl.state = model_state::sync;
_mdl.iterator_map(_mdl);
return _mdl;
}

template <
  typename T
, typename Device
, typename GetIteratorMap >
auto
get (
  output_model <Device, GetIteratorMap>
  & _mdl
)
-> decltype ( typesystems::get<T> (
  _mdl.iterator_map(_mdl)
  ))
{
return typesystems::get<T> (
  _mdl.iterator_map(_mdl)
);}

namespace bits {

struct end_of_oplaceholder {

bool operator == (
  end_of_oplaceholder const &
) const {
return false;
}

};

template <typename T, typename Model>
struct end_of_oget {

static auto get_if (
  Model const & _mdl
)
-> decltype (get<T>(const_cast<Model&>(_mdl)))
{
return get<T>(const_cast<Model&>(_mdl));
}

};

template <typename Model>
struct end_of_oget
<end_of_oplaceholder, Model> {

static end_of_oplaceholder get_if (
  Model const & _mdl
){
return end_of_oplaceholder();
}

};

} /* bits */

template <
  typename T
, typename Device
, typename GetIteratorMap >
bool
end_of_output (
  output_model <Device, GetIteratorMap>
  const & _mdl
){
using mdl_t = typename std
::remove_reference <
  decltype (
  const_cast<
    output_model<Device,GetIteratorMap>&
  >(_mdl)
    .iterator_map (
  const_cast <
    output_model<Device,GetIteratorMap>&
  >(_mdl))
  )
>::type;

return (
  bits::end_of_oget <
    typename std::conditional< typesystems::type_map_has_type<end_tag<T>, mdl_t>::value
      ,T,bits::end_of_oplaceholder>::type
  , output_model <Device, GetIteratorMap>
  >::get_if (_mdl)
==
  bits::end_of_oget <
    typename std::conditional< typesystems::type_map_has_type<end_tag<T>, mdl_t>::value
      ,end_tag<T>,bits::end_of_oplaceholder>::type
  , output_model <Device, GetIteratorMap>
  >::get_if (_mdl)
);
}

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, bool const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model<Device, GetIteratorMap> &
, signed short const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, unsigned short const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, signed int const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, unsigned int const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, signed long const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, unsigned long const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, float const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, double const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, long double const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, unsigned char const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, signed char const &
);

/* output value */
template <
  typename Device
, typename GetIteratorMap >
output_model <
  Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> &
, char const &
);

/* output model */
template <
  typename Device
, typename GetIteratorMap >
struct output_model
: public virtual model <Device>
{

GetIteratorMap iterator_map;

/* dtor */
virtual
~output_model() noexcept = default;

/* ctor */
output_model (
  Device &&
, GetIteratorMap &&
);

/* ctor move */
output_model (
  output_model <Device,GetIteratorMap> &&
) = default;

/* assignment operator move */
output_model <Device, GetIteratorMap> &
operator = (
  output_model <Device, GetIteratorMap> &&
) = default;

/* ctor copy */
output_model (
  output_model <Device, GetIteratorMap>
  const &
) = delete;

/* assignment operator copy */
output_model <Device, GetIteratorMap> &
operator = (
  output_model <Device, GetIteratorMap>
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

output_model <Device, GetIteratorMap>
* output_mdl;

public:

explicit
iterator (
  output_model <Device, GetIteratorMap>
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
  iterator const & _rhs
) const {
  if (_rhs.output_mdl == nullptr)
  return end_of_output<T>(*this->output_mdl);

return (
   end_of_output<T>(*(_rhs.output_mdl))
|| end_of_output<T>(*this->output_mdl)
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
, typename GetIteratorMap >
  typename output_model
  <Device, GetIteratorMap>
:: template iterator<T>
make_output_iterator (
  output_model <Device, GetIteratorMap> &
);

} /* data_pattern */
#include "bits/output_model.tcc"
#endif

