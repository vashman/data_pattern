//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <tuple>
#include <iterator>
#include <typesystems/type_map.hpp>
#include "../include/model.hpp"

using std::vector;
using data_pattern::model;
using data_pattern::model_state;

using data_pattern::end_iterator_tag;
using data_pattern::sync_iterator_tag;
using typesystems::make_type_map;

using data_pattern::read;
using data_pattern::write;
using data_pattern::empty;
using data_pattern::full;

int main (){

model<vector<int>> vec {vector<int>{4}};

auto vector_ilocale = make_type_map <
  int, end_iterator_tag<int>, sync_iterator_tag<int> >
( std::make_tuple (
  [](vector<int> & _vec){return begin(_vec);}
, [](vector<int> & _vec){return end(_vec);}
, [](
    model<vector<int>> & _mdl
  , vector<int>::iterator _iter
  ){
    if (_iter == end(_mdl.device))
    _mdl.state = model_state::inoperable;
    else
    _mdl.device.erase(_iter);
  }
));

auto vector_olocale = make_type_map <
  int, sync_iterator_tag<int> >
( std::make_tuple (
  [](vector<int> & _vec){return std::back_inserter(_vec);}
, [](
    model<vector<int>> & _mdl
  , std::back_insert_iterator<vector<int>> _iter
  ){}
));

  if (! empty<int>(vec, vector_ilocale)){
  int temp = read<int>(vec, vector_ilocale);
  std::cout << "input was: " << temp << std::endl;
  }

  if (! full<int>(vec, vector_olocale)){
  write(3, vec, vector_olocale);
  std::cout << "output was: " << vec.device[0] << std::endl;
  }

return 0;
}
