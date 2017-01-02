//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP
#define DATA_PATTERN_OUTPUT_REWRITE_ITERATOR_HPP

namespace data_pattern {

template <typename T, typename Writer, typename Model>
class output_rewrite_iterator {

T temp;
Writer writer;
Check check;
output_model<Device, Map> * mdl;

public:

/* ctor */
output_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Model, Check> const &
) = default;

/* operator copy assignment */
output_rewrite_iterator <T, Writer, Model, Check> &
operator = (
  output_rewrite_iterator <T, Writer, Model, Check> const &
) = default;

/* ctor move */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Model, Check> &&
) = default;

/* operator move assignment */
output_rewrite_iterator <T, Writer, Model, Check> &
operator = (
  output_rewrite_iterator <T, Writer, Model, Check> &&
) = default;

/* dtor */
~output_rewrite_iterator () = default;

/* rewrite iterator assignment operator. */
output_rewrite_iterator <T, Writer, Model, Check> &
operator = (
  T const &
);

output_rewrite_iterator <T, Writer, Model, Check> &
operator ++ ();

output_rewrite_iterator <T, Writer, Model, Check> &
operator ++ (int);

output_rewrite_iterator <T, Writer, Model, Check> &
operator * ();

}; /* output rewrite iterator */

template <
  typename T
, typename Writer
, typename Model
, typename Check >
output_rewrite_iterator <T, Writer, Model, Check> &
  output_rewrite_iterator <T, Writer, Model, Check>
::operator = (
  T const &
){

return *this;
}

template <
  typename T
, typename Writer
, typename Model
, typename Check >
output_rewrite_iterator <T, Writer, Model, Check> &
  output_rewrite_iterator <T, Writer, Model, Check>
::operator ++ (){
return *this;
}

template <
  typename T
, typename Writer
, typename Model
, typename Check >
output_rewrite_iterator <T, Writer, Model, Check> &
  output_rewrite_iterator <T, Writer, Model, Check>
::operator ++ (int){
return *this;
}

template <
  typename T
, typename Writer
, typename Model
, typename Check >
output_rewrite_iterator <T, Writer, Model, Check> &
  output_rewrite_iterator <T, Writer, Model, Check>
::operator * (){
return *this;
}

} /* data_pattern */
#endif
