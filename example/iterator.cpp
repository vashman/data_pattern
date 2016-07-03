//

//          Copyright Sundeep S. Sangha 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iterator_decorator/cast_iterator.hpp>
#include "../include/data_model.hpp"

using std::cout;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using data_pattern::make_input_model;
using data_pattern::make_output_model;
using data_pattern::make_data_model;
using data_pattern::model_state;
using iterator_decorator::make_cast_iterator;

typedef std::shared_ptr<std::istream>
iptr_t;

typedef std::shared_ptr<std::ostream>
optr_t;

typedef std::shared_ptr<std::stringstream>
sptr_t;

int main(){

auto imdl ( make_input_model (
  iptr_t (&cin, [](void*){} )

, [](iptr_t _device){
  return istream_iterator<char> (
    *_device.get() );
  }

, [](iptr_t _device, model_state & _state){
  char temp;
  cout << "\nenter y to exit.";
  *_device.get() >> temp;
    if (temp == 'y') _state = model_state::end;
  }
));

auto first = begin(imdl);
auto last = end(imdl);

while (first != last){
cout << "\nenter a character: ";
char t = static_cast<char>(*first);
cout << "\nThe input was: " << t;
++first;
}

auto omdl ( make_output_model (
  optr_t (&cout, [](void*){})

, [](optr_t _device){
  return ostream_iterator<char> (
    *_device.get() );
  }

, [](optr_t _device, model_state & _state){
  _state = model_state::standby;
  *_device.get() << std::endl;
  }
));

std::vector<char> vec
  = {'A', 'E', 'I', 'O'};

std::copy (
  begin(vec)
, end (vec)
, make_output_iterator(omdl)
);

istream_iterator<char> it;

auto io ( make_data_model (
  sptr_t (new std::stringstream ("12345"))

, [&](sptr_t _strm){
    if (it == istream_iterator<char>())
    it = istream_iterator<char>(*(_strm.get()));
  return it;
  }

,[](sptr_t _strm){
  return ostream_iterator<char>(*(_strm.get()));
  }

, [&](sptr_t _strm, model_state & _state){
  _state = model_state::standby;
  ++it;
    if (it == istream_iterator<char>())
    _state = model_state::end; 
  } 
));

std::copy (
  make_cast_iterator<char>(begin(io))
, make_cast_iterator<char>(end(io))
, make_output_iterator(omdl)
);

cout << "\nvector model" << std::endl;
vector<int>::iterator vit;
bool f = false;
auto vecio ( make_data_model (
  vector<int> {1, 2, 3, 4, 5}

, [&](vector<int> & _vec){
    if (f == false){
    vit = begin(_vec);
    f = true;
    }
  return vit;
  }

, [&](vector<int> & _vec){
  f = false;
  return begin(_vec);
  }

, [&](vector<int> & _vec, model_state & _state){
  ++vit;
    if (vit == end(_vec)){
    _state = model_state::end;
   }
   if (f == false) {
   _state = model_state::standby;
   } 
  }
));

std::copy (
  make_cast_iterator<int>(begin(vecio))
, make_cast_iterator<int>(end(vecio))
, make_output_iterator(omdl)
);

return 0;
}
