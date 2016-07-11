//

#include <iostream>
#include <functional>
#include "../include/input_model.hpp"
#include "../include/getopt_iterator.hpp"

using data_pattern::getopt_iterator;
using data_pattern::make_getopt_iterator;
using data_pattern::make_input_model;
using data_pattern::model_state;

int main (int argc, char * argv[]){

char const * const ops = "abcde:";
getopt_iterator first;
getopt_iterator last (argc, argv, ops);

  if (first == last) {
  return 1;
  }
std::cout << *first;

// get opt model
auto iter ( make_getopt_iterator (
  argc, argv, ops) );

auto input ( make_input_model (
  argv
, [&](char ** _argv){ return iter; }
, [&](char ** _argv, model_state & _state){
    if (iter == make_getopt_iterator())
    _state = model_state::end;
  }
) );

auto start (begin(input))
, finish (end(input));

while (start != finish){
std::cout << "current option is: "
<< static_cast<char>(*start++);
}

return 0;
}
