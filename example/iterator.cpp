//

//          Copyright Sundeep S. Sangha 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <sstream>
//#include <memory>
//#include <iterator>
#include <algorithm>
#include <vector>
#include "../include/model.hpp"
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using data_pattern::make_ostream_locale;
using data_pattern::make_istream_locale;
using std::copy;
using data_pattern::model;
using data_pattern::begin;
using data_pattern::end;

int main(){

model <std::stringstream> input ("abcdefg");
auto loc = make_istream_locale<char>(input.device);

auto first = begin<char>(input, loc);
auto last = end<char>(input, loc);

while (first != last){
cout << "\nenter a character: ";
cout << "\nThe input was: " << *first;
++first;
}

std::vector<char> vec = {'A', 'E', 'I', 'O'};
model<std::ostream*> output (&cout);
auto oloc = make_ostream_locale<char,int>(cout);

copy (
  begin(vec)
, end(vec)
, begin<char>(output.device, oloc)
);

model<std::stringstream> ss("12345");
auto ss_oloc = make_ostream_locale<char,int>(ss.device);
auto ss_iloc = make_istream_locale<char,int>(ss.device);

copy (
  begin<int>(ss.device, ss_iloc)
, end<int>(ss.device, ss_iloc)
, begin<int>(output.device, oloc) );

return 0;
}
