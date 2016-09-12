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
  typename MapType
, typename Stream
, typename... Ts >
struct stream_iter {

MapType map;

stream_iter (
  Stream & _stream
, MapType _map
)
: map (_map)
{}

MapType &
operator ()(
  model <Stream const &> & _mdl
){
  if (_mdl.state == model_state::sync)
  _mdl.device.flush();
  if (_mdl.device.good())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
return this->map;
}

/*MapType &
operator ()(
  model <(Stream const *)> & _mdl
){
  if (_mdl.state == model_state::sync)
  _mdl.device.flush();
  if (_mdl.device.good())
  _mdl.state = model_state::good;
  else
  _mdl.state = model_state::end;
return this->map;
}*/

}; //

template <
  typename MapType
, typename Stream
, typename... Ts >
struct istream_iter {

MapType map;

istream_iter (
  Stream & _stream
, MapType _map
)
: map (_map)
{}

MapType &
operator ()(
  model <Stream const &> & _mdl
){
  if (_mdl.device.good())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
return this->map;
}

}; //

} /* bits */

template <
  typename... Ts, typename Stream >
auto
get_ostream_manager (
  Stream && _stream
)
-> bits::stream_iter <
    decltype (typesystems::make_type_map<Ts...>
    (std::make_tuple (std::ostream_iterator<Ts>(_stream)...))
    )
  , Stream
  , Ts... >
{
return bits::stream_iter <
  decltype (typesystems::make_type_map<Ts...>
  (std::make_tuple (std::ostream_iterator<Ts>(_stream)...))
  )
, Stream
, Ts... >
(
  _stream
, typesystems::make_type_map<Ts...>
  (std::make_tuple (std::ostream_iterator<Ts>(_stream)...))
);
}

template <
  typename... Ts, typename Stream >
auto
get_istream_manager (
  Stream && _stream
)
-> bits::istream_iter <
    decltype (typesystems::make_type_map<Ts...>
    (std::make_tuple (std::istream_iterator<Ts>(_stream)...))
    )
  , Stream
  , Ts... >
{
return bits::istream_iter <
  decltype (typesystems::make_type_map<Ts...>
  (std::make_tuple (std::istream_iterator<Ts>(_stream)...))
  )
, Stream
, Ts... >
(
  _stream
, typesystems::make_type_map<Ts...>
  (std::make_tuple (std::istream_iterator<Ts>(_stream)...))
);
}

template <
  typename... Ts
, typename Stream
, typename... Iterator >
auto
get_stream_manager (
  Stream && _stream
, Iterator... _iters
)
-> bits::stream_iter <
    decltype (typesystems::make_type_map<Ts...>
    (std::make_tuple (_iters...))
    )
  , Stream
  , Ts... >
{
return bits::stream_iter <
  decltype (typesystems::make_type_map<Ts...>
  (std::make_tuple (_iters...))
  )
, Stream
, Ts... >
(
  _stream
, typesystems::make_type_map<Ts...>
  (std::make_tuple (_iters...))
);
}

} /* data pattern */
#endif

