// data model base to provide interface
// for io, and hold the type-system.

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_REWRITE_TYPE_HPP
#define DATA_PATTERN_REWRITE_TYPE_HPP

#include "data_model.hpp"
#include "bits/rewrite_iterator.hpp"

namespace data_pattern {

template <typename Map, typename... Ts>
class rewriter_map {

Map map;
typesystems::type_map<std::tuple<>, Ts...> writer_map;

};

input_rewrite_iterator<T, Writer, Check, Device, Map>
make_input_rewritr_iterator (
){
}

make_rewriter_map (
  Map && _map
, Tuple _writers
){
auto tup = make_tuple(m_iter<Ts,>...);
typesystems::type_map<_writers, Ts...> writer_map;
return rewriter_map <Map>(_map, writer_map);
}

} /* data_pattern */
#endif

