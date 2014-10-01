// getopt within a model, allows use of getopt where a model is prefered to io of arguments.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STDL_DATABASE_GETOPT_DB_HPP
#define STDL_DATABASE_GETOPT_DB_HPP

#include <unistd.h>
#include <string>
#include <vector>
#include <stdl/model.hpp>

namespace stdl{
template <typename Alloc = std::allocator<char*> >
class getopt_db : public model{
public:
	typedef std::vector<char*,Alloc> char_container_type;
	typedef typebuffer<char*, char_container_type> char_buffer_type;

	getopt_db(std::string);
#if __cplusplus >= 201103L
//	getopt_db(getopt_db&&);
//	getopt_db& operator=(getopt_db&&)
#endif
	~getopt_db();
	void set_args(std::string&);
	void process();
protected:
	getopt_db(getopt_db const&) = delete;
	getopt_db& operator=(getopt_db const&) = delete;
private:
	std::string args;
};

template <typename Alloc>
getopt_db<Alloc>::getopt_db(std::string _str)
	: model (typesystem())
	, args(_str){
set_typebuff<typename getopt_db<Alloc>::char_container_type >(this->buff_map);
}

#if __cplusplus >= 201103L
/*
template <typename Alloc>
getopt_db<Alloc>::getopt_db(getopt_db<Alloc>&& _db)
	: model (_db){
}

template <typename Alloc>
getopt_db<Alloc>& getopt_db<Alloc>::operator=(getopt_db<Alloc>&& _db){
this = _db;
}
*/
#endif

template <typename Alloc>
getopt_db<Alloc>::~getopt_db(){
}

template <typename Alloc>
void getopt_db<Alloc>::process(){
typename getopt_db<Alloc>::char_buffer_type& buff = use_typebuff<char*, typename getopt_db<Alloc>::char_buffer_type>(this->buff_map);
	if (!buff.empty()){
	while ((c =  getopt(static_cast<int>(buff.size()), &(*buff_ptr)[0], this->args.c_str())) != -1){
	buff_int.push(c);
	}
	}
}
}
#endif
