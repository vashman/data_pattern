//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/raw.hpp"
#include "../src/sqlite.cpp"
#include "../src/sqlite_rewriters.cpp"

using std::cout;
using std::endl;
using data_pattern::sqlite;
using data_pattern::raw;

int main () {
sqlite db("testdata");
/* Create the table if it does not exist
  yet.
*/

auto query2 = db.create(
  "CREATE TABLE IF NOT EXISTS test3"
  "(Value INT, str TEXT, dec REAL, "
  "raw Blob);"
);

db.step(query2);

data_pattern::sqlite_statement query1 (
  "CREATE TABLE IF NOT EXISTS test"
  "(ID INT PRIMARY KEY NOT NULL"
  ", Value INT);"
, db
);

/* Run the statement. */
db.step(query1);

/**/
db << db.create(
  "INSERT INTO test3 "
  "(Value, str, dec, raw) Values (?,?,?,?);"
);

db << 45 << std::string("test string")
<< 12.04 << raw("0101", 4);
db.step();

/**/
db << db.create(
  "INSERT INTO test "
  "(ID, Value) Values (?, ?);"
);

/* bind data into data_model */
db << 2 << 4;

int temp_int;
std::string temp_str;
data_pattern::raw temp_raw;
double temp_dbl;

/*
db << db.create(
  "SELECT ID, Value FROM test;"
);
db.step();

int temp;
db >> temp; cout << temp;
db >> temp; cout << temp << endl;
*/

db << db.create(
  "SELECT Value, str, dec, raw FROM "
  "test3;"
);
db.step();

db >> temp_int >> temp_str >> temp_dbl
>> temp_raw;


return 0;
}
