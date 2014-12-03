//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_INTERPRATER_HPP
#define DATA_PATTERN_INTERPRATER_HPP

#include "data_model.hpp"

namespace data_pattern {

template <typename Model>
class interprater {
public:

#if __cplusplus >= 201103L
  interprater() = default;

  interprater(
    interprater &&
  ) = default;

  interprater &
  operator=(
    interprater &&
  ) = default;

  interprater(
    interprater const &
  ) = delete;

  interprater &
  operator=(
    interprater const &
  ) = delete;
#endif

  virtual
  ~interprater();

  void
  interpret(
    Model &
  , char *
  );

protected:
  virtual void
  do_interpret(
    Model &
  , char *
  ) = 0;
};

template <typename Model>
void
interprater<Model>::interpret(
  Model & _mdl
, char * _data
){
this->do_interpret(_mdl, _data);
}

} /* data_pattern */
#include "bits/model_traits.hpp"
#include "bits/model_store.hpp"
#endif
