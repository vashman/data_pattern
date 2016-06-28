//

//          Copyright Sundeep S. Sangha 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <memory>
#include <iterator>
#include "../include/input_model.hpp"

using std::cout;
using std::cin;
using std::istream_iterator;
using data_pattern::make_input_model;
using data_pattern::model_state;
using data_pattern::begin;

typedef std::shared_ptr<std::istream>
iptr_t;

typedef std::shared_ptr<std::ostream>
optr_t;

int main(){

auto imdl ( make_input_model (
  iptr_t (&cin, [](void*){} )

, [](iptr_t _device){
  return istream_iterator<char> (
    *_device.get() );
  }

, [](iptr_t _device, model_state & _state){
  char temp;
  cout << "\nenter z to exit.";
  *_device.get() >> temp;
    if (temp == 'z') _state = model_state::end;
  return ;
  }
));

auto first = begin(imdl);
auto last = end(imdl);

while (first != last){
cout << "\nThe input was: "
<< static_cast<char>(*first);
++first;
}

return 0;
}
