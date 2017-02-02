// 

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/model.hpp"
#include <string>
#include <array>

using data_pattern::model;

int main (){

int i = 4;
model<int> mdl0;
model<int> mdl1 (i);
model<int> mdl2 (3);
model<int> mdl3 {5};
model<int> mdl4 = {5};
model<int> mdl5 = model<int>(4);
model<int> mdl6 = mdl5;
model<int> mdl7 {mdl5};

model<std::string> mdl8 ("test");
model<std::string> mdl9 {"test"};
model<std::string> mdl10 {'a', 'b'};

model<std::array<std::string, 2>> mdl11 {
  std::array<std::string, 2>
  {{ {"1"}, {"22"} }}
};

return 0;
}
