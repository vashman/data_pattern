//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_INPUT_REWRITE_ITERATOR_HPP
#define DATA_PATTERN_BITS_INPUT_REWRITE_ITERATOR_HPP

#include <functional>
#include <type_traits>
#include "input_rewrite_locale.hpp"

namespace data_pattern {

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
class input_rewrite_iterator;

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
class input_rewrite_iterator {

T temp;
model<Device> * mdl;
Locale * locale;
std::reference_wrapper<Writer> writer;
std::reference_wrapper<Check> check;

public:

typedef std::input_iterator_tag iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T * pointer;
typedef T & reference;

/* ctor */
input_rewrite_iterator (
  Writer &
, Check &
, Locale &
, model<Device> &
);

/* ctor */
input_rewrite_iterator (
  Writer &
, Check &
, Locale &
);

/* ctor copy */
input_rewrite_iterator (
  input_rewrite_iterator
  const &
) = default;

/* operator copy assignment */
input_rewrite_iterator &
operator = (
  input_rewrite_iterator
  const &
) = default;

/* ctor move */
input_rewrite_iterator (
  input_rewrite_iterator &&
) = default;

/* operator move assignment */
input_rewrite_iterator &
operator = (
  input_rewrite_iterator &&
) = default;

/* dtor */
~input_rewrite_iterator () = default;

input_rewrite_iterator &
operator ++ ();

input_rewrite_iterator
operator ++ (int);

T&
operator * ();

T*
operator -> ();

bool
operator == (
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const &
) const;

}; /* input rewrite iterator */

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
bool
operator != (
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const &
, input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const &
);

/* ctor */
template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
  input_rewrite_iterator<T, Device, Locale, Writer, Check>
::input_rewrite_iterator (
  Writer & _writer
, Check & _check
, Locale & _locale
, model<Device> & _mdl
)
: temp {}
, mdl (& _mdl)
, locale (& _locale)
, writer (_writer)
, check (_check)
{
  if (! this->check(*this->mdl, *this->locale))
  this->temp = this->writer(*this->mdl, *this->locale);
}

/* ctor */
template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
  input_rewrite_iterator<T, Device, Locale, Writer, Check>
::input_rewrite_iterator (
  Writer & _writer
, Check & _check
, Locale & _locale
)
: temp {}
, mdl (nullptr)
, locale (& _locale)
, writer (_writer)
, check (_check)
{}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
bool
operator != (
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const & _lhs
, input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const & _rhs
){
return !(_lhs == _rhs);
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
bool
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
::operator == (
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
  const & _rhs
) const {
  if (this->mdl == nullptr){
    if (_rhs.mdl == nullptr) return true;
  return _rhs.check(*_rhs.mdl, *_rhs.locale);
  }
return this->check(*this->mdl, *this->locale);
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
input_rewrite_iterator <T, Device, Locale, Writer, Check> &
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
::operator ++ (){
this->temp = this->writer(*this->mdl, *this->locale);
return *this;
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
input_rewrite_iterator <T, Device, Locale, Writer, Check>
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
::operator ++ (int){
auto temp_iter (*this);
this->temp = this->writer(*this->device, *this->local);
return temp_iter;
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
T&
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
::operator * (){
return this->temp;
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
T*
  input_rewrite_iterator <T, Device, Locale, Writer, Check>
::operator -> (){
return &this->temp;
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
auto
begin (
  model<Device> & _mdl
, input_rewriter_locale<Locale, Writer, Check> & _loc
)
-> input_rewrite_iterator <
  T
, Device
, Locale
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
>
{
return input_rewrite_iterator <
  T
, Device
, Locale
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
>{
  get<T>(_loc.writer), get<T>(_loc.check), _loc.locale, _mdl
};
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check >
auto
end (
  model<Device> & _mdl
, input_rewriter_locale<Locale, Writer, Check> & _loc
)
-> input_rewrite_iterator <
  T
, Device
, Locale
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
>
{
return input_rewrite_iterator <
  T
, Device
, Locale
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
>
{get<T>(_loc.writer), get<T>(_loc.check), _loc.locale};
}

} /* data_pattern */
#endif

