#include <vector>
#include "../../include/cppdb.hpp"

using data_pattern::cppdb;

int main(){
cppdb instance<int, std::vector<int> >();

instance.add_type<float, std::vector<float> >();

return 0;
}
