#include "../include/model.hpp"

using data_pattern::model;
using data_pattern::sync;

int main (){

int i = 4;
model <int> mdll (i);
model <int> mdl(3);
sync (mdl);
sync (mdll);

return 0;
}
