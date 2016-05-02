#include <vector>
#include <iostream>
#include "../include/rewrite_type.hpp"

using namespace data_pattern;
using std::begin;
using std::end;
using std::cout;
using std::endl;

template <typename Iter>
class fout {
public:
  bool
  operator ()(int const &, Iter) {
  return true;
  }
};

template <typename Iter>
class fchar {
public:
  bool
  operator ()(char const & _var, Iter _out) {
  *_out = _var;
  ++_out;
  return true;
  }
};

template <typename Iter>
struct fin {
bool
operator ()(int & _var, Iter _begin, Iter _end){
_var = *_begin;
return true;
}

};

template <typename Iter>
struct fvalue {
bool
operator ()(double & _var, Iter _in, Iter _end){
double temp;
temp = static_cast<double>(*_in);
  if (_in == _end) return false;

_var = temp + static_cast<double>(*_in);
return true;
}

};

typedef std::vector<int>::iterator it;

struct make_iterator {
it
operator () (std::vector<int> & _vec){
return _vec.begin();
}
};

struct make_end_iterator {
it
operator () (std::vector<int> & _vec){
return _vec.end();
}
};

int main() {

std::vector<int> vec(4);

make_iterator mk;
orewrite_iterator <
  make_iterator, it, int, char >
oiter (
  mk, vec, fout<it>(), fchar<it>() );

auto oo = make_orewrite_iterator
  <int,char>(
  make_iterator()
, vec
, fout<it>()
, fchar<it>() );

irewrite_iterator <
  make_iterator, make_end_iterator
, it, int, double >
iiter (
  mk
, make_end_iterator()
, vec
, fin <it> ()
, fvalue <it> ()
);

auto ii = make_irewrite_iterator
  <int,double>(
  make_iterator()
, make_end_iterator()
, vec
, fin<it>()
, fvalue<it>() );

int a = 3;
char b = 'A'; 

oo = a;
oo = b;
oiter = a;
oiter = b;

a = 99;
b = 'b';
double c = 4.4;

cout << vec[0] << " : " << vec[1] << endl;

a = *ii;
c = *iiter;

cout << a << " : " << c << endl;

return 0;
}
