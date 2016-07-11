//

#include <vector>
#include <iostream>
#include <iterator>
#include "../include/rewrite_type.hpp"

using data_pattern::make_orewrite_iterator;
using data_pattern::make_irewrite_iterator;

typedef std::vector<int> con_t;
typedef std::vector<int>::iterator it_t;
typedef std::back_insert_iterator <
  std::vector<int> > in_t;

int main() {

std::vector<int> con;

auto oo (
  make_orewrite_iterator <int, char> (

  [](con_t & _con) {
  return std::back_inserter(_con);
  }

, con

, [](int const _var, in_t _iter) {
  return true;
  }

, [](char const _var, in_t _iter) {
  *_iter = _var;
  ++_iter;
  return true;
  }
));

auto ii (
  make_irewrite_iterator <int, double> (

  [](con_t & _con) {return begin(_con);}

, [](con_t & _con) {return end(_con); }

, con

,  [](int & _var, it_t _iter, it_t){
  _var = *_iter;
  return true;
  }

, [](double & _var, it_t _iter, it_t _end){
  double temp;
  temp = static_cast<double>(*_iter);
    if (_iter == _end) return false;
  _var = temp + static_cast<double>(*_iter);
  return true;
  }
));

int a = 3;
char b = 'A'; 

oo = a;
oo = b;

a = 99;
b = 'b';
double c = 4.4;

std::cout << "Values in con are: "
 << con[0] << " and " << con[1]
 << std::endl;

con.push_back(99);
a = *ii;
c = *ii;

std::cout << "int is: " << a
  << " and as a double: " << c
  << std::endl;

return 0;
}
