//

//          Copyright Sundeep S. Sangha 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "simple_data_model.hpp"
#include "../include/iterator.hpp"

using data_pattern::idata_model_iterator;
using data_pattern::odata_model_iterator;

int main(){
simple_data_model mdl;
//odata_model_iterator<int> oend;
idata_model_iterator<int> iend;

odata_model_iterator<int> obegin(mdl);
idata_model_iterator<int> ibegin(mdl);

int value = 44;
//obegin = value;

return 0;
}
