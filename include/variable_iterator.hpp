// output iterator for normal variables.

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_VARIABLE_ITER_HPP
#define DATA_PATTERN_VARIABLE_ITER_HPP

#include <iterator>

namespace data_pattern {

/* variable iterator */
template <typename T>
class variable_iterator;

template <typename T>
class variant_iterator
{
}; /* variable iterator */

template <typename T>
bool
operator == (
  variable_iterator<T> const &
, variable_iterator<T> const &
);

/* variable iterator */
template <typename T>
class variable_iterator
: public std::iterator <
    std::input_iterator_tag
  , T >
{
T * var;

public:

explicit
variable_iterator (
  T & _var
)
: var (& _var) {
}

explicit
variable_iterator ()
: var (nullptr) {
}

variable_iterator<T> &
operator ++ (){
var = nullptr;
return *this;
}

variable_iterator<T> &
operator ++ (
  int
){
var = nullptr;
return *this;
}

T *
operator -> (){
return this->var;
}

T &
operator * (){
return *this->var;
}

friend bool
operator == <> (
  variable_iterator<T> const &
, variable_iterator<T> const &
);

}; /* variable iterator */

template <typename T>
bool
operator == (
  variable_iterator<T> const & _lhs
, variable_iterator<T> const & _rhs
){
return (
  (_lhs.var == nullptr)
&&
  (_rhs.var == nullptr)
);
}

template <typename T>
bool
operator != (
  variable_iterator<T> const & _lhs
, variable_iterator<T> const & _rhs
){
return !(_lhs == _rhs);
}

} /* data pattern */
#endif

