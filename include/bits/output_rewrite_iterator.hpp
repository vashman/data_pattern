//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP
#define DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP

namespace data_pattern {

template <
  typename T
, typename Writer
, typename Check
, typename Device
, typename Locale >
class output_rewrite_iterator {

Writer writer;
Check check;
model<Device> * mdl;
Locale * locale;

public:

typedef std::output_iterator_tag iterator_catagory;
typedef void value_type;
typedef void difference_type;
typedef void pointer;
typedef void reference;

/* ctor */
template <typename WriterType, typename CheckType>
output_rewrite_iterator (
  WriterType
, CheckType
, Locale &
, model<Device> &
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

output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator ++ ();

output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator ++ (int);

output_rewrite_iterator <T, Writer, Check, Device, Locale> &
operator * ();

bool
operator == (
  output_rewrite_iterator <T, Writer, Check, Device, Locale>
  const &
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
template <typename WriterType, typename CheckType>
  output_rewrite_iterator<T, Writer, Check, Device, Locale>
::output_rewrite_iterator (
  WriterType _writer
, CheckType _check
, Locale & _locale
, model<Device> & _mdl
)
: writer {_writer}
, check {_check}
, mdl {_mdl}
, locale {_locale}
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

} /* data_pattern */
#endif

