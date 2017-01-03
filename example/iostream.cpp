//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <fstream>
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using std::fstream;
using data_pattern::model;
using data_pattern::make_ostream_locale;
using data_pattern::make_istream_locale;
using data_pattern::empty;
using data_pattern::read;
using data_pattern::write;

int main (int argc, char *argv[]){

model<fstream> file {"./testing.test", std::ios::out};
model<std::istream*> input {&cin};
model<std::ostream*> output{&cout};

auto ofloc =
  make_ostream_locale <int, double, char>(file.device);
auto oloc = make_ostream_locale <int, char>(cout);

chain(file, ofloc) << 99 << '+' << 1.1 << '=' << 100.1;

chain(output, oloc) << 'g' << 'A' << 'b' << 44 << 44;

chain(output, oloc) << '\n' << 'i' << 'n' << 'p' << 'u'
<< 't' << ' ' << 'w' << 'a' <<'s' <<':';

//input iterator will block the output on creation of locale
auto iloc = make_istream_locale <char>(cin);
  if (! empty<char>(input, iloc) && input.is_operable()){
  char v = read<char>(input, iloc);
  write(v, output, oloc);
  } else {
  chain(output, oloc) << 'n' << 'o' << 'p' << 'e';
  }

return 0;
}
