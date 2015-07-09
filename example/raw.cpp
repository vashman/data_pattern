#include "../include/raw.hpp"
#include <string>

using data_pattern::raw;

int main (){
std::string str("sfdgdgdsgg");
const void * data = static_cast<const void*>(str.c_str());
raw b(data, str.size());
return 0;
}

