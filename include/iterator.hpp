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
/* idata_model_iterator
Input iterator.
*/
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
  idata_model_iterator<T,Distance> &
  operator++(
  );

  /**/
  idata_model_iterator<T,Distance> &
  operator++(
    int
  );

  bool
  is_empty(
  ) const ;  

private:
  /* data_model pointer */
  data_model * mdl;

  /* temp variable */
  T temp;
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
, typename Distance
>
bool
operator!=(
  idata_model_iterator<T,Distance>
    const &
, idata_model_iterator<T,Distance>
    const &
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
  /* ctor end */
  odata_model_iterator(
  );

  /* ctor */
  odata_model_iterator(
    data_model &
  );

  /**/
  odata_model_iterator<T> &
  operator=(
    T const &
  );

  /**/
  odata_model_iterator<T> &
  operator*(
  );

  /**/
  odata_model_iterator<T> &
  operator++(
  );

  /**/
  odata_model_iterator<T> &
  operator++(
    int
  );

private:
  /* data_model pointer */
  data_model * mdl;

  /* temp variable */
  T temp;
};

/**/
template <typename T>
bool
operator!=(
  odata_model_iterator<T> const &
, odata_model_iterator<T> const &
);

} /* data_pattern */
#include "bits/iterator.tcc"
#endif
