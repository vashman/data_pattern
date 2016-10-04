//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_MODEL_HPP
#define DATA_PATTERN_INPUT_MODEL_HPP

#include <type_traits>
#include "model.hpp"
#include "bits/map_type.hpp"

namespace data_pattern {

/* input model */
template <typename Device, typename GetIteratorMap>
class input_model;

template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap>
make_input_model (
  Device &&
, GetIteratorMap &&
);

template <
  typename T
, typename Device
, typename GetIteratorMap >
auto
get (
  input_model <Device, GetIteratorMap> & _mdl
)
-> decltype ( typesystems::get<T> (_mdl.iterator_map(_mdl)))
{
return typesystems::get<T> (_mdl.iterator_map(_mdl));
}

namespace bits {

struct end_of_placeholder {

bool operator == (
  end_of_placeholder const &
) const {
return false;
}

};

template <typename T, typename Model>
struct end_of_get {

static auto get_if (
  Model const & _mdl
)
-> decltype(get<T>(const_cast<Model&>(_mdl)))
{
return get<T>(const_cast<Model&>(_mdl));
}

};

template <typename Model>
struct end_of_get
<end_of_placeholder, Model> {

static end_of_placeholder get_if (
  Model const & _mdl
){
return end_of_placeholder();
}

};

} /* bits */

template <
  typename T
, typename Device
, typename GetIteratorMap >
bool
end_of_input (
  input_model <Device, GetIteratorMap> const & _mdl
){
  if (_mdl.state == model_state::inoperable) return true;

using mdl_t = typename std::remove_reference <
decltype (
  const_cast<input_model<Device,GetIteratorMap>&>(_mdl)
  .iterator_map (
    const_cast <input_model<Device,GetIteratorMap>&>(_mdl)
  )
)>::type;

return (
  bits::end_of_get <
    typename std::conditional< typesystems::type_map_has_type<end_tag<T>, mdl_t>::value
      ,T,bits::end_of_placeholder>::type
  , input_model <Device, GetIteratorMap>
  >::get_if (_mdl)
==
  bits::end_of_get <
    typename std::conditional< typesystems::type_map_has_type<end_tag<T>, mdl_t>::value
      ,end_tag<T>,bits::end_of_placeholder>::type
  , input_model <Device, GetIteratorMap>
  >::get_if (_mdl)
);
}

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, bool &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, signed short &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, unsigned short &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, signed int &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, unsigned int &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, signed long &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, unsigned long &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, float &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, double &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, long double &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, char &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, signed char &
);

/* input value */
template <typename Device, typename GetIteratorMap>
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> &
, unsigned char &
);

/* input model */
template <typename Device, typename GetIteratorMap>
struct input_model
: public virtual  model <Device>
{
GetIteratorMap iterator_map;

/* ctor */
input_model (
  Device &&
, GetIteratorMap &&
);

/* dtor */
virtual
~input_model() noexcept = default;

/* ctor move */
input_model (
  input_model<Device, GetIteratorMap> &&
) = default;

/* assignment operator move */
input_model <Device, GetIteratorMap> &
operator = (
  input_model<Device, GetIteratorMap> &&
) = default;

/* ctor copy */
input_model (
  input_model <Device, GetIteratorMap>
  const &
) = delete;

/* assignment operator copy */
input_model <Device, GetIteratorMap> &
operator = (
  input_model <Device, GetIteratorMap>
  const &
) = delete;

template <typename T>
class iterator {

typedef std::input_iterator_tag
  iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T* pointer;
typedef T& reference;

input_model <Device, GetIteratorMap>
* input_mdl;

T temp;

public:

explicit
iterator (
  input_model <Device, GetIteratorMap>
 & _mdl
)
: input_mdl (& _mdl)
, temp ()
{
sync(*(this->input_mdl));
*(this->input_mdl) >> this->temp;
}

explicit
iterator ()
: input_mdl (nullptr)
, temp ()
{}

iterator (iterator const &) = default;

iterator &
operator = (iterator const &) = default;

iterator (iterator &&) = default;

iterator &
operator = (iterator &&) = default;

~iterator () = default;

T &
operator * (){
return this->temp;
}

iterator *
operator -> (){
return &this->temp;
}

iterator
operator ++ (int){
sync(*(this->input_mdl));
return *this;
}

iterator &
operator ++ (){
sync(*(this->input_mdl));
return *this;
}

bool
operator == (
  iterator<T> const & _rhs
) const {
  if (_rhs.input_mdl == nullptr)
  return end_of_input<T>(*this->input_mdl);

return (
   end_of_input<T>(*(_rhs.input_mdl))
|| end_of_input<T>(*this->input_mdl)
);
}

bool
operator != (
  iterator<T> const _rhs
) const {
return !(_rhs == *this);
}

}; /*  iterator */
}; /* input model */

template <
  typename T
, typename Device
, typename GetIteratorMap >
  typename input_model <Device, GetIteratorMap>
:: template iterator<T>
make_input_iterator (
  input_model <Device, GetIteratorMap> &
);

template <
  typename T
, typename Device
, typename GetIteratorMap >
  typename input_model<Device, GetIteratorMap>
:: template iterator<T>
make_end_input_iterator (
  input_model <Device, GetIteratorMap> &
);

} /* data_pattern */
#include "bits/input_model.tcc"
#include "bits/string_data_model_shifts.hpp"
#endif

