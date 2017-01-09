#include <iostream>
#include "../include/model.hpp"
#include "../include/stream_model.hpp"
#include "../include/rewrite_type.hpp"

using std::cout;
using std::cin;
using data_pattern::model;
using data_pattern::make_ostream_locale;
using data_pattern::make_istream_locale;
using data_pattern::make_input_rewrite_iterator;

struct double_to_int {

template <typename Model, typename Locale>
int
operator ()(
  Model & _mdl
, Locale & _loc
){
using data_pattern::begin;

auto iter = begin<double>(_mdl.device, _loc);
return static_cast<int>(*iter++);
}

};

struct dtoi_check {
template <typename Model, typename Locale>
bool
operator ()(
  Model & _mdl
, Locale & _loc
){
using data_pattern::begin;
using data_pattern::end;

return begin<double>(_mdl.device, _loc)
    == end<double>(_mdl.device, _loc);
}
};

int main (){

model<std::ostream *> output (&cout);
model<std::istream *> input (&cin);
auto oloc = make_ostream_locale <char, double>(cout);
auto iloc = make_istream_locale <char, double>(cin);

auto iter = make_input_rewrite_iterator <int>(
  double_to_int{}, dtoi_check{}, input, iloc );

//chain (output, oloc) << "test" << ':' << ' ' << 12.04;

char temp;
int temp_int;

//input >> temp >> rewrite_input(temp_int, double_to_int());
//std::cout << temp << " " << temp_int;

return 0;
}
