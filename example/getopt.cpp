//

#include <iostream>
#include <functional>
#include "../include/input_model.hpp"
#include "../include/getopt_iterator.hpp"

using data_pattern::getopt_iterator;
using data_pattern::make_getopt_iterator;
using data_pattern::make_input_model;
using data_pattern::model_state;
using data_pattern::make_input_iterator;
using data_pattern::make_end_input_iterator;

int main (int argc, char * argv[]){

char const * const ops = "abcde:";
getopt_iterator first;
getopt_iterator last (argc, argv, ops);

  if (first == last) {
  return 1;
  }
std::cout << *first;

// get opt model
auto iter_map (
typesystems::make_type_map <char> (
  std::make_tuple (
  make_getopt_iterator (argc, argv, ops)
) ) );

auto input ( make_input_model (
  argv
, [&](char ** _argv)
  -> decltype (
  typesystems::make_type_map <char> (
    std::make_tuple (
    make_getopt_iterator (argc, argv, ops)
  ) )
  ) &
  { return iter_map; }
, [&](char ** _argv, model_state & _state){
  auto & t = typesystems::get<char>(iter_map);
    if (t == make_getopt_iterator())
    _state = model_state::end;
  }
) );

auto start =
  make_input_iterator<char>(input);
auto finish =
  make_end_input_iterator<char>(input);

while (start != finish){
std::cout << "current option is: "
<< static_cast<char>(*start++);
}

return 0;
}
