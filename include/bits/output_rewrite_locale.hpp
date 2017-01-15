//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_OUTPUT_REWRITE_LOCALE_HPP
#define DATA_PATTERN_BITS_OUTPUT_REWRITE_LOCALE_HPP

namespace data_pattern {

template <
  typename Device
, typename Locale
, typename Writer
, typename Check >
struct output_rewriter_locale;

template <
  typename Device
, typename Locale
, typename Writer
, typename Check >
struct output_rewriter_locale {

output_rewriter_locale (
  Locale _loc
, Writer _writer
, Check _check
)
: locale (_loc)
, writer (_writer)
, check (_check)
{}

output_rewriter_locale (
  output_rewriter_locale const &
) = default;

output_rewriter_locale &
operator = (
  output_rewriter_locale const &
) = default;

output_rewriter_locale (
  output_rewriter_locale &&
) = default;

output_rewriter_locale & operator = (
  output_rewriter_locale &&
) = default;

~output_rewriter_locale() = default;

Locale locale;
Writer writer;
Check check;

}; /* rewrite locale */

template <
  typename Device
, typename Locale
, typename Writer
, typename Check >
output_rewriter_locale<Device, Locale, Writer, Check>
make_output_rewrite_locale (
  Locale _loc
, Writer _writer
, Check _check
, Device &
){
return output_rewriter_locale<Device, Locale, Writer, Check>
{_loc, _writer, _check};
}

} /* data_pattern */
#endif

