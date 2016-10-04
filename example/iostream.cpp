#include <iostream>
#include <fstream>
#include <iterator>
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using std::fstream;
using std::ios;
using data_pattern::make_output_model;
using data_pattern::make_input_model;
using data_pattern::make_ostream_sync;
using data_pattern::make_istream_sync;
using data_pattern::end_of_input;

int main (int argc, char *argv[]){

fstream fstrm ("./testing.test", ios::out);

auto file ( make_output_model (
  fstrm, make_ostream_sync <int, double, char>(fstrm) )
);

file << 99 << '+' << 1.1 << ' ' << '=' << 100.1;

auto output = make_output_model
  (cout, make_ostream_sync <int, char>(cout));

output << 'g' << 'A' << 'b' << 44 << 44;

auto input (
  make_input_model
  (cin, make_istream_sync <char>(cin))
);

output << 'i' << 'n' << 'p' << 'u'
<< 't' << ' ' << 'w' << 'a' <<'s'
<<':';

char v;
  if (! end_of_input <char>(input)){
  input >> v;
  output << v;
  } else {
  output << 'n' << 'o' << 'p' << 'e';
  }

return 0;
}
