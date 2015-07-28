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

class string_writer
  : public typesystems::owriter<std::string>
  , public typesystems::iwriter<std::string> {
public:
  typedef typename typesystems
  ::owriter<std::string>::type type;

  typedef typename typesystems
  ::owriter<std::string>::value_type
  value_type;

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

class raw_writer
  : public typesystems::owriter<raw>
  , public typesystems::iwriter<raw> {
public:
  typedef typename typesystems
  ::owriter<raw>::type type;

  typedef typename typesystems
  ::owriter<raw>::value_type value_type;

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

} /* sqlite_rw */
} /* bits */
} /* data_patten */
#include "sqlite_rewriters.tcc"
#endif
