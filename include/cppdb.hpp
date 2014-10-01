
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STDL_DATABASE_CPPDB_HPP
#define STDL_DATABASE_CPPDB_HPP

#if __cplusplus < 201103L
#error c++ 11 or higher is required.
#endif

#include <initializer_list>
#include <vector>
#include <functional>
#include <stdl/database.hpp>

namespace stdl{
class cppdb : public database {
public:
	explicit cppdb(std::initializer_list<function<database::rv_type(database&)> >);
	cppdb(cppdb const&);
	cppdb& operator=(cppdb const&);
	cppdb(cppdb&&);
	cppdb& operator=(cppedb&&);
	~cppdb();
	virtual database::rv_type access(database::access_type);
private:
	std::vector<sdt::function<database::rv_type(database&)> > commands;
};
}
#endif
