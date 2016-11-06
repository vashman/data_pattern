#include <iostream>
#include "../include/stream_model.hpp"
#include "../include/rewrite_type.hpp"

using std::cout;
using std::cin;
using data_pattern::make_output_model;
using data_pattern::make_input_model;
using data_pattern::make_ostream_sync;
using data_pattern::make_istream_sync;
using data_pattern::rewrite_output;
using data_pattern::rewrite_input;

struct int_to_double {
template <typename TypeMap>
void
 operator()(
  int const & _i
, TypeMap & _map
){
using data_pattern::get;
auto && iter = get<double>(_map);
*iter = static_cast<double>(_i);
++iter;
}
};

struct double_to_int {

template <typename TypeMap>
int
operator ()(
  TypeMap & _map
){
using data_pattern::get;
auto && iter = get<double>(_map);
return static_cast<int>(*iter++);
}

};

int main (){

auto output (
  make_output_model
  (cout, make_ostream_sync <char, double>(cout))
);

output << 't' << 'e' << 's' << 't' << ' ' << 12.04;

output << ' ' << rewrite_output(1, int_to_double()) << ' ';

auto input (
  make_input_model
  (cin, make_istream_sync <char, double>(cin))
);

char temp;
int temp_int;

input >> temp >> rewrite_input(temp_int, double_to_int());
std::cout << temp << " " << temp_int;

auto oiter = make_output_rewrite_iterator <>(output);

return 0;
}
