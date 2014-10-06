//

//

#ifndef DATA_PATTERN_BITS_SPARQL_SQLITE_HPP
#define DATA_PATTERN_BITS_SPARQL_SQLITE_HPP

#include <string>

namespace data_pattern {
namespace bits {
/* sqlite_store */
template <>
model_store<sqlite>{
public:
  inline static bool
  enabled();

  std::string query;
};

/* sparql_sqlite_traits */
template <>
sparql_traits<sqlite>{
public:
  inline static void
  select(sqlite &, model_store<sqlite> &);

  inline static void
  where(sqlite &, model_store<sqlite> &);

  inline static void
  ask(sqlite &, model_store<sqlite> &);

  inline static void
  describe(sqlite &, model_store<sqlite> &);

  inline static void
  create(sqlite &, model_store<sqlite> &);
};

template <>
void
sparql_traits<sqlite>::select(
  sqlite & _db
, model_store<sqlite> & _store
){
_store.query.push_back("SELECT ");
}

template <>
sparql_traits<sqlite>::where(
  sqlite & _db
, model_store<sqlite> & _store
){
_store.query.push_back("WHERE ");
}

template <>
sparql_traits<sqlite>::ask(
  sqlite & _db
, model_store<sqlite> & _store
){
}

template <>
sparql_traits<sqlite>::describe(
  sqlite & _db
, model_store<sqlite> & _store
){
}

template <>
sparql_traits<sqlite>::create(
  Model & _db
, model_store<sqlite> & _store
){

}

} /* bits */ } /* data_pattern */
#endif
