// 

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/raw.hpp"
#include <vector>

using data_pattern::raw;

int main (){
Empty e;
std::vector<raw<>::data_type> vec {0, 1, 2};

raw<> temp(vec.data(), vec.size());
raw<> blob(vec);

return 0;
}

