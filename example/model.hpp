#include <sstream>
#include <vector>
#include "../include/model.hpp"

using namespace std;
using data_pattern::model;

int main (int argc, char* argv[]){
model<ostream> m ((stringstream ()));

model<ostream,vector<int>> mm(
  (stringstream ()), vector<int>() );
return 0;
}
