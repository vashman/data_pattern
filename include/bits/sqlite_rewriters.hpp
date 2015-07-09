// rewriters for pod sqlite types

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_OWRITER_HPP
#define DATA_PATTERN_BITS_SQLITE_RW\
_SQLITE_OWRITER_HPP

#include <typesystems/owriter.hpp>
#include <typesystems/iwriter.hpp>
#include <string>
#include "../raw.hpp"

namespace data_pattern {
namespace bits {
namespace sqlite_rw {

template <typename T>
class type_writer
  : public typesystems::owriter<T>
  , public typesystems::iwriter<T> {
public:
  typedef typename typesystems
  ::owriter<T>::type type;

  typedef typename typesystems
  ::owriter<T>::value_type value_type;

  /* ctor */
  type_writer() = default;

private:
  /* do_put */
  virtual void
  do_put(
    value_type const &
  ,   typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::owriter_container const &
  ) const;

  /* do_get */
  virtual void
  do_get(
    value_type &
  ,   typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;

  /* do_empty */
  virtual bool
  do_empty(
      typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;
};
/*
template <>
class type_writer<std::string>
  : public typesystems::owriter<std::string>
  , public typesystems::iwriter<std::string> {
public:
  typedef typename typesystems
  ::owriter<std::string>::type type;

  typedef typename typesystems
  ::owriter<std::string>::value_type
  value_type;

  / * do_put * /
  virtual void
  do_put(
    value_type const & _value
  ,   typesystems
    ::typebuffer_container const & _buff
  ,   typesystems
    ::owriter_container const & _writer
  ) const {
    typesystems
  ::typebuffer<sqlite_statement>
  & buff = typesystems
  ::use_typebuffer<sqlite_statement>
  (_buff);

  auto & stmt = buff.back();
  stmt.bind(
    stmt.index++
  , _value.c_str()
  );
  }

  / * do_get * /
  virtual void
  do_get(
    value_type &
  ,   typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;

  / * do_empty * /
  virtual bool
  do_empty(
      typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;
};

template <>
class type_writer<raw>
  : public typesystems::owriter<raw>
  , public typesystems::iwriter<raw> {
public:
  typedef typename typesystems
  ::owriter<raw>::type type;

  typedef typename typesystems
  ::owriter<raw>::value_type value_type;

  / * do_put * /
  virtual void
  do_put(
    value_type const & _value
  ,   typesystems
    ::typebuffer_container const & _buff
  ,   typesystems
    ::owriter_container const & _writer
  ) const {
    typesystems
  ::typebuffer<sqlite_statement>
  & buff = typesystems
  ::use_typebuffer<sqlite_statement>
  (_buff);

  auto & stmt = buff.back();
  stmt.bind(
    stmt.index++
  , _value.ptr()
  , _value.size()
  );
  }

  / * do_get * /
  virtual void
  do_get(
    value_type &
  ,   typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;

  / * do_empty * /
  virtual bool
  do_empty(
      typesystems
    ::typebuffer_container const &
  ,   typesystems
    ::iwriter_container const &
  ) const;
};*/

/* do_put
  No need to check for type buffers
  since the assumption is sqlite always
  uses sqlite_statements internally.
*/
template <typename T>
void
type_writer<T>::do_put(
  value_type const & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::owriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
stmt.bind(stmt.index++, _value);
}

/* do_get */
template <typename T>
void
type_writer<T>::do_get(
  value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
_value = static_cast<T>(stmt);
}
/*
template <>
void
type_writer<std::string>::do_get(
  value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
_value = static_cast<std::string>(stmt);
}

template <>
void
type_writer<raw>::do_get(
  value_type & _value
,   typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
  typesystems
::typebuffer<sqlite_statement>
& buff = typesystems
::use_typebuffer<sqlite_statement>
(_buffer);

auto & stmt = buff.back();
_value = static_cast<raw>(stmt);
}*/

/* do_empty */
template <typename T>
bool
type_writer<T>::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return true;
}

/* do_empty */
/*template <>
bool
type_writer<std::string>::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return true;
}

/ * do_empty * /
template <>
bool
type_writer<raw>::do_empty(
    typesystems
  ::typebuffer_container const & _buffer
,   typesystems
  ::iwriter_container const & _writer
) const {
return true;
}*/

} /* sqlite_rw */
} /* bits */
} /* data_patten */
#endif
