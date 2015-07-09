#ifndef DATA_PATTERN_STRING_DATA_MODEL_SHIFTS_HPP
#define DATA_PATTERN_STRING_DATA_MODEL_SHIFTS_HPP

#include <string>

namespace data_pattern {

template <
  typename charT
, typename allocator
>
data_model &
operator<<(
  data_model &
, std::basic_string<charT,allocator>
  const &
);

template <
  typename charT
, typename allocator
>
data_model &
operator>>(
  data_model &
, std::basic_string<charT,allocator> &
);

template <
  typename charT
, typename allocator
>
data_model &
operator<<(
  data_model & _mdl
, std::basic_string<charT,allocator>
  const & _str
){
rewrite(_mdl,_str);
return _mdl;
}

template <
  typename charT
, typename allocator
>
data_model &
operator>>(
  data_model & _mdl
, std::basic_string<charT,allocator> &
  _str
){
rewrite(_mdl,_str);
return _mdl;
}

} /* data_pattern */
#endif
