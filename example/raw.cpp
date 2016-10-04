#include "../include/raw.hpp"
#include <vector>

using data_pattern::raw;

int main (){
std::vector<unsigned char> vec {};
raw<> blob(vec.data(), vec.size());
raw<> zlob(blob);
blob = zlob;
raw<> temp;
return 0;
}

