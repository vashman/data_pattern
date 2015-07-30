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
: mdl (& _mdl) {
  if (!empty<T>(_mdl)){
  *(this->mdl) >> this->temp;
  }
}

/* idata_model_iterator ctor
*/
template <typename T, typename Distance>
idata_model_iterator<T,Distance>
::idata_model_iterator(
  idata_model_iterator<T,Distance> const
  & _iter
)
: mdl (
  const_cast<data_model *>(_iter.mdl)
) {
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
return _lhs.is_empty();
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
return *this;
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
return *this;
}

/* idata_model_iterator empty */
template <typename T, typename Distance>
bool
idata_model_iterator<T,Distance>
::is_empty(
) const {
return empty<T>(*(this->mdl));
}

/* odata_model_iterator ctor */
template <typename T>
odata_model_iterator<T>
::odata_model_iterator(
)
  : mdl (nullptr) {
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
return *this;
}

/* odata_model_iterator operator ++
*/
template <typename T>
odata_model_iterator<T> &
odata_model_iterator<T>
::operator++(
){
return *this;
}

/* odata_model_iterator operator ++
*/
template <typename T>
odata_model_iterator<T> &
odata_model_iterator<T>
::operator++(
  int _value
){
return *this;
}

/* odata_model_iterator operator ==
*/
template <typename T>
bool
operator==(
  odata_model_iterator<T> const & _lhs
, odata_model_iterator<T> const & _rhs
){
return _lhs.is_empty();
}

/* odata_model_iterator operator !=
*/
template <typename T>
bool
operator!=(
  odata_model_iterator<T> const & _lhs
, odata_model_iterator<T> const & _rhs
){
return !_lhs.is_empty();
}

/* odata_model_iterator empty */
template <typename T>
bool
odata_model_iterator<T>
::is_empty(
) const {
return empty<T>(*(this->mdl));
}

} /* data_pattern */
#endif
