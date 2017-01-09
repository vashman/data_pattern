// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_REWRITE_TYPE_HPP
#define DATA_PATTERN_REWRITE_TYPE_HPP

#include "model.hpp"
#include "bits/input_rewrite_iterator.hpp"
//#include "bits/output_rewrite_iterator.hpp"

namespace data_pattern {

/*template <typename Locale, typename>
class input_rewriter_locale {

Locale locale;
TupleWriter writer;
TupleCheck check;

type_map <tuple<input_rewrite_iterator<Ts, W, C, Device, Locale>...>, Ts...>

};

template <typename T>
input_rewrite_iterator<T, Writer, Check, Device, Locale>
get (
  input_rewriter_locale<Locale, >
){

}

input_rewrite_iterator<T, Writer, Check, Device, Map>
make_input_rewritr_iterator (
){
}

template <typename... Ts, typename Locale, typename TupleWriter, typename TupleCheck>
make_rewriter_locale (
  Locale _locale
, TupleWriter _writers
, TupleCheck _checks
, model<Device> _mdl
){
auto tup = make_tuple(m_iter<Ts,>...);
typesystems::type_map<_writers, Ts...> writer_map;
return rewriter_map <Map>(_map, writer_map);
}*/

} /* data_pattern */
#endif

