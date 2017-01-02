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
#include <typesystems/type_map.hpp>
#include "../include/model.hpp"

namespace data_pattern {

template <typename T, typename Stream>
struct isml {

std::istream_iterator<T> stream;

// call ctor once, so iterator only extracts first time.
isml (Stream & _stream) : stream (_stream) {}
~isml() = default;
isml(isml const &) = default;
isml& operator=(isml const &) = default;

std::istream_iterator<T>
operator () (
  Stream & _stream
){
return this->stream;
}

};

template <typename T, typename Stream>
std::istream_iterator<T>
ismel (
  Stream & _stream
){
return std::istream_iterator<T>();
}

template <typename T, typename Stream>
std::ostream_iterator<T>
osml (
  Stream & _stream
){
return std::ostream_iterator<T>(_stream);
}

template <typename T, typename Stream>
void
ismls (
  model<Stream&> & _mdl
, std::istream_iterator<T> _iter
){
  if (0 == _mdl.device.sync())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}

template <typename T, typename Stream>
void
osmls (
  model<Stream&> & _mdl
, std::ostream_iterator<T> _iter
){
  if (_mdl.device.flush())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}

template <typename... Ts, typename Stream>
auto
make_istream_locale (
  Stream & _stream
) -> decltype ( typesystems::make_type_map <
  Ts..., end_iterator_tag<Ts>..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (
    isml<Ts,Stream>{_stream}...
  , ismel<Ts,Stream>...
  , ismls<Ts,Stream>...
  )
)
){
return typesystems::make_type_map <
  Ts..., end_iterator_tag<Ts>..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (
    isml<Ts,Stream>{_stream}...
  , ismel<Ts,Stream>...
  , ismls<Ts,Stream>...
  )
);
}

template <typename... Ts, typename Stream>
auto
make_ostream_locale (
  Stream & _stream
) -> decltype ( typesystems::make_type_map <
  Ts..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (osml<Ts,Stream>..., osmls<Ts,Stream>...)
)
){
return typesystems::make_type_map <
  Ts..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (osml<Ts,Stream>..., osmls<Ts,Stream>...)
);
}

} /* data pattern */
#endif

