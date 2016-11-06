//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_REWRITE_TYPE_TCC
#define DATA_PATTERN_REWRITE_TYPE_TCC

namespace data_pattern {
namespace bits {

/* owrrite type */
template <typename T, typename Writer>
struct output_rewrite_type {
T const & var;
Writer writer;

explicit
output_rewrite_type (
  T const & _var
, Writer _writer
)
: var (_var)
, writer (_writer) {
}

}; /* owrite type */

/* owrite type << output_model */
template <
  typename T
, typename Writer
, typename Device
, typename Sync >
output_model <Device, Sync> &
operator << (
  output_model <Device, Sync> & _mdl
, output_rewrite_type <T, Writer> && _writer
){
_writer.writer (_writer.var, _mdl.iterator_map(_mdl));
return _mdl;
}

/* iwrite type */
template <typename T, typename Writer>
struct input_rewrite_type {

T & var;
Writer writer;

explicit
input_rewrite_type (
  T & _var
, Writer _writer
)
: var (_var)
, writer (_writer) {
}

}; /* iwrite type */

/* iwrite type >> input */
template <
  typename T
, typename Writer
, typename Device
, typename Sync >
input_model <Device, Sync> &
operator >> (
  input_model <Device, Sync> & _mdl
, input_rewrite_type <T, Writer> && _writer
){
_writer.var = _writer.writer(_mdl.iterator_map(_mdl));
return _mdl;
}

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::output_rewrite_type <T, Writer>
rewrite_output (
  T const & _var
, Writer _writer
){
return bits::output_rewrite_type <T, Writer>(_var, _writer);
}

/* rewrite input */
template <typename T, typename Writer>
bits::input_rewrite_type <T, Writer>
rewrite_input (
  T & _var
, Writer _writer
){
return bits::input_rewrite_type <T, Writer>(_var, _writer);
}

/*template <typename Device, typename SyncMap, typename WriterMap, typename... Ts>
class rewriter_model_sync {

SyncMap sync_map;
WriterMap writer_map;

rewriter_model_sync (
  SyncMap _sync
, WriterMap _map
)
: sync_map (_sync)
, writer_map (_map)
{}

WriterMap &
operator ()(
  model<Device> & _mdl
){
auto && map = this->sync_map(_mdl);
return typesystems::make_type_map <Ts...>
(std::make_tuple(rewrite_iterator<Ts, , decltype(map)>()...))
}

}; */

} /* data_pattern */
#endif

