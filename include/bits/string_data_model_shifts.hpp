// Include to add <<>> operators

#ifdef DATA_PATTERN_INPUT_MODEL_HPP

#ifndef DATA_PATTERN_STRING_INPUT_MODEL\
_HPP
#define DATA_PATTERN_STRING_INPUT_MODEL\
_HPP

#include <string>

namespace data_pattern {

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model<
  Device, GetIteratorMap, Sync > &
, std::basic_string<charT,allocator> &
);

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap
, typename Sync >
input_model <
  Device, GetIteratorMap, Sync > &
operator >> (
  input_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, std::basic_string<charT,allocator>
  & _string
){
auto & iter = get<
  std::basic_string<charT,allocator> >
(_mdl);

_string = *iter;
++iter;
return _mdl;
}

} /* data_pattern */
#endif
#endif

#ifdef DATA_PATTERN_OUTPUT_MODEL_HPP

#ifndef DATA_PATTERN_STRING_OUTPUT\
_MODEL_HPP
#define DATA_PATTERN_STRING_OUTPUT\
_MODEL_HPP

#include <string>

namespace data_pattern {

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model<
    Device, GetIteratorMap, Sync > &
, std::basic_string<charT,allocator>
  const &
);

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap
, typename Sync >
output_model <
  Device, GetIteratorMap, Sync > &
operator << (
  output_model <
    Device, GetIteratorMap, Sync >
  & _mdl
, std::basic_string<charT,allocator>
  const & _string
){
auto & iter = get<
  std::basic_string<charT,allocator> >
(_mdl);

*iter = _string;
++iter;
return _mdl;
}

} /* data pattern */
#endif
#endif

