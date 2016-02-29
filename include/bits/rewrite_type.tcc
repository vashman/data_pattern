//

#ifndef
#define

namespace data_pattern {
namespace bits {

template <
  typename Iter, typename Writer >
struct owrite_type {
Iter buffer_begin, buffer_end;
Writer writer;

explicit
owrite_type (
  Iter _begin
, Iter _end
, Writer _writer
)
: buffer_begin (_begin)
, buffer_end (_end)
, writer (_writer) {
}

}; /* owrite type */

template <
  typename Iter
, typename Writer
, typename Buffer
, typename MakeIter >
output_model<Buffer,Makeiter> &
operator << (
  output_model & _mdl
, owrite_type<Iter,Writer> & _writer
){
_writer.writer (
  _writer.buffer_begin
, _writer.buffer_end
, _mdl.output_iterator(_mdl.buffer)
);
}

template <typename Iter>
input_model<Buffer,MakeIter> &
operator >> (
  input_model<Buffer,MakeIter> & _mdl
, iwrite_type<Buffer,Writer> & _writer
){
_writer.writer (
  _mdl.input_iterator(_mdl.buffer)
, _mdl.input_iterator(_mdl.buffer)
, _writer.output_iter
);
}

template <typename T>
class output_iterator {
T * var;

public:

explicit
output_iterator (
  T & _var
)
: var (& _var) {
}

output_iterator<T> &
operator ++ (
){
return *this;
}

output_iterator<T> &
operator ++ (
  int
){
return *this;
}

T *
operator -> (){
return this->var;
}

T &
operator * (){
return *this->var;
}

};

} /* bits */

/* rewrite output */
template <typename T, typename Writer>
bits::owrite_type
rewrite_output (
  T const & _var // input
, Writer _writer
){
T * var (& _var);
T * end (var);
return
bits::owrite_type <T*, Writer>
(_var,++_var,_writer);
}

/* rewrite output */
template <
  typename Iter, typename Writer >
bits::owrite_type
rewrite_output (
  Iter _begin // input
, Iter _end
, Writer _writer
){
return
bits::owrite_type <Iter, Writer>
(_begin,_end,_writer);
}

/* rewrite input */
template <typename T, typename Writer>
bits::iwrite_type
rewrite_input (
  T & _var // output
, Writer _writer
){
return
  bits
::iwrite_type <bits::output_iterator<T>>
(bits::output_iterator(_var), _writer);
}

} /* data_pattern */
#endif

