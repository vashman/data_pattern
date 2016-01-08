#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "../include/input_model.hpp"
#include "../include/output_model.hpp"
#include "../include/data_model.hpp"

using std::back_inserter;
using std::vector;
using data_pattern::make_imodel;
using data_pattern::make_omodel;
using data_pattern::make_iomodel;

typedef int type; 

struct func {
vector<type>::iterator
operator () (vector<type> &  _vec) {
return _vec.begin();
}
};

struct func2 {
std::back_insert_iterator<vector<type>>
operator () (vector<type> & _vec) {
return back_inserter(_vec);
}
};

int main (){
  
auto input (
  make_imodel(
    vector<type>()
  , func ()
  ) );

auto output (
  make_omodel(
    vector<type>()
  , func2 ()
  ) );

auto io (
  make_iomodel (
    vector<type>()
  , func()
  , func2()
  )
);

auto
  iter (begin(input.buffer))
, eiter (end(input.buffer));

output << 4 << 3 << 2 << 1.1 << "strun";

return 0;
}
