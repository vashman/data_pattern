//

//

#ifndef DATA_PATTERN_BITS_SPARQL_SQLITE_HPP
#define DATA_PATTERN_BITS_SPARQL_SQLITE_HPP

namespace data_pattern {
namespace bits {
/**/
template <>
sparql_traits<sqlite>{
public:
  inline static void
  select(sqlite &);

  inline static void
  where(sqlite &);

  inline static void
  ask(sqlite &);

  inline static void
  describe(sqlite &);

  inline static void
  create(sqlite &);
};

template <>
void
sparql_traits<sqlite>::select(
  sqlite & _db
){
_db.prepare
}

} /* bits */ } /* data_pattern */
#endif
