#ifndef DATA_PATTHEN_EXAMPLE_SIMPLE_DATA_MODEL
#define DATA_PATTERN_EXAMPLE_SIMPLE_DATA_MODEL

#include <algorithm>
#include <vector>
#include "../../include/data_model.hpp"

class simple_data_model : public data_pattern::data_model {
public:
  simple_data_model();

  bool
  find(int);

  void
  add(int);

  template <typename UnaryOperation>
  void
  transform(UnaryOperation);
};

simple_data_model::simple_data_model(){
typesystems::set_typebuffer<int, std::vector<int> >(this->typesys);
}

void
simple_data_model::find(
  int _value
){
auto & buff =
typesystems::get_typebuffer<int, std::vector<int> >(this->typesys);
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
typesystems::get_typebuffer<int, std::vector<int> >(this->typesys);
buff.push(buff.next() + _value);
}

template <typename UnaryOperation>
void
simple_data_model::transform(
  UnarayOperation _unary_op
){
std::transform(con.begin(), con.end(), con.begin(), _unary_op);
}
#endif
