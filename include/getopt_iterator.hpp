// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_GETOPT_MODEL_HPP
#define DATA_PATTERN_GETOPT_MODEL_HPP

#include <unistd.h>
#include <tuple>
#include <string>
#include "model.hpp"

namespace data_pattern {

struct program_option {

std::tuple <char, std::string> option;

bool
has_arg () const {
using std::get;

return ! get<1>(this->option).empty();
}

char &
get_option (){
return std::get<0>(this->option);
}

std::string &
get_arg (){
return std::get<1>(this->option);
}

program_option (
  char _opt
)
: option (_opt, "")
{}

program_option (
  char _opt
, std::string _str
)
: option (_opt, _str)
{}

program_option (program_option const &) = default;
program_option (program_option &&) = default;

program_option &
operator = (program_option const &) = default;

program_option &
operator = (program_option &&) = default;

~program_option() = default;
program_option() = default;

}; /* program option */

class getopt_iterator {

typedef int difference_type;
typedef program_option value_type;
typedef program_option* pointer;
typedef program_option& reference;
typedef std::input_iterator_tag iterator_catagory;

int local_optind;
std::string local_opts;
int local_argc;
program_option option;
char** local_argv;
int rv;

void
get_opt (){
using std::get;

/* set getopt state to local state. */
int global_optind = optind;
optind = this->local_optind;

this->rv =  getopt (
  this->local_argc
, this->local_argv
, this->local_opts.c_str() );

  if (this->rv != -1){
  // if a '?' character, then an error is found.
  get<0>(this->option.option) = static_cast<char>(rv);
    if (
       '?' != static_cast<char>(rv)
    && ':' != static_cast<char>(rv)
    && optarg != NULL
    ){
    get<1>(this->option.option) = optarg;
    }
  }
  
/* restore get opt state */
this->local_optind = optind;
optind = global_optind;
}

public:

getopt_iterator (
  char * _argv[]
, std::string _opts
, int _argc
)
: local_optind (optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
, local_argv (_argv)
, rv (-1)
{
this->get_opt();
}

getopt_iterator ()
: local_optind ()
, local_opts ()
, local_argc ()
, option ()
, local_argv (nullptr)
, rv (-1)
{}

getopt_iterator (getopt_iterator const &) = default;
getopt_iterator & operator = (getopt_iterator const &) = default;
getopt_iterator (getopt_iterator &&) = default;
getopt_iterator & operator =(getopt_iterator &&) = default;

getopt_iterator &
operator ++ (){
this->get_opt();
return *this;
}

getopt_iterator
operator ++ (int){
auto temp (*this);
this->get_opt();
return temp;
}

program_option &
operator * (){
return this->option;
}

program_option *
operator -> (){
return &this->option;
}

bool
operator == (
  getopt_iterator const & _rhs
) const {
return ((this->rv == -1) || (_rhs.rv == -1));
}

}; /* getopt iterator */

bool
operator != (
  getopt_iterator const & _lhs
, getopt_iterator const & _rhs
){
return !(_lhs == _rhs);
}

namespace bits {

struct a {

int argc;
std::string opts;

a (
  int _argc
, std::string _opts
)
: argc (_argc)
, opts (_opts)
{}

~a() = default;
a (a const &) = default;
a (a &&) = default;
a& operator= (a const &) = default;
a& operator= (a&&)= default;

getopt_iterator
operator ()(
  char** _argv
){
return getopt_iterator(_argv, this->opts, this->argc);
}

};

auto b = [](char** _argv){return getopt_iterator();};
auto c = [](
    model<char**> & _mdl
  , getopt_iterator _first
  , getopt_iterator _last
  ){
    if (_first != _last)
    _mdl.state = model_state::inoperable;
  };

} /* bits */

auto
make_getopt_type_map (
  std::string _opts
, int _argc
)
-> decltype ( typesystems::make_type_map <
  program_option
, end_iterator_tag<program_option>
, sync_iterator_tag<program_option>
  const program_option
, end_iterator_tag<const program_option>
, sync_iterator_tag<const program_option>
> (std::make_tuple (bits::a(_argc,_opts),bits::b,bits::c))
){
return typesystems::make_type_map <
  program_option
, end_iterator_tag<program_option>
, sync_iterator_tag<program_option>
  const program_option
, end_iterator_tag<const program_option>
, sync_iterator_tag<const program_option>
> (std::make_tuple (
  bits::a(_argc,_opts), bits::b, bits::c
, bits::
));
}

} /* data_pattern */
#endif

