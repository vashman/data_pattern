#ifndef
#define

#include <../../include/interprater.hpp>

template <typename Model>
class simple_store : public data_pattern::model_store<Model> {

};

template <typename Model>
class simple_traits : public data_pattern::model_traits {
public:
  static inline bool
  find(
    Model &
  , simple_store<Model> &
  , int
  ) const;

  static inline void
  add(
    Model &
  , simple_store<Model> &
  , int
  ) const;
};

template <typename Model>
class simple_interprater : public data_pattern::interprater<Model> {
private:
  bool
  do_interprate(char const * const);

};

template <typename Model>
bool
simple_interprater<Model>::do_interprate(
  Model & _mdl
, char const * const _data
){
model_store<Model> store;
  if (std::char_traits<char>::length(_data) < 5){
  return false;
  }

  if (std::char_traits<char>::compare(_data, "find ", 5) == 0) {
  simple_traits<Model>::find(_mdl, store, var);
  }
   else if (std::char_traits<char>::compare(_data, "add ", 4) == 0) {
  simple_traits<Model>::add(_mdl, store, var);
  }
}

#endif
