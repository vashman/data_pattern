// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef DATA_PATTERN_GETOPT_DB_HPP
#define DATA_PATTERN_GETOPT_DB_HPP

#include <unistd.h>
#include <string>
#include <vector>
#include "data_model.hpp"

namespace data_pattern {

template <typename Alloc = std::allocator<char> >
class getopt_db : public data_model {
public:
  getopt_db(
    char const * const;
  );

  getopt_db(
  ) = default;

#if __cplusplus >= 201103L
  getopt_db(
    getopt_db &&
  );

  getopt_db &
  operator=(
    getopt_db &&
  )
#endif
	~getopt_db();

  void
  set_args(std::string &);

  void 
  getopt(
    int
  , char **
  , char const * const
 );

protected:
  getopt_db(
    getopt_db const &
  ) = delete;
	
  getopt_db &
  operator=(
    getopt_db const &
  ) = delete;

private:
	std::string args;
};

class getopt_putrw : public typesystems::put_rewriter<> {
public:
};

bool
getopt_putrw::do_rewrite(
  
){
}

/**/
template <typename alloc>
getopt_db<alloc>::getopt_db(
  std::string _str
)
	: model (typesystem())
	, args (_str) {
typesystems::set_typebuffer<
  typename getopt_db<alloc>::char_container_type>(this);
}

#if __cplusplus >= 201103L
/**/
template <typename alloc>
getopt_db<alloc>::getopt_db(
  getopt_db<Alloc> && _db
)
	: model (_db) {
}

template <typename alloc>
getopt_db<alloc> &
getopt_db<alloc>::operator=(
  getopt_db<alloc> && _db
){
this = _db;
}
#endif

template <typename alloc>
getopt_db<alloc>::~getopt_db(
){
}

/* getopt_db getopt */
template <typename alloc>
void
getopt_db<alloc>::getopt(
  int _argc
, char * const _argv[]
, char const * _str
){
char * optarg;
int optind, opterr, optopt;
std::vector<char,alloc> & buff = use_typebuff<char, alloc>(this->typesys);
while ((c =  getopt(_argc, _argv, _str)) != -1){
buff.push(c);
}
}

} /* data_pattern */
#endif
