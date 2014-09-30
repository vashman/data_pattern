// model base class to mange state and typebuffers, with helper functions.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_MODEL_HPP
#define DATA_PATTERN_MODEL_HPP

#include <typesystem/typesystem.hpp>

namespace data_pattern {

class data_model {
public:
#if __cplusplus >= 201103L
  data_model() = default;

  data_model(data_model &&) = default;

  data_model &
  operator=(data_model &&) = default;

  data_model(data_model const &) = delete;

  data_model &
  operator=(data_model const &) = delete;
#endif

  virtual
  ~data_model();

protected:
	typesystems::typesystem typesys;

private:
  template <typename T> friend data_model &
  operator<<(data_model &, T const &);

  template <typename T> friend data_model &
  operator>>(data_model &, T &);
};

template <typename T>
bool
empty(data_model const &);

template <typename T>
data_model &
operator<<(data_model &, T const &);

template <typename T>
data_model &
operator>>(data_model &, T &);

} /* data_pattern */
#endif
