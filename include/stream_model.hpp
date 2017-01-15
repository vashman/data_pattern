//

//          Copyright Sundeep S. Sangha 2013 - 2017.
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

template <typename T, typename CharT, typename Traits>
struct isml {

std::istream_iterator<T> stream;

// call ctor once, so iterator only extracts first time.
isml (std::basic_istream<CharT,Traits> & _stream)
: stream (_stream) {}

~isml() = default;
isml(isml const &) = default;
isml& operator=(isml const &) = default;

template <typename Stream>
std::istream_iterator<T>
operator () (
  Stream & _stream
){
return this->stream;
}

std::istream_iterator<T>
operator () (
  std::basic_istream<CharT,Traits> * _stream
){
return this->stream;
}

};

template <typename T, typename CharT, typename Traits>
struct ismel {

template <typename Stream>
std::istream_iterator<T>
operator ()(
  Stream & _stream
){
return std::istream_iterator<T>();
}

std::istream_iterator<T>
operator ()(
  std::basic_istream<CharT,Traits> * _stream
){
return std::istream_iterator<T>();
}
};

template <typename T, typename CharT, typename Traits>
struct osml {

template <typename Stream>
std::ostream_iterator<T>
operator ()(
  Stream & _stream
){
return std::ostream_iterator<T>(_stream);
}

std::ostream_iterator<T>
operator ()(
  std::basic_ostream<CharT,Traits> * _stream
){
return std::ostream_iterator<T>(*_stream);
}
};

template <typename T, typename CharT, typename Traits>
struct ismls {

template <typename Stream>
void
operator ()(
  model<Stream> & _mdl
, std::istream_iterator<T> _iter
){
  if (0 == _mdl.device.sync())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}

void
operator ()(
  model<std::basic_istream<CharT,Traits>*> & _mdl
, std::istream_iterator<T> _iter
){
  if (0 == _mdl.device->sync())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}
};

template <typename T, typename CharT, typename Traits>
struct osmls{

template <typename Stream>
void
operator ()(
  model<Stream> & _mdl
, std::ostream_iterator<T> _iter
){
  if (_mdl.device.flush())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}

void
operator ()(
  model<std::basic_ostream<CharT,Traits>*> & _mdl
, std::ostream_iterator<T> _iter
){
  if (_mdl.device->flush())
  _mdl.state = model_state::operable;
  else
  _mdl.state = model_state::inoperable;
}
};

template <typename... Ts, typename CharT, typename Traits>
auto
make_istream_locale (
  std::basic_istream<CharT,Traits> & _stream
) -> decltype ( typesystems::make_type_map <
  Ts..., end_iterator_tag<Ts>..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (
    isml<Ts,CharT,Traits>{_stream}...
  , ismel<Ts,CharT,Traits>{}...
  , ismls<Ts,CharT,Traits>{}...
  )
)
){
return typesystems::make_type_map <
  Ts..., end_iterator_tag<Ts>..., sync_iterator_tag<Ts>... >
(
  std::make_tuple (
    isml<Ts,CharT,Traits>{_stream}...
  , ismel<Ts,CharT,Traits>{}...
  , ismls<Ts,CharT,Traits>{}...
  )
);
}

template <typename... Ts, typename CharT, typename Traits>
auto
make_ostream_locale (
  std::basic_ostream<CharT,Traits> & _stream
) -> decltype ( typesystems::make_type_map <Ts..., sync_iterator_tag<Ts>...>
(
  std::make_tuple (
    osml<Ts,CharT,Traits>{}...
  , osmls<Ts,CharT,Traits>{}...
  )
)
){
return typesystems::make_type_map <Ts..., sync_iterator_tag<Ts>...>
(
  std::make_tuple (
    osml<Ts,CharT,Traits>{}...
  , osmls<Ts,CharT,Traits>{}...
  )
);
}

} /* data pattern */
#endif

