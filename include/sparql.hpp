//

//

#ifndef DATA_PATTERN_SPARQL_HPP
#define DATA_PATTERN_SPARQL_HPP

#include "interprater.hpp"

namespace data_pattern {
/* sparql_traits */
template <typename Model>
class sparql_traits : public data_traits<Model>{
public:
  inline static void
  select(Model &);

  inline static void
  where(Model &);

  inline static void
  ask(Model &);

  inline static void
  describe(Model &);

  inline static void
  create(Model &);
};

/* sparql
http://www.w3.org/TR/sparql11-query
*/
template <typename Model, typename sparql_traits<Model> >
class sparql : public interprater<Model>{
private:
  virtual void
  do_interpret(
    Model &
  , char const * const
  );
};

}/* data_pattern */
#include "bits/sparql.tcc"
#endif
