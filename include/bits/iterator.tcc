//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ITERATOR_TCC
#define DATA_PATTERN_ITERATOR_TCC

namespace data_pattern {
/* idata_model_iterator ctor
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance>
::idata_model_iterator(
)
  : mdl (nullptr) {
}

/* idata_model_iterator ctor
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance>
::idata_model_iterator(
  data_model & _mdl
)
  : mdl (&_mdl) {
  if (!empty<T>(*(this->mdl))){
  *(this->mdl) >> this->temp;
  }
}

/* idata_model_iterator ctor
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance>
::idata_model_iterator(
  idata_model_iterator<T,Distance>
    const & _iter
)
  : mdl (&_iter.mdl) {
}

/* idata_model_iterator operator *
*/
template <typename T, typename Distance>
T const &
idata_model_iterator<T,Distance>
::operator*(
) const {
return (this->temp);
}

/* idata_model_iterator operator ->
*/
template <typename T, typename Distance>
T const *
idata_model_iterator<T,Distance>
::operator->(
) const {
return &(this->temp);
}

/* idata_model_iterator operator ==
*/
template <typename T, typename Distance>
bool
operator==(
  idata_model_iterator<T,Distance>
    const & _lhs
, idata_model_iterator<T,Distance>
    const & _rhs
){
return empty<T>(_lhs);
}

/* idata_model_iterator operator =!=
*/
template <typename T, typename Distance>
bool
operator!=(
  idata_model_iterator<T,Distance>
    const & _lhs
, idata_model_iterator<T,Distance>
    const & _rhs
){
return !(_lhs==_rhs);
}

/* idata_model_iterator operator ++
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance> &
idata_model_iterator<T,Distance>
::operator++(
){
*(this->mdl) >> this->temp;
return this;
}

/* idata_model_iterator operator ++
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance> &
idata_model_iterator<T,Distance>
::operator++(
  int _value
){
  while (_value > 0){
  this->operator++();
  --_value;
  }
return this;
}

/* odata_model_iterator ctor
*/
template <typename T>
odata_model_iterator<T>
::odata_model_iterator(
  data_model & _mdl
)
  : mdl (&_mdl) {
}

/* odata_model_iterator operator =
*/
template <typename T>
odata_model_iterator<T> &
odata_model_iterator<T>
::operator=(
  T const & _value
){
*(this->mdl) << _value;
return this;
}

/* odata_model_iterator operator ++
*/
template <typename T>
odata_model_iterator<T> &
odata_model_iterator<T>
::operator++(
){
return this;
}

/* odata_model_iterator operator ++
*/
template <typename T>
odata_model_iterator<T> &
odata_model_iterator<T>
::operator++(
  int _value
){
return this;
}

} /* data_pattern */
#endif
