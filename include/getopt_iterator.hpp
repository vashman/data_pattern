// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_GETOPT_ITERATOR_HPP
#define DATA_PATTERN_GETOPT_ITERATOR_HPP

#include <unistd.h>
#include <string>
#include "input_model.hpp"

namespace data_pattern {

typedef std::tuple <
  char** // argv
, int // local optind
, char // opt
, std::string // opts
, int // argc
, std::string // local optarg
, int > // argc count down to end
getopt_device;

namespace bits {
auto getopt_lam = 
  [](model<getopt_device> & _mdl){
  /* set getopt state to local state. */
  int global_optind = optind;
  optind = std::get<1>(_mdl.device);
  int rv = getopt (
      std::get<4>(_mdl.device)
    , std::get<0>(_mdl.device)
    , (std::get<3>(_mdl.device)).c_str()
  );
    if (rv == -1){
    _mdl.state = model_state::inoperable;
    } else {
    --std::get<6>(_mdl.device);
    std::get<2>(_mdl.device) =
      static_cast<char>(rv);
    std::get<1>(_mdl.device) = optind;
    }
  
  /* restore get opt state */
  optind = global_optind;
  std::get<5>(_mdl.device) = optarg;
  std::tuple <char*, std::string*> tup;

(
      & std::get<2>(_mdl.device)
    , & std::get<5>(_mdl.device)
    )


  return typesystems::make_type_map
  <char, std::string> (
    std::tuple <char*, std::string*>(
      & std::get<2>(_mdl.device)
    , & std::get<5>(_mdl.device)
    )
  );
  };
}

auto
make_getopt_model (
  char** _argv
, int _argc
, std::string _ops
)
-> input_model <getopt_device,decltype(bits::getopt_lam) &>
{
return make_input_model (
  getopt_device (_argv, optind, '?', _ops, _argc, "", _argc)
, bits::getopt_lam
);
}

} /* data_pattern */
#endif

