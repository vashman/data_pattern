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

fstream fs{"./testing.test", std::ios::out};
model<fstream&> file {fs};
model<std::istream&> input {cin};
auto ofloc = make_ostream_locale <int, double, char>(fs);
auto iloc = make_istream_locale <char>(cin);
auto oloc = make_ostream_locale <int, char>(cout);

chain(file, ofloc) << 99 << '+' << 1.1 << '=' << 100.1;

model<std::ostream&> output{cout};
chain(output, oloc) << 'g' << 'A' << 'b'
<< 44 << 44;

chain(output, oloc) << 'i' << 'n' << 'p' << 'u'
<< 't' << ' ' << 'w' << 'a' <<'s' <<':';

  if (! empty<char>(input, iloc) && input.is_operable()){
  char v = read<char>(input, iloc);
  write(v, output, oloc);
  } else {
  chain(output, oloc) << 'n' << 'o' << 'p' << 'e';
  }

return 0;
}
