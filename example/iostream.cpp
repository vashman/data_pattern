#include <iostream>
#include <iterator>
#include "../include/output_model.hpp"
#include "../include/input_model.hpp"

using std::cout;
using std::ostreambuf_iterator;
using std::cin;
using std::istreambuf_iterator;
using data_pattern::make_input_model;
using data_pattern::make_output_model;

int main (int argc, char *argv[]){

auto output ( make_output_model (
  cout.rdbuf()
, [](std::basic_streambuf<char> * _buf){
    return ostreambuf_iterator<char>(_buf);
  }
, [](std::basic_streambuf<char> * _buf){
  _buf->pubsync();
  }
) );

output << 'g' << 'A' << 'b';

auto input ( make_input_model (
  cin.rdbuf()
, [](std::streambuf * _buf){
  return istreambuf_iterator<char>(_buf);
  }
, [](std::streambuf * _buf){
  _buf->pubsync();
  }
) );

char v;
input >> v;

output << 'i' << 'n' << 'p' << 'u'
<< 't' << ' ' << 'w' << 'a' <<'s'
<<':' << v;

return 0;
}
