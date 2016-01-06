//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_ITERATOR_TCC
#define DATA_PATTERN_ITERATOR_TCC

namespace data_pattern {
/* input model iterator. */
template <
  typename T
, typename Distance = std::ptrdiff_t >
class iterator
: public std::iterator <
    std::input_iterator_tag
  , T
  , Distance
  , T const *
  , T const & >
{
public:

/* ctor end */
iterator (
  input_model<Buffer,MakeInputIter> &
, int
);

/* ctor */
iterator (
  input_model<Buffer,MakeInputIter> &
);

/* ctor copy */
iterator (
  iterator<T,Distance> const &
);

/* defrence */
T const &
operator * () const;

/**/
T const *
operator -> () const;

/* operator increment */
iterator<T,Distance> &
operator ++ ();

/* operator increment */
iterator<T,Distance> &
operator ++ (
  int
);

/* is_empty
Used by the iterator comparison
operators to check whether the is empty.
*/
bool
is_empty (
  iterator<T,Distance> const &
) const ;

private:

decltype(begin<T>(buffer)) iter;

}; /* iterator */

/* operator == */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
bool
operator == (
    typename
    input_model<Buffer,MakeInputIter>
  ::template iterator <T, Distance>
  const &
,   typename
    input_model<Buffer,MakeInputIter>
  ::template iterator <T, Distance>
  const &
);

/* operator != */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
bool
operator != (
    typename
    input_model<Buffer,MakeInputIter>
  ::template iterator <T, Distance>
  const &
,   typename
    input_model<Buffer,MakeInputIter>
  ::template iterator <T, Distance>
  const &
);

//// TCC
/* input_model::iterator end ctor */
/*template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::iterator (
  input_model<Buffer,MakeInputIter>
  & _mdl
, int
)
: iter (end<T>(_mdl.buffer)) {
}*/

/* input_model::iterator begin ctor */
/*template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::iterator (
  input_model<Buffer,MakeInputIter>
  & _mdl
)
: iter (begin<T>(_mdl.buffer)) {
}*/

/* input_model::iterator operator * */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
T const &
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::operator * (
) const {
return *this->iter;
}

/* input_model::iterator operator -> */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
T const *
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::operator -> (
) const {
return this->iter.operator->();
}

/* input_model::iterator operator == */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
bool
operator == (
    typename
    input_model<Buffer,MakeInputIter>
  ::template iterator<T,Distance>
  const & _lhs
,   typename
    input_model<Buffer,MakeInputIter>
  ::template iterator<T,Distance>
  const & _rhs
){
return _lhs.is_empty(_rhs);
}

/* input_model::iterator operator != */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
bool
operator != (
    typename
    input_model<Buffer,MakeInputIter>
  ::template iterator<T,Distance>
  const & _lhs
,   typename
    input_model<Buffer,MakeInputIter>
  ::template iterator<T,Distance>
  const & _rhs
){
return !(_lhs==_rhs);
}

/* input_model::iterator operator ++ */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance> &
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::operator ++ (
){
this->iter++;
return *this;
}

/* input_model::iterator operator ++ */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance> &
  typename
  input_model<Buffer,MakeInputIter>
::template iterator<T,Distance>
::operator ++ (
  int _value
){
//? call op with value
++this->iter;
return *this;
}

/* idata_model_iterator empty */
template <
  typename T
, typename Distance
, typename Buffer
, typename MakeInputIter >
bool
  input_model<Buffer,MakeInputIter>
::iterator<T,Distance>
::is_empty (
    input_model<Buffer,MakeInputIter>
  ::iterator<T,Distance> const & _iter
) const {
return (this->iter == _iter);
}

  ///////////////////////////////
  
/* idata_model_iterator ctor */
template <typename T, typename Distance>
idata_model_iterator<T,Distance>
::idata_model_iterator(
  idata_model_iterator<T,Distance> const
  & _iter
)
: mdl (
  const_cast<data_model *>(_iter.mdl)
) {
}/////////////////////////////////////



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
