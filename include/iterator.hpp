// model input iterator

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ITERATOR_HPP
#define DATA_PATTERN_ITERATOR_HPP

#include <iterator>
#include "data_model.hpp"

namespace data_pattern {

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

  /* operator assignment */
  odata_model_iterator<T> &
  operator=(
    T const &
  );

  /**/
  odata_model_iterator<T> &
  operator*(
  );

  /* operator increment */
  odata_model_iterator<T> &
  operator++(
  );

  /* operator increment */
  odata_model_iterator<T> &
  operator++(
    int
  );

  /* is_empty */
  bool
  is_empty(
  ) const;

private:
  /* data_model pointer */
  data_model * mdl;

  /* temp variable */
  T temp;
};

/* odata_model_iterator operator == */
template <typename T>
bool
operator==(
  odata_model_iterator<T> const &
, odata_model_iterator<T> const &
);

/* odata_model_iterator operator != */
template <typename T>
bool
operator!=(
  odata_model_iterator<T> const &
, odata_model_iterator<T> const &
);

} /* data_pattern */
#include "bits/iterator.tcc"
#endif
