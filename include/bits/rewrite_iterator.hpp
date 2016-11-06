//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_ITERATOR_HPP
#define TYPESYSTEMS_REWRITE_ITERATOR_HPP

namespace data_pattern {

namespace bits {

/* rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
class rewrite_iterator {

T temp;
Writer * writer;
Check * check;
Model * model_ptr;

public:

/* ctor */
rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
rewrite_iterator (
  rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
rewrite_iterator <T, Writer, Check, Model> &
operator = (
  rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
rewrite_iterator (
  rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
rewrite_iterator <T, Writer, Check, Model> &
operator = (
  rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~rewrite_iterator () = default;

bool
operator == (
  rewrite_iterator <T, Writer, Check, Model> const &
) const;

bool
operator != (
  rewrite_iterator <T, Writer, Check, Model> const &
) const;

}; /* rewrite_iterator */

} /* bits */

template <
  typename T
, typename Writer
, typename Check
, typename Model >
struct input_rewrite_iterator
: public bits::rewrite_iterator <T, Writer, Check, Model> 
{

/* ctor */
input_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
input_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
input_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~input_rewrite_iterator () = default;

T &
operator * ();

T *
operator -> ();

input_rewrite_iterator <T, Writer, Check, Model> &
operator ++ ();

input_rewrite_iterator <T, Writer, Check, Model> &
operator ++ (int);

}; /* input rewrite iterator */

template <
  typename T
, typename Writer
, typename Check
, typename Model >
struct output_rewrite_iterator
: public bits::rewrite_iterator <T, Writer, Check, Model>
{

/* ctor */
output_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~output_rewrite_iterator () = default;

/* rewrite iterator assignment operator. */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  T const &
);

output_rewrite_iterator <T, Writer, Check, Model> &
operator ++ ();

output_rewrite_iterator <T, Writer, Check, Model> &
operator ++ (int);

output_rewrite_iterator <T, Writer, Check, Model> &
operator * ();

}; /* output rewrite model */

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
input_rewrite_iterator <T, Writer, Check, Model>
make_input_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model>
make_output_rewrite_iterator (
  Writer &
, Check &
, Model
  Writer &
, Check &
, Model &
);

/* ctor copy */
rewrite_iterator (
  rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
rewrite_iterator <T, Writer, Check, Model> &
operator = (
  rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
rewrite_iterator (
  rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
rewrite_iterator <T, Writer, Check, Model> &
operator = (
  rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~rewrite_iterator () = default;

bool
operator == (
  rewrite_iterator <T, Writer, Check, Model> const &
) const;

bool
operator != (
  rewrite_iterator <T, Writer, Check, Model> const &
) const;

}; /* rewrite_iterator */

} /* bits */

template <
  typename T
, typename Writer
, typename Check
, typename Model >
struct input_rewrite_iterator
: public bits::rewrite_iterator <T, Writer, Check, Model> 
{

/* ctor */
input_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
input_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
input_rewrite_iterator (
  input_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
input_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  input_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~input_rewrite_iterator () = default;

T &
operator * ();

T *
operator -> ();

input_rewrite_iterator <T, Writer, Check, Model> &
operator ++ ();

input_rewrite_iterator <T, Writer, Check, Model> &
operator ++ (int);

}; /* input rewrite iterator */

template <
  typename T
, typename Writer
, typename Check
, typename Model >
struct output_rewrite_iterator
: public bits::rewrite_iterator <T, Writer, Check, Model>
{

/* ctor */
output_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* ctor copy */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* operator copy assignment */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Model> const &
) = default;

/* ctor move */
output_rewrite_iterator (
  output_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* operator move assignment */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  output_rewrite_iterator <T, Writer, Check, Model> &&
) = default;

/* dtor */
~output_rewrite_iterator () = default;

/* rewrite iterator assignment operator. */
output_rewrite_iterator <T, Writer, Check, Model> &
operator = (
  T const &
);

output_rewrite_iterator <T, Writer, Check, Model> &
operator ++ ();

output_rewrite_iterator <T, Writer, Check, Model> &
operator ++ (int);

output_rewrite_iterator <T, Writer, Check, Model> &
operator * ();

}; /* output rewrite model */

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
input_rewrite_iterator <T, Writer, Check, Model>
make_input_rewrite_iterator (
  Writer &
, Check &
, Model &
);

/* make rewrite iterator */
template <
  typename T
, typename Writer
, typename Check
, typename Model >
output_rewrite_iterator <T, Writer, Check, Model>
make_output_rewrite_iterator (
  Writer &
, Check &
, Model &
);

} /*  data_pattern */
#include "./rewrite_iterator.tcc"
#endif

