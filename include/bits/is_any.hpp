//

#ifndef DATA_PATTERN_BITS_IS_ANY_HPP
#define DATA_PATTERN_BITS_IS_ANY_HPP

#include <type_traits>

namespace data_pattern {
namespace bits {

template<typename T, typename... Ts>
struct is_any : std::false_type {};

template<typename T, typename U>
struct is_any<T, U>
  : std::is_same<T, U> {};

template<typename T, typename U, typename... Ts>
struct is_any<T, U, Ts...>
    : std::integral_constant <
    bool
  , std::is_same<T,U>::value
|| is_any<T, Ts...>::value >{};

} /* bits */ } /* data_pattern */
#endif

