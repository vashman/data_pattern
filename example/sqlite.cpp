//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/raw.hpp"
#include "../src/sqlite.cpp"

using std::cout;
using std::endl;
using data_pattern::sqlite;
using data_pattern::raw;
using data_pattern::sqlite_statement;

int main () {
sqlite db("testdata");
/* Create the table if it does not exist
  yet.
*/

db.step ( db.create (
  "CREATE TABLE IF NOT EXISTS test3"
  "(Value INT, str TEXT, dec REAL, "
  "raw Blob);"
) );

sqlite_statement query1 (
  "CREATE TABLE IF NOT EXISTS test"
  "(ID INT PRIMARY KEY NOT NULL"
  ", Value INT);"
, db
);

/* Run the statement. */
db.step(query1);

auto query3 = db.create(
  "INSERT INTO test3 "
  "(Value, str, dec, raw) Values"
  " (?,?,?,?);" );

*query3 = 45;
++query3;
*query3 = std::string("test string");
++query3;
*query3 = 12.04;
++query3;
*query3 = raw("0101", 4);

db.step(query3);

auto query4 = db.create (
  "INSERT INTO test "
  "(ID, Value) Values (?, ?);" );

/* bind data into data_model */
*query4 = 1; ++query4; *query4 = 4;
db.step(query4);

//
int temp_int;
std::string temp_str;
data_pattern::raw temp_raw;
double temp_dbl;

auto query5 ( db.create (
  "SELECT ID, Value FROM test;" ));
db.step(query5);

int temp;
temp = *query5++;
temp = *query5++;

auto query6 ( db.create (
  "SELECT Value, str, dec, raw FROM "
  "test3;" ));
db.step(query6);

temp_int = *query6++;
temp_str = static_cast <
  std::string >(*query6++);
temp_dbl = *query6++;

cout << "value: " << temp_int
<< " str: " << temp_str << " dec: "
<< temp_dbl;

return 0;
}
