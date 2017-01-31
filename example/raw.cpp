// 

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/raw.hpp"
#include "../include/raw_view.hpp"
#include <vector>

using data_pattern::raw;
using data_pattern::raw_view;

int main (){
std::vector<raw<>::data_type> vec {'0', '1', '2'};

raw<> temp(vec.data(), vec.size()); //ub
raw<> blob(vec);
raw<> str("hello", 5); // ub

raw<> t (str);
t = blob;
t = raw<>("11", 2);

raw_view v (temp);

bool b = (blob != str);

return 0;
}

