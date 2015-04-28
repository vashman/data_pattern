// simple data_model to showcase feature extenisbility.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_EXAMPLE_SIMPLE_DATA_MODEL
#define DATA_PATTERN_EXAMPLE_SIMPLE_DATA_MODEL

#include <algorithm>
#include <vector>
#include "../include/data_model.hpp"

class simple_data_model
  : public data_pattern::data_model {
public:
  simple_data_model();

  bool
  find(
    int
  );

  void
  add(
    int
  );

  template <typename UnaryOperation>
  void
  transform(
    UnaryOperation
  );
};

/* ctor */
simple_data_model::simple_data_model(
){
typesystems::set_typebuffer<
  int
, std::vector<int>
>
(this->typesys);
}

bool
simple_data_model::find(
  int _value
){
auto & buff
  = typesystems::use_typebuffer<
      int
    , std::vector<int>
    >
    (this->typesys);
auto con = buff.get_container();

  if (con.end() == std::find(con.begin(), con.end(), _value)){
  return false;
  } else {
  return true;
  }
}

void
simple_data_model::add(
  int _value
){
auto & buff =
typesystems::use_typebuffer<int, std::vector<int> >(this->typesys);
buff.push(buff.next() + _value);
}

template <typename UnaryOperation>
void
simple_data_model::transform(
  UnaryOperation _unary_op
){
auto & buff =
typesystems::use_typebuffer<int, std::vector<int> >(this->typesys);
auto con = buff.get_container();

std::transform(con.begin(), con.end(), con.begin(), _unary_op);
}
#endif
