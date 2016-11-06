//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_STREAMBUF_MODEL_HPP
#define DATA_PATTERN_STREAMBUF_MODEL_HPP

#include <streambuf>
#include <tuple>
#include <iterator>
#include "../include/output_model.hpp"
#include "../include/input_model.hpp"

namespace data_pattern {

namespace bits {

template <typename CharT, typename Traits, typename Map>
struct streambuf_model_sync {

Map map;

streambuf_model_sync (
  std::basic_streambuf<CharT,Traits> & _buf
)
: map (
  typesystems::make_type_map<CharT> (
    std::make_tuple (std::ostreambuf_iterator <CharT,Traits>
    (& _buf)
    )
  )
){}

Map &
operator ()(
  std::basic_streambuf<CharT,Traits> const & _buf
){
  if (-1 == _buf.pubsync())
  _state = model_state::end;
  else
  _state = model_state::good;

return this->map;
}

}; //

template <
  typename CharT, typename Traits >
struct ibufiter {

typedef typesystems::type_map <
  std::tuple < std::istreambuf_iterator
    <CharT, Traits> >
, CharT
> map_type;

map_type map;

ibufiter (
  std::basic_streambuf<CharT,Traits>
  & _buf
)
: map (
  typesystems::make_type_map<CharT> (
    std::make_tuple (
      std::istreambuf_iterator
      <CharT, Traits>(& _buf)
    )
  )
) {}

Map &
operator ()(
  std::basic_streambuf<CharT,Traits>
  const & _buf
){
return this->map;
}
}; //

} // bits

template <typename StreamBuf>
auto
make_ostreambuf_model (
  StreamBuf _buf
)
-> decltype ( make_output_model (
    _buf
  , bits::make_obufiter(_buf)
  , bits::make_bufsync(_buf)
))
{
return make_output_model (
  _buf
, bits::make_obufiter(_buf)
, bits::make_bufsync(_buf) 
);
}

template <typename StreamBuf>
auto
make_istreambuf_model (
  StreamBuf _buf
) -> decltype ( make_input_model (
    _buf
  , bits::make_ibufiter(_buf)
  , bits::make_bufsync(_buf)
))
{
return make_input_model (
  _buf
, bits::make_ibufiter(_buf)
, bits::make_bufsync(_buf) 
);
}

} // data_pattern
#endif

