#include <iostream>
#include <fstream>
#include <iterator>
//#include "../include/streambuf_model.hpp"
#include "../include/stream_model.hpp"

using std::cout;
using std::cin;
using std::fstream;
using std::ios;
using data_pattern::make_istream_model;
using data_pattern::make_ostream_model;

int main (int argc, char *argv[]){

fstream fstrm
  ("./testing.test", ios::out);

auto file (
  make_ostream_model<int, double, char>
  (fstrm)
);

//file.device << "test";
file.device << 99 << '+' << 1.1 << ' ' << '=' << 100.1;

auto output =
  make_ostream_model<char, int> (cout);

output << 'g' << 'A' << 'b' << 44 << 44;

auto input (
  make_istream_model<char> (cin)
);

char v;
input >> v;

output << 'i' << 'n' << 'p' << 'u'
<< 't' << ' ' << 'w' << 'a' <<'s'
<<':' << v;

return 0;
}
