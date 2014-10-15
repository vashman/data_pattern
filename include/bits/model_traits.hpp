//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_MODEL_TRAITS_HPP
#define DATA_PATTERN_MODEL_TRAITS_HPP

#if __cplusplus >= 201103L
#include <type_traits>
#elif
#include <boost/type_traits>
#endif

namespace data_pattern{

template <typename Model>
class model_traits{
public:
  virtual
  ~model_traits(
  );

  /* true in derived class if model traits can be used on the Model. */
  inline static bool
  enabled();

private:
#if __cplusplus >= 201103L
  static_assert(std::is_base(Model, model)
   , "Data model does not have model base");
#endif
};

template <Model>
model_traits<Model>::~model_traits(
){
}

template <Model>
bool
model_traits<Model>::enabled(
){
return false;
}

} /* data_pattern */
#endif
