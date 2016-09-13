#include <iostream>
#include <fstream>
#include <iterator>
//#include "../include/streambuf_model.hpp"
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using std::fstream;
using std::ios;
using data_pattern::make_output_model;
using data_pattern::make_input_model;
using data_pattern::get_ostream_manager;
using data_pattern::get_stream_manager;
using data_pattern::get_istream_manager;
using data_pattern::sync;
using data_pattern::end_of_input;

int main (int argc, char *argv[]){

fstream fstrm
  ("./testing.test", ios::out);

auto file ( make_output_model (
  fstrm
, get_ostream_manager
  <int, double, char>(fstrm)
));

file.device << 99 << '+' << 1.1
  << ' ' << '=' << 100.1;
sync(file);

auto output = make_output_model (
  cout
, get_stream_manager <int, char>(
    cout
  , std::ostream_iterator<int>(cout, ",")
  , std::ostream_iterator<char>(cout)
  )
);

output << 'g' << 'A' << 'b' << 44 << 44;

auto input (
  make_input_model
  (cin, get_istream_manager <char>(cin))
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
