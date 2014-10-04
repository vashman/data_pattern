//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_SQL_INTERPRATER_HPP
#define DATA_PATTERN_SQL_INTERPRATER_HPP

#include <data_pattern/interprater.hpp>

namespace data_pattern {

template <typename Model>
class sql_traits : public dbmodel::model_traits<Model>{
public:
  typedef sql_traits<Model> traits_type;

  inline static void
  process_sql_statment(char const * const);

  inline static typename sql_interpreater<Model,traits_type>::sql_versions
  sql_version();
};

/*
verify statment
if can pass statment directly pass it else
use traits to run operate subprocedures
*/
template <typename Model, typename Traits = sql_dbtraits<Model> >
class sql_interprater : public dbmodel::interprater<Model>{
public:
  typedef int sql_versions;
  static sql_versions const _86 = 0;
  static sql_versions const _89 = 1;
  static sql_versions const _92 = 2;
  static sql_versions const _1999 = 3;

  explicit
  sql_interprater(sql_versions);

private:
  virtual void
  do_interpret(
     Model &
     char *
  );
};

template <Model, typename Traits>
sql_interprater<Model,Traits>::sql_interprater(
  sql_versions
){
}

template <typename Model, typename Traits>
void
sql_interprater<Model,Traits>::do_interpret(
  Model & _mdl
  char * _data
){
}

} /* data_pattern */
#endif
