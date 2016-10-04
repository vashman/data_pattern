// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_GETOPT_ITERATOR_HPP
#define DATA_PATTERN_GETOPT_ITERATOR_HPP

#include <unistd.h>
#include <tuple>
#include <string>
#include "input_model.hpp"

namespace data_pattern {

struct program_option {

std::tuple <char, std::string> option;

bool
has_arg () const {
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

template <typename Device, typename DeviceSync>
input_model<Device, DeviceSync> &
operator >> (
  input_model<Device, DeviceSync> & _mdl
, program_option & _var
){
auto && iter = get<program_option>(_mdl);
_var = *iter;
++iter;
return _mdl;
}

class getopt_model_sync {

int local_optind;
std::string local_opts;
int local_argc;
program_option option;

public:

getopt_model_sync (
  std::string _opts
, int _argc
)
: local_optind (optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
{}

  typesystems
::type_map<std::tuple<program_option*>, program_option>
operator ()(model<char**&> & _mdl){
using std::get;

/* set getopt state to local state. */
int global_optind = optind;
optind = this->local_optind;

int rv = getopt (
  this->local_argc, _mdl.device, this->local_opts.c_str() );

  if (rv == -1){
  _mdl.state = model_state::inoperable;
  } else {
  // if a '?' character, and error found.
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

return typesystems::make_type_map <program_option> (
  std::tuple <program_option*> (& this->option) );
}

}; /* getopt_model_sync */

} /* data_pattern */
#endif

