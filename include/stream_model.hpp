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

template <typename MapType, typename Stream>
struct stream_model_sync {

typedef typename Stream::char_type char_type;
typedef typename Stream::traits_type traits_type;

MapType map;

stream_model_sync (
  MapType _map
)
: map (_map)
{}

bool
sync (
  std::basic_istream<char_type, traits_type> & _stream
) const {
  if (0 == _stream.sync()) return true;
  else return false;
}

bool
sync (
  std::basic_ostream<char_type, traits_type> & _stream
) const {
  if (_stream.flush()) return true;
  else return false;
}

bool
sync (
  std::basic_iostream<char_type, traits_type> & _stream
) const {
  if (_stream.flush() && (0 == _stream.sync())) return true;
  else return false;
}

MapType &
operator ()(
  model <Stream &> & _mdl
){
  if (this->sync(_mdl.device))
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
return this->map;
}

/*MapType & no stream move ctor in this std lib.
operator ()(
  model <Stream> & _mdl
){
  if (this->sync(_mdl.device))
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
return this->map;
}*/

}; //

template <typename... Ts, typename Stream>
stream_model_sync <
  typesystems::type_map <
    std::tuple<std::ostream_iterator<Ts>...>, Ts... >
, Stream >
make_ostream_sync (
  Stream & _stream
){
return stream_model_sync <
  typesystems::type_map <
    std::tuple<std::ostream_iterator<Ts>...>, Ts... >
, Stream > (
  typesystems::make_type_map<Ts...>
  (std::make_tuple(std::ostream_iterator<Ts>(_stream)...))
);

}

template <typename... Ts, typename Stream>
stream_model_sync <
  typesystems::type_map <
    std::tuple<std::istream_iterator<Ts>...>, Ts... >
, Stream >
make_istream_sync (
  Stream & _stream
){
return stream_model_sync <
  typesystems::type_map <
    std::tuple<std::istream_iterator<Ts>...>, Ts... >
, Stream > (
  typesystems::make_type_map<Ts...>
  (std::make_tuple(std::istream_iterator<Ts>(_stream)...))
);

}

} /* data pattern */
#endif

