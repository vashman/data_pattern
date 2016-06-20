// Include to add <<>> operators

#ifdef DATA_PATTERN_INPUT_MODEL_HPP
#ifdef DATA_PATTERN_RAW_HPP

#ifndef DATA_PATTERN_RAW_INPUT_MODEL_HPP
#define DATA_PATTERN_RAW_INPUT_MODEL_HPP
namespace data_pattern {

template <
  typename T
, typename Alloc
, typename Device
, typename MakeInputIterator
, typename Sync >
input_model <Device,MakeInputIterator,Sync> &
operator >> (
  input_model <Device,MakeInputIterator,Sync> & _mdl
, raw_data<T,Alloc> &
);

template <
  typename T
, typename Alloc
, typename Device
, typename MakeInputIterator
, typename Sync >
input_model <Device,MakeInputIterator,Sync> &
operator >> (
  input_model <Device,MakeInputIterator,Sync> & _mdl
, raw_data<T,Alloc> & _data
){
_data =
*_mdl.input_iterator(_mdl.device)++;
return _mdl;
}
 
} /* data_patten */

#endif
#endif
#endif

#ifdef DATA_PATTERN_OUTPUT_MODEL_HPP
#ifdef DATA_PATTERN_RAW_HPP

#ifndef DATA_PATTERN_RAW_OUTPUT_MODEL_HPP
#define DATA_PATTERN_RAW_OUTPUT_MODEL_HPP

namespace data_pattern {

template <
  typename T
, typename Alloc
, typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <Device,MakeOutputIterator,Sync> &
operator << (
  output_model <Device,MakeOutputIterator,Sync> & _mdl
, raw_data<T,Alloc> const &
);

template <
  typename T
, typename Alloc
, typename Device
, typename MakeOutputIterator
, typename Sync >
output_model <Device,MakeOutputIterator,Sync> &
operator << (
  output_model <Device,MakeOutputIterator,Sync> & _mdl
, raw_data<T,Alloc> const & _data
){
*_mdl.output_iterator(_mdl.device)++
  = _data;
return _mdl;
}

} /* data_patten */
#endif
#endif
#endif

