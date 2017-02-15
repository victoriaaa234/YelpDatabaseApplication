#include "stdafx.h"
#include "database.h"

Database::Database() {}
// Destructor
Database::~Database() {}

// add a table to the database 
void Database::addTable(Table& table, const std::string& name) {}
// delete a table from the database
void Database::dropTable(const std::string& name) {}
// return list of table NAMES
std::vector<std::string> Database::listTables() {
	std::vector<std::string> dummyVector = { "hello", "world" };
	return dummyVector;
}

// return vector of Table object 
std::vector<Table*> Database::getTables() {
	Table *tempTable1 = new Table;
	std::vector<Table*> tempVect = { tempTable1 };
	return tempVect;
}
// Querry
Table Database::Querry(std::string Select, std::string From, std::string Where) {
	Table *tempTable = new Table;
	return *tempTable;
}