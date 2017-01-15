//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP
#define DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP

#include <functional>
#include <type_traits>
#include "output_rewrite_locale.hpp"

namespace data_pattern {

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
class output_rewrite_iterator;

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale>
make_output_rewrite_iterator (
  Writer &
, Check &
, model<Device> &
, Locale &
);

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
class output_rewrite_iterator {

std::reference_wrapper<Writer> writer;
std::reference_wrapper<Check> check;
model<Device> * mdl;
Locale * locale;

public:

typedef std::output_iterator_tag iterator_catagory;
typedef void value_type;
typedef void difference_type;
typedef void pointer;
typedef void reference;

/* ctor */
output_rewrite_iterator (
  Writer &
, Check &
, Locale &
, model<Device> &
);

/* ctor */
output_rewrite_iterator (
  Writer &
, Check &
, Locale &
);

/* ctor copy */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
) = default;

/* operator copy assignment */
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
) = default;

/* ctor move */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  &&
) = default;

/* operator move assignment */
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  &&
) = default;

/* dtor */
~output_rewrite_iterator () = default;

/* rewrite iterator assignment operator. */
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator = (
  T const &
);

output_rewrite_iterator &
operator ++ ();

output_rewrite_iterator &
operator ++ (int);

output_rewrite_iterator &
operator * ();

bool
operator == (
  output_rewrite_iterator const &
) const;

}; /* output rewrite iterator */

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
bool
operator != (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
, output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
);

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
  output_rewrite_iterator<T, Writer, Check, Device, Locale>
::output_rewrite_iterator (
  Writer & _writer
, Check & _check
, Locale & _locale
, model<Device> & _mdl
)
: writer (_writer)
, check (_check)
, mdl (& _mdl)
, locale (& _locale)
{}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
  output_rewrite_iterator<T, Writer, Check, Device, Locale>
::output_rewrite_iterator (
  Writer & _writer
, Check & _check
, Locale & _locale
)
: writer (_writer)
, check (_check)
, mdl (nullptr)
, locale (& _locale)
{}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
bool
operator != (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const & _lhs
, output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const & _rhs
){
return !(_lhs == _rhs);
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator = (
  T const & _var
){
this->writer(_var, *this->mdl, *this->locale);
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
bool
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator == (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const & _rhs
) const {
return this->check(*this->mdl, *this->locale);
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator ++ (){
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator ++ (int){
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale> &
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator * (){
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
output_rewrite_iterator <T, Writer, Check, Device, Locale>
make_output_rewrite_iterator (
  Writer & _writer
, Check & _check
, model<Device> & _mdl
, Locale & _locale
){
return
output_rewrite_iterator<T, Writer, Check, Device, Locale>
{_writer, _check, _locale, _mdl};
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
, output_rewriter_locale<Locale, Writer, Check> & _loc
)
-> output_rewrite_iterator <
  T
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
, Device
, Locale
>
{
return output_rewrite_iterator <
  T
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
, Device
, Locale
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
, output_rewriter_locale<Locale, Writer, Check> & _loc
)
-> output_rewrite_iterator <
  T
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
, Device
, Locale
>
{
return output_rewrite_iterator <
  T
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.writer))>::type
, typename std::remove_reference<decltype(typesystems::get<T>(_loc.check))>::type
, Device
, Locale
>
{get<T>(_loc.writer), get<T>(_loc.check), _loc.locale};
}

template <
  typename T
, typename Device
, typename Locale
, typename Writer
, typename Check
, typename Iter >
void
sync (
  model<Device> & _mdl
, output_rewriter_locale<Locale, Writer, Check> & _loc
, Iter &
){

}

} /* data_pattern */
#endif

