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
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> & _mdl
, raw<T,Alloc> &
);

template <
  typename T
, typename Alloc
, typename Device
, typename GetIteratorMap >
input_model <Device, GetIteratorMap> &
operator >> (
  input_model <Device, GetIteratorMap> & _mdl
, raw<T,Alloc> & _data
){
auto && iter = get<raw<T,Alloc>>(_mdl);
_data = *iter;
++iter;
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
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> & _mdl
, raw<T,Alloc> const &
);

template <
  typename T
, typename Alloc
, typename Device
, typename GetIteratorMap >
output_model <Device, GetIteratorMap> &
operator << (
  output_model <Device, GetIteratorMap> & _mdl
, raw<T,Alloc> const & _data
){
auto && iter = get<raw<T,Alloc>>(_mdl);
*iter = _data;
++iter;
return _mdl;
}

} /* data_patten */
#endif
#endif
#endif

