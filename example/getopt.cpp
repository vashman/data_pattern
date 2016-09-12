//

#include <iostream>
#include <functional>
#include "../include/input_model.hpp"
#include "../include/getopt_iterator.hpp"

using typesystems::get;
using data_pattern::make_getopt_model;

int main (int argc, char * argv[]){

char const * const ops = "abcde:";

auto i = make_getopt_model (argv, argc,ops);
char j;
i >> j;

return 0;
}
