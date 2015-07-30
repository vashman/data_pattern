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
odata_model_iterator<int> oend;
idata_model_iterator<int> iend;

odata_model_iterator<int> obegin(mdl);
idata_model_iterator<int> ibegin(mdl);

idata_model_iterator<int> cei (iend);
odata_model_iterator<int> ceo (oend);

idata_model_iterator<int> ci (ibegin);
odata_model_iterator<int> co (obegin);

ci = ibegin;
co = obegin;
ceo = oend;
cei = iend;

int value = 44;

  if (obegin != oend) obegin = value;

  if (ibegin != iend) value = *ibegin;

return 0;
}
