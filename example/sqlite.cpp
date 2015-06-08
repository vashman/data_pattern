//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../src/sqlite.cpp"
#include "../src/sqlite_rewriters.cpp"

using std::cout;
using std::endl;
using data_pattern::sqlite;

int main () {
sqlite db("testdata");
/* Create the table if it does not exist
  yet.
*/

auto query2 = db.create(
  "CREATE TABLE IF NOT EXISTS test2"
  "(Value INT);"
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
  "INSERT INTO test2 "
  "(Value) Values (?);"
);

db << 45;
db.step();

/**/
db << db.create(
  "INSERT INTO test "
  "(ID, Value) Values (?, ?);"
);

/* bind data into data_model */
db << 2 << 4;

db.step();
}
