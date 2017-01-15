//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <sstream>
#include <string>
#include <typesystems/type_map.hpp>
#include <tuple>
#include "../include/model.hpp"
#include "../include/stream_model.hpp"
#include "../include/rewrite_type.hpp"

using std::cout;
using std::stringstream;
using std::string;
using std::make_tuple;
using typesystems::make_type_map;
using data_pattern::model;
using data_pattern::make_ostream_locale;
using data_pattern::make_istream_locale;
using data_pattern::make_input_rewrite_locale;
using data_pattern::make_output_rewrite_locale;
using data_pattern::get;
using data_pattern::begin;

struct double_to_int {

template <typename Model, typename Locale>
int
operator ()(
  Model & _mdl
, Locale & _loc
){
using data_pattern::read;
auto var = read<double>(_mdl, _loc);
return static_cast<int>(var);
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
model<std::stringstream> input ("12.14 13.04");
auto oloc = make_ostream_locale<char, double>(cout);
auto iloc = make_istream_locale<char, double>(input.device);

auto irw_loc = make_input_rewrite_locale (
  iloc
, make_type_map<int>(make_tuple(double_to_int{}))
, make_type_map<int>(make_tuple(dtoi_check{}))
, input.device
);

auto orw_loc = make_output_rewrite_locale (
  oloc
, make_type_map<std::string>(make_tuple(str_to_char{}))
, make_type_map<std::string>(make_tuple(stoc_check{}))
, output.device
);

int tempi;
auto i = begin<int>(input, irw_loc);
//chain (input, irw_loc) >> tempi;

//*oiter = std::string {"testing"};
//chain (output, oloc) << "test" << ':' << ' ' << 12.04;

char temp;
int temp_int;

//input >> temp >> rewrite_input(temp_int, double_to_int());
//std::cout << temp << " " << temp_int;

return 0;
}
