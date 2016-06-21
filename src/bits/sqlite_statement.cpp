// data_model sqlite implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef DATA_PATTERN_BITS_SQLITE_CPP
#define DATA_PATTERN_BITS_SQLITE_CPP

namespace data_pattern {

/* ctor */
sqlite_statement::sqlite_statement (
  char const * _query
, sqlite & _db
)
/* index starts at 1 and then
  increments. */
: stmt () 
, db(_db.db)
, max_col (new int(0))
, index (1) {
sqlite3_stmt * stmtptr = NULL;
  bits::sqlite
::check_error( sqlite3_prepare_v2 (
  _db.db.get()
, _query
, -1 // Query is null terminated.
, & stmtptr
/* There is never an unused portion of
  the statement.
*/
, 0 ));
this->stmt.reset(
  stmtptr, sqlite3_finalize );
}

sqlite_statement
sqlite_statement::operator ++ (int){
auto temp (*this);
++index;
return temp;
}

sqlite_statement &
sqlite_statement::operator ++ (){
++index;
return *this;
}

sqlite_statement &
sqlite_statement::operator * (){
return *this;
}

sqlite_statement *
sqlite_statement::operator -> (){
return this;
}

/* sqlite_statement bind_int */
void
sqlite_statement::bind (
  int _index
, int _var
){
  bits::sqlite
::check_error ( sqlite3_bind_int (
  this->stmt.get()
, _index
, _var ) );
}

sqlite_statement &
sqlite_statement::operator = (
  int _var
){
this->bind(this->index, _var);
return *this;
}

/* */
void
sqlite_dtor_data (
  void *
);

void
sqlite_dtor_data (
  void * _data
){
// do nothing
}

/* sqlite_statement bind_blob */
void
sqlite_statement::bind (
  int _index
, void const * _blob
, int _size
){
  bits::sqlite
::check_error ( sqlite3_bind_blob (
  this->stmt.get()
, _index
, _blob
, _size
, sqlite_dtor_data ) );
}

/* sqlite_statement bind string */
void
sqlite_statement::bind (
  int _index
, char const * _str
){
  bits::sqlite
::check_error ( sqlite3_bind_text (
  this->stmt.get()
, _index
, _str
, static_cast<int> (
  std::char_traits<char>::length(_str) )
, sqlite_dtor_data ) );
}

sqlite_statement &
sqlite_statement::operator = (
  std::string _var
){
this->bind(this->index, _var.c_str());
return *this;
}

/* sqlite_statement bind double */
void
sqlite_statement::bind (
  int _index
, double _var
){
  bits::sqlite
::check_error ( sqlite3_bind_double (
  this->stmt.get(), _index, _var ) );
}

sqlite_statement &
sqlite_statement::operator = (
  double _var 
){
this->bind(this->index, _var);
return *this;
}

/* sqlite bind null */
void
sqlite_statement::bind (
  int _index
){
  bits::sqlite
::check_error ( sqlite3_bind_null (
  this->stmt.get(), _index ) );
}

/* sqlite_statement column_int */
int
sqlite_statement::column_int (
  int _index
){
return sqlite3_column_int (
  this->stmt.get(), _index );
}

sqlite_statement::operator int (){
return this->column_int(this->index);
}

/* sqlite_statement column_double */
double
sqlite_statement::column_double(
  int _index
){
return sqlite3_column_double (
  this->stmt.get(), _index );
}

sqlite_statement::operator double (){
return
this->column_double(this->index);
}

  sqlite_statement
::operator std::string (){
return std::string (
  reinterpret_cast<char const *> (
    this->column_text(this->index) )
);
}

sqlite_statement::operator raw (){
return raw (
  this->column_blob(this->index)
, static_cast<std::size_t>(
    this->column_bytes(this->index) )
);
}

sqlite_statement &
sqlite_statement::operator = (
  raw _var
){
this->bind (
  this->index
, _var.ptr()
, static_cast<int>(_var.size()) );
return *this;
}

/* sqlite_statement column_blob */
const void *
sqlite_statement::column_blob (
  int _index
){
return sqlite3_column_blob (
  this->stmt.get(), _index );
}

/* column bytes */
int
sqlite_statement::column_bytes (
  int _index
){
return sqlite3_column_bytes (
  this->stmt.get(), _index );
}

/* column bytes 16 */
int
sqlite_statement::column_bytes16 (
  int _index
){
return sqlite3_column_bytes16 (
  this->stmt.get(), _index );
}

/* column text */
const unsigned char *
sqlite_statement::column_text (
  int _index
){
return sqlite3_column_text (
  this->stmt.get(), _index );
}

/* column bytes 16 */
const void *
sqlite_statement::column_text16 (
  int _index
){
return sqlite3_column_text16 (
  this->stmt.get(), _index );
}

sqlite3_value *
sqlite_statement::column_value (
  int _index
){
return sqlite3_column_value (
  this->stmt.get(), _index );
}

int
sqlite_statement::column_type (
  int _index
){
return sqlite3_column_type (
  this->stmt.get(), _index );
}

bool
sqlite_statement::operator == (
  sqlite_statement const & _rhs
) const {
return (this->index > *this->max_col);
}

} /* data pattern */
#endif

