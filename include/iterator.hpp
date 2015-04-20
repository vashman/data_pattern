// data_model input iterator

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ITERATOR_HPP
#define DATA_PATTERN_ITERATOR_HPP

#include <iterator>
#include "data_model.hpp"

namespace data_pattern {
/**/
template <
  typename T
, typename Distance = std::ptrdiff_t
>
class idata_model_iterator
  : public std::iterator <
      std::input_iterator_tag
    , T
    , Distance
    , T const *
    , T const &
    >
{
public:
  /* ctor end */
  idata_model_iterator(
  );

  /* ctor */
  idata_model_iterator(
    data_model &
  );

  /* ctor copy */
  idata_model_iterator(
    idata_model_iterator const &
  );

  /**/
  T const &
  operator*(
  ) const ;

  /**/
  T const *
  operator->(
  ) const ;

  /**/
  idata_model_iterator &
  operator++(
  );

  /**/
  idata_model_iterator
  operator++(
    int
  );
};

/**/
template <
  typename T
, typename Dist
>
bool
operator==(
  idata_model_iterator<T,Dist> const &
, idata_model_iterator<T,Dist> const &
);

/**/
template <
  typename T
, typename Dist
>
bool
operator!=(
  idata_model_iterator<T,Dist> const &
, idata_model_iterator<T,Dist> const &
);

/* output data_model iterator */
template <typename T>
class odata_model_iterator
  : public std::iterator <
      std::output_iterator_tag
    , void
    , void
    , void
    , void
    >
{
public:
  /* ctor */
  odata_model_iterator(
    data_model &
  );

  /**/
  idata_model_iterator &
  operator=(
    T const &
  );

  /**/
  idata_model_iterator &
  operator*(
  );

  /**/
  odata_model_iterator &
  operator++(
  );

  /**/
  odata_model_iterator
  operator++(
    int
  );
};

} /* data_pattern */
#include "bits/iterator.tcc"
#endif
