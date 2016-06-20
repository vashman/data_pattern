// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_GETOPT_ITERATOR_HPP
#define DATA_PATTERN_GETOPT_ITERATOR_HPP

#include <unistd.h>
#include <string>
#include <iterator>

namespace data_pattern {

/* iterates overs the */
class getopt_iterator
: public std::iterator <
    char
  , std::input_iterator_tag > {

int count;
char opt;
char ** argv;
std::string opts;

void
get();

public:

getopt_iterator();

getopt_iterator(
  int _argc
, char ** _argv
, std::string
);

getopt_iterator (
  getopt_iterator const &
) = default;

getopt_iterator (
  getopt_iterator &&
) = default;

getopt_iterator &
operator = (
  getopt_iterator const &
) = default;

getopt_iterator &
operator = (
  getopt_iterator &&
) = default;

~getopt_iterator () = default;

getopt_iterator &
operator ++();

getopt_iterator
operator ++(int);

char
operator * ();

char *
operator -> ();

friend bool
operator == (
  getopt_iterator const &
, getopt_iterator const &
);
}; /* getopt iterator */

getopt_iterator
make_getopt_iterator (
  int 
, char **
, std::string
);

getopt_iterator
make_getopt_iterator ();

getopt_iterator
make_getopt_iterator (
  int _argc
, char ** _argv
, std::string _opts
){
return
getopt_iterator(_argc, _argv, _opts);
}

getopt_iterator
make_getopt_iterator (){
return getopt_iterator();
}

bool
operator == (
  getopt_iterator const &
, getopt_iterator const &
);

bool
operator != (
  getopt_iterator const &
, getopt_iterator const &
);

getopt_iterator::getopt_iterator (
  int _argc
, char ** _argv
, std::string _opts
)
: count (_argc)
, opt ()
, argv (_argv)
, opts (_opts)
{
this->get();
}

getopt_iterator::getopt_iterator ()
: count (0)
, opt (-1)
, argv (nullptr)
, opts ()
{
}

getopt_iterator
getopt_iterator::operator ++ (
  int
){
getopt_iterator temp (*this);
this->get();
return temp;
}

getopt_iterator &
getopt_iterator::operator ++ (
){
this->get();
return *this;
}

void
getopt_iterator::get(){
this->opt = getopt (
  this->count
, this->argv
, this->opts.c_str() );
}

char
getopt_iterator::operator * (){
return this->opt;
}

char *
getopt_iterator::operator -> (){
return &this->opt;
}

bool
operator == (
  getopt_iterator const & _lhs
, getopt_iterator const & _rhs
){
return (
  (_lhs.opt == -1) && (_rhs.opt == -1)
);
}

bool
operator != (
  getopt_iterator const & _lhs
, getopt_iterator const & _rhs
){
return !(_lhs==_rhs);
}

template <typename T>
bool
empty (
  char **
);

template <typename T>
bool
empty (
  char **
){
return false;
}

} /* data_pattern */
#endif

