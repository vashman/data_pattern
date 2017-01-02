//

//          Copyright Sundeep S. Sangha 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <vector>
#include "../include/data_model.hpp"
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using std::vector;
using data_pattern::make_input_model;
using data_pattern::make_output_model;
using data_pattern::make_ostream_map;
using data_pattern::make_istream_map;
using data_pattern::make_data_model;
using data_pattern::model_state;
using data_pattern::output_begin;
using data_pattern::output_end;
using data_pattern::input_begin;
using data_pattern::input_end;

int main(){

std::stringstream s1 {"abcdefg"};
auto input = make_input_model
  (s1, make_istream_map<char>(s1));

auto first = input_begin<char>(input);
auto last = input_end<char>(input);

while (first != last){
cout << "\nenter a character: ";
cout << "\nThe input was: " << *first;
++first;
}

auto omdl = make_output_model
   (cout, make_ostream_map<char,int>(cout));

std::vector<char> vec = {'A', 'E', 'I', 'O'};
std::copy (begin(vec), end(vec), output_begin<char>(omdl));

std::stringstream ss("12345");
auto io = make_data_model (
  ss
, make_istream_map<char,int>(ss)
, make_ostream_map<char,int>(ss)
);

std::copy (
  input_begin<int>(io)
, input_end<int>(io)
, output_begin<int>(omdl)
);

return 0;
}
