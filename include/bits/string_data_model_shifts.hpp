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
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model<Device, GetIteratorMap> &
, std::basic_string<charT,allocator> &
);

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> & _mdl
, std::basic_string<charT,allocator> & _string
){
auto && iter = get<std::basic_string<charT,allocator> >
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
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model<Device, GetIteratorMap> &
, std::basic_string<charT,allocator>
  const &
);

template <
  typename charT
, typename allocator
, typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> & _mdl
, std::basic_string<charT,allocator> const & _string
){
auto && iter = get<std::basic_string<charT,allocator> >
(_mdl);

*iter = _string;
++iter;
return _mdl;
}

} /* data pattern */
#endif
#endif

