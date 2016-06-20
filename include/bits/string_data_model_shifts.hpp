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
, typename MakeInputIterator
, typename Sync >
input_model <Device,MakeInputIterator,Sync> &
operator >> (
  input_model<Device,MakeInputIterator,Sync> &
, std::basic_string<charT,allocator> &
);

template <
  typename charT
, typename allocator
, typename Device
, typename MakeInputIterator
, typename Sync >
input_model <Device,MakeInputIterator,Sync> &
operator >> (
  input_model <
    Device, MakeInputIterator, Sync >
  & _mdl
, std::basic_string<charT,allocator>
  & _string
){
_string =
*_mdl.input_iterator(_mdl.device)++;
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
, typename MakeInputIterator
, typename Sync >
output_model <Device,MakeInputIterator,Sync> &
operator << (
  output_model<Device,MakeInputIterator,Sync> &
, std::basic_string<charT,allocator>
  const &
);

template <
  typename charT
, typename allocator
, typename Device
, typename MakeInputIterator
, typename Sync >
output_model <Device,MakeInputIterator,Sync> &
operator << (
  output_model <
    Device, MakeInputIterator, Sync >
  & _mdl
, std::basic_string<charT,allocator>
  const & _string
){
*_mdl.output_iterator(_mdl.device)++
  = _string;
return _mdl;
}

} /* data pattern */
#endif
#endif

