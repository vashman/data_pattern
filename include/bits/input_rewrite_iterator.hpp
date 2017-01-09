//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_INPUT_REWRITE_ITERATOR_HPP
#define DATA_PATTERN_INPUT_REWRITE_ITERATOR_HPP

namespace data_pattern {

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
class input_rewrite_iterator;

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
input_rewrite_iterator <T, Writer, Check, Device, Locale>
make_input_rewrite_iterator (
  Writer &&
, Check &&
, model<Device> &
, Locale &
);

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
class input_rewrite_iterator {

T temp;
Writer writer;
Check check;
model<Device> * mdl;
Locale * locale;

public:

typedef std::input_iterator_tag iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T * pointer;
typedef T & reference;

/* ctor */
template <typename WriterType, typename CheckType>
input_rewrite_iterator (
  WriterType
, CheckType
, Locale &
, model<Device> &
);

/* ctor copy */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
) = default;

/* operator copy assignment */
input_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
) = default;

/* ctor move */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  &&
) = default;

/* operator move assignment */
input_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  &&
) = default;

/* dtor */
~input_rewrite_iterator () = default;

input_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator ++ ();

input_rewrite_iterator <T, Writer, Check, Device, Locale>
operator ++ (int);

T&
operator * ();

T*
operator -> ();

bool
operator == (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
) const;

}; /* input rewrite iterator */

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
bool
operator != (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
, input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
);

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
template <typename WriterType, typename CheckType>
  input_rewrite_iterator<T, Writer, Check, Device, Locale>
::input_rewrite_iterator (
  WriterType _writer
, CheckType _check
, Locale & _locale
, model<Device> & _mdl
)
: temp {}
, writer (_writer)
, check (_check)
, mdl (&_mdl)
, locale (&_locale)
{
  if (! this->check(*this->mdl, *this->locale))
  this->temp = this->writer(*this->mdl, *this->locale);
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
bool
operator != (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const & _lhs
, input_rewrite_iterator <T, Writer, Check, Device, Locale>
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
bool
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator == (
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
  const & _rhs
) const {
  if (this->check == nullptr){
    if (_rhs.check == nullptr) return true;
  return _rhs.check(*_rhs,mdl, *_rhs.locale);
  }
return this->check(*this->mdl, *this->locale);
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
input_rewrite_iterator <T, Writer, Check, Device, Locale> &
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator ++ (){
this->temp = this->writer(*this->device, *this->locale);
return *this;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
input_rewrite_iterator <T, Writer, Check, Device, Locale>
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator ++ (int){
auto temp_iter (*this);
this->temp = this->writer(*this->device, *this->locale);
return temp_iter;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
T&
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator * (){
return this->temp;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
T*
  input_rewrite_iterator <T, Writer, Check, Device, Locale>
::operator -> (){
return &this->temp;
}

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
input_rewrite_iterator <T, Writer, Check, Device, Locale>
make_input_rewrite_iterator (
  Writer && _writer
, Check && _check
, model<Device> & _mdl
, Locale & _locale
){
return
input_rewrite_iterator<T, Writer, Check, Device, Locale>
{_writer, _check, _locale, _mdl};
}

} /* data_pattern */
#endif

