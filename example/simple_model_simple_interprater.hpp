#include "simple_interprater.hpp"
#include "simple_data_model.hpp"

template <>
class simple_store<simple_data_model>
                : public data_pattern::model_store<simple_data_model>{
};

template <>
class simple_traits<simple_data_model>
              : public data_pattern::model_traits<simple_data_model> {
public:
  static inline bool
  find(
    simple_data_model &
  , simple_store<simple_data_model> &
  ) const;

  static inline void
  add(
    simple_data_model &
  , simple_store<simple_data_model> &
  ) const;
};

template <>
bool
simple_tratis<simple_data_model>::find(
  simple_data_model & _mdl
, simple_store<simple_data_model> & _store
, int _var
) const {
return _mdl.find(_var);
}

template <>
void
simple_tratis<simple_data_model>::add(
  simple_data_model & _mdl
, simple_store<simple_data_model> & _store
, int _var
) const {
_mdl.add(_var);
}
