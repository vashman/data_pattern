//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITE_ITERATOR_TCC
#define TYPESYSTEMS_REWRITE_ITERATOR_TCC

namespace data_pattern {
/* ctor */
template <
  typename OutIterator
, typename InIterator, typename... Ts >
  rewrite_iterator <
  OutIterator,InIterator,Ts... >
::rewrite_iterator (
  orewrite_iterator<OutIterator,Ts...>
  _oiter
, irewrite_iterator<InIterator,Ts...>
  _iiter
)
: orewrite_iterator <OutIterator,Ts...>
  (_oiter)
, irewrite_iterator <InIterator,Ts...>
  (_iiter) {
}

/* rewriter iterator assignment
  operator. */
template <
  typename OutIterator
, typename InIterator, typename... Ts >
template <typename U>
rewrite_iterator <
  OutIterator,InIterator,Ts... > &
  rewrite_iterator <
    OutIterator,InIterator,Ts... >
::operator = (
  U const & _val
){
  orewrite_iterator <
    OutIterator, InIterator, Ts... >
::operator = (*this, _val);
return *this;
}

/* make rewrite iterator */
template <
  typename OutIterator
, typename InIterator, typename... Ts >
rewrite_iterator <
  OutIterator, InIterator, Ts... >
make_rewrite_iterator (
  orewrite_iterator<OutIterator,Ts...> _oiter
, irewrite_iterator<InIterator,Ts...> _iiter
){
return
rewrite_iterator <
  OutIterator, InIterator, Ts... >
  (_oiter,_iiter);
}

/* make rewrite iterator */
template <
  typename... Ts, typename Iterator>
rewrite_iterator<Iterator, Ts...>
make_rewrite_iterator (
  Iterator _iterator
, Ts... _ts
){
return
rewrite_iterator<Iterator, Ts...>
  (_iterator, _ts...);
}

} /* data_pattern */

#endif

