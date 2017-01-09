#include <iostream>
#include <string>
#include "../include/model.hpp"
#include "../include/stream_model.hpp"
#include "../include/rewrite_type.hpp"

using std::cout;
using std::cin;
using std::string;
using data_pattern::model;
using data_pattern::make_ostream_locale;
using data_pattern::make_istream_locale;
using data_pattern::make_input_rewrite_iterator;
using data_pattern::make_output_rewrite_iterator;

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

struct str_to_char {

template <typename Model, typename Locale, typename Cat>
void
func (
  std::string const _str
, Model & _mdl
, Locale & _loc
, Cat
){
using data_pattern::begin;
using data_pattern::end;

auto iter = begin<char>(_mdl.device, _loc);
auto b = begin(_str);
auto e = end(_str);
auto eiter = end<char>(_mdl.device, _loc);

while ((iter != eiter) && (b != e)){
*iter = *b;
++b;
}
}

template <typename Model, typename Locale>
void
func (
  std::string const _str
, Model & _mdl
, Locale & _loc
, std::output_iterator_tag
){
using data_pattern::begin;
using data_pattern::end;

auto iter = begin<char>(_mdl.device, _loc);
auto b = begin(_str);
auto e = end(_str);

while (b != e){
*iter = *b;
++b;
}
}

template <typename Model, typename Locale>
void
operator ()(
  std::string const _str
, Model & _mdl
, Locale & _loc
){
using data_pattern::begin;

this->func (
  _str
, _mdl
, _loc
, typename
  std::iterator_traits<decltype(begin<char>(_mdl.device, _loc))>::iterator_category()
);
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

struct stoc_check {
template <typename Model, typename Locale>
bool
operator ()(
  Model & _mdl
, Locale & _loc
){
using data_pattern::begin;
using data_pattern::end;

return begin<char>(_mdl.device, _loc)
    != end<char>(_mdl.device, _loc);
}
};

int main (){

model<std::ostream *> output (&cout);
model<std::istream *> input (&cin);
auto oloc = make_ostream_locale <char, double>(cout);
auto iloc = make_istream_locale <char, double>(cin);

auto iter = make_input_rewrite_iterator <int>(
  double_to_int{}, dtoi_check{}, input, iloc );

auto oiter = make_output_rewrite_iterator <std::string>(
  str_to_char{}, stoc_check{}, output, oloc );
auto k = std::string {"testing"};
*oiter = k;
//chain (output, oloc) << "test" << ':' << ' ' << 12.04;

char temp;
int temp_int;

//input >> temp >> rewrite_input(temp_int, double_to_int());
//std::cout << temp << " " << temp_int;

return 0;
}
