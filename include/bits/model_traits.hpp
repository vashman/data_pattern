//

//

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
  )
#if __cplusplus >= 201103L
    = default;
#else
   ;
#endif

private:
#if __cplusplus >= 201103L
  static_assert(std::is_base(Model, model)
   , "Data model does not have model base");
#endif
};

} /* data_pattern */
#endif
