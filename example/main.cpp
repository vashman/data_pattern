#include <iostream>
#include "simple_data_model.hpp"

using data_pattern::empty;
using data_pattern::data_model;

void
print_int(
  data_model &
);

int main(){
simple_data_model sdm;

/* input a set of numbers */
sdm << 42 << 21 << 21 << 12 << 4;

/* print first number */
print_int(sdm);

/* if there is the number add 21 to the next number*/
  if (sdm.find(4)){
  sdm.add(21);
  }

print_int(sdm);
return 0;
}

void
print_int(
  data_model & _mdl
){
  if (empty<int>(_mdl)){
  int temp;
  _mdl >> temp;
  std::cout << "next number is: " << temp << std::endl;
  }
}
