// Include to add <<>> operators

#ifdef DATA_PATTERN_DATA_MODEL_HPP
#ifdef DATA_PATTERN_RAW_HPP

#ifndef DATA_PATTERN_RAW_DATA_MODEL_HPP
#define DATA_PATTERN_RAW_DATA_MODEL_HPP

namespace data_pattern {

template <typename T>
data_model &
operator<<(
  data_model &
, raw_data<T> const &
);

template <typename T>
data_model &
operator>>(
  data_model &
, raw_data<T> &
);

template <typename T>
data_model &
operator<<(
  data_model & _mdl
, raw_data<T> const & _data
){
rewrite(_mdl, _data);
return _mdl;
}

template <typename T>
data_model &
operator>>(
  data_model & _mdl
, raw_data<T> & _data
){
rewrite(_mdl, _data);
return _mdl;
}
 
} /* data_patten */
#endif
#endif
#endif
