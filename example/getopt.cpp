//

#include <iostream>
#include "../include/input_model.hpp"
#include "../include/getopt_iterator.hpp"

using data_pattern::getopt_model_sync;
using data_pattern::end_of_input;
using data_pattern::program_option;

int main (int argc, char * argv[]){

program_option j;
auto i = make_input_model (
  argv, getopt_model_sync ("abcde:", argc) );

  if (end_of_input<char>(i) == false){
  i >> j;
  std::cout << "option is: " << j.get_option() << " ";
    if (j.has_arg()) std::cout << "arg is: " << j.get_arg();
  }

return 0;
}
