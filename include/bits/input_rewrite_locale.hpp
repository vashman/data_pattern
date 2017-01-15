//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_INPUT_REWRITE_LOCALE_HPP
#define DATA_PATTERN_BITS_INPUT_REWRITE_LOCALE_HPP

namespace data_pattern {

template <typename Locale, typename Writer, typename Check>
struct input_rewriter_locale;

template <typename Locale, typename Writer, typename Check>
struct input_rewriter_locale {

input_rewriter_locale (
  Locale _loc
, Writer _writer
, Check _check
)
: locale (_loc)
, writer (_writer)
, check (_check)
{}

input_rewriter_locale (
  input_rewriter_locale const &
) = default;

input_rewriter_locale &
operator = (
  input_rewriter_locale const &
) = default;

input_rewriter_locale (
  input_rewriter_locale &&
) = default;

input_rewriter_locale & operator = (
  input_rewriter_locale &&
) = default;

~input_rewriter_locale() = default;

Locale locale;
Writer writer;
Check check;

}; /* rewrite locale */

template <typename Locale, typename Writer, typename Check>
input_rewriter_locale<Locale, Writer, Check>
make_input_rewrite_locale (
  Locale _loc
, Writer _writer
, Check _check
){
return input_rewriter_locale<Locale, Writer, Check>
{_loc, _writer, _check};
}

} /* data_pattern */
#endif

