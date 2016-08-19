//

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_STREAMBUF_MODEL_HPP
#define DATA_PATTERN_STREAMBUF_MODEL_HPP

#include <iostream>
#include <tuple>
#include <iterator>
#include "../include/output_model.hpp"
#include "../include/input_model.hpp"

namespace data_pattern {

namespace bits {

template <
  typename CharT
, typename Traits
, typename... Ts >
struct ositer {

typedef typesystems::type_map <
  std::tuple < std::ostream_iterator
    <Ts, CharT, Traits>... >
, Ts...
> map_type;

map_type map;

ositer (
  std::basic_ostream<CharT, Traits>
  & _stream
) : map (
  typesystems::make_type_map<Ts...> (
    std::make_tuple ( std
      ::ostream_iterator
        <Ts, CharT, Traits >(_stream)...
    )
  )
){}

map_type &
operator ()(
  std::basic_ostream<CharT,Traits>
  const &
){
return this->map;
}

map_type &
operator ()(
  std::basic_ostream<CharT,Traits>
  const *
){
return this->map;
}

}; //

template <
  typename CharT
, typename Traits
, typename... Ts >
struct isiter {

typedef typesystems::type_map <
  std::tuple < std::istream_iterator
    <Ts, CharT, Traits>... >
, Ts...
> map_type;

map_type map;

isiter (
  std::basic_istream<CharT, Traits>
  & _stream
) : map (
  typesystems::make_type_map<Ts...> (
    std::make_tuple ( std
      ::istream_iterator
        <Ts, CharT, Traits >(_stream)...
    )
  )
){}

map_type &
operator ()(
  std::basic_istream<CharT,Traits>
  const &
){
return this->map;
}

map_type &
operator ()(
  std::basic_istream<CharT,Traits>
  const *
){
return this->map;
}

}; //

template <
  typename... Ts
, typename CharT
, typename Traits >
ositer <CharT,Traits,Ts...>
make_ositer (
  std::basic_ostream<CharT, Traits>
  & _stream
){
return
ositer<CharT,Traits,Ts...>(_stream);
}

template <
  typename... Ts
, typename CharT
, typename Traits >
isiter <CharT,Traits,Ts...>
make_isiter (
  std::basic_istream<CharT, Traits>
  & _stream
){
return
isiter<CharT,Traits,Ts...>(_stream);
}

template <
  typename CharT, typename Traits >
struct ostreamsync {

void
operator ()(
  std::basic_ostream<CharT,Traits>
  const & _stream
, model_state & _state
){
_stream.flush();
  if (_stream.good())
  _state = model_state::good;
  else
  _state = model_state::end;
}

void
operator ()(
  std::basic_ostream<CharT,Traits>
  const * _stream
, model_state & _state
){
this->operator ()(*_stream, _state);
}

}; // streamsync

template <
  typename CharT, typename Traits >
struct istreamsync {

void
operator ()(
  std::basic_istream<CharT,Traits>
  & _stream
, model_state & _state
){
_stream.flush();
  if (_stream.good())
  _state = model_state::good;
  else
  _state = model_state::end;
}

void
operator ()(
  std::basic_istream<CharT,Traits>
  * _stream
, model_state & _state
){
this->operator ()(*_stream, _state);
}

}; // streamsync

template <
  typename CharT, typename Traits >
ostreamsync<CharT,Traits>
make_ostreamsync(
  std::basic_ostream<CharT,Traits>
  & _stream
){
return ostreamsync<CharT,Traits>();
}

template <
  typename CharT, typename Traits >
istreamsync<CharT,Traits>
make_istreamsync(
  std::basic_istream<CharT,Traits>
  & _stream
){
return istreamsync<CharT,Traits>();
}

} /* bits */

template <
  typename... Ts, typename Ostream >
auto
make_ostream_model (
  Ostream && _ostream
)
-> decltype ( make_output_model (
   std::forward<Ostream> (_ostream)
  , bits::make_ositer<Ts...>(_ostream)
  , bits::make_ostreamsync(_ostream)
))
{
return make_output_model (
  std::forward<Ostream> (_ostream)
, bits::make_ositer<Ts...>(_ostream)
, bits::make_ostreamsync(_ostream) 
);
}

template <
  typename... Ts, typename Istream >
auto
make_istream_model (
  Istream && _istream
) -> decltype ( make_input_model (
    std::forward<Istream> (_istream)
  , bits::make_isiter<Ts...>(_istream)
  , bits::make_istreamsync(_istream)
))
{
return make_input_model (
  std::forward<Istream> (_istream)
, bits::make_isiter<Ts...>(_istream)
, bits::make_istreamsync(_istream) 
);
}

} /* data pattern */
#endif

