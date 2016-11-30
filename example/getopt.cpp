//

#include <iostream>
#include "../include/input_model.hpp"
#include "../include/getopt_iterator.hpp"

using data_pattern::make_getopt_type_map;
using data_pattern::empty;
using data_pattern::make_input_model;
using data_pattern::program_option;

int main (int argc, char * argv[]){

program_option j;
auto input_options = make_input_model (
  argv, make_getopt_type_map ("abcde:", argc) );

  if (! input_options.is_operable()) return 1;

  if (! empty<program_option>(input_options)){
  input_options >> j;
  std::cout << "option is: " << j.get_option() << " ";
    if (j.has_arg()) std::cout << "arg is: " << j.get_arg();
  }

return 0;
}
