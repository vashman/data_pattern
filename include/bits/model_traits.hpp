//

//

#ifndef DATABASE_MODEL_MODEL_TRAITS_HPP
#define DATABASE_MODEL_MODEL_TRAITS_HPP

#if __cplusplus >= 201103L
#include <type_traits>
#elif
// produce error
#endif

namespace database_model{

template <typename Model>
class model_traits{
public:
  virtual ~model_traits() = default;

private:
#if __cplusplus >= 201103L
  static_assert(std::is_base(Model, model)
   , "Data model does not have model base");
#endif
};

} /* database_model */
#endif
