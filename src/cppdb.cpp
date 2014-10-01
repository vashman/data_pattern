
//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STDL_DATABASE_CPPDB_CPP
#define STDL_DATABASE_CPPDB_CPP

#include "cppdb.hpp"

namespace stdl{
cppdb::cppdb(std::initializer_list<std::function<database::rv_type(database&)> > _list)
	: database(typesystem())
	, commands (_list){
}

cppdb::~cppdb(){
}

cppdb::cppdb(cppdb const& _db)
	: database(_db)
	, commands (_db.commands){
}

cppdb::cppdb(cppdb && _db)
	: database (_db)
	, commands (_db.commands){
}

cppdb& cppdb::operator=(cppdb const& _db){
	if (this != &_db){
	this->commands = _db.commands;
	}
return *this;
}

cppdb& cppdb::operator=(cppdb && _db){
this->commands = _db.commands;
return *this;
}

database::rv_type cppdb::access(database::access_type _operation){
	if (_operation > this->commands.size()){
	return database::noquery_bit;
	}
return (this->commands[_operation])(*this);
}
}
#endif
