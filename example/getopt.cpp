//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/model.hpp"
#include "../include/getopt_iterator.hpp"

using data_pattern::make_getopt_locale;
using data_pattern::empty;
using data_pattern::program_option;
using data_pattern::model;
using data_pattern::read;

int main (int argc, char * argv[]){

model<char**> input_options {argv};
auto getopt_locale = make_getopt_locale("abcde:", argc);

  if (! input_options.is_operable()) return 1;

  if (empty<program_option>(input_options, getopt_locale))
  return 1;

auto j = read<program_option>(input_options, getopt_locale);

std::cout << "option is: " << j.get_option() << " ";
  if (j.has_arg())
  std::cout << "arg is: " << j.get_arg();

return 0;
}
