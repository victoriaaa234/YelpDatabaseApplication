#include "stdafx.h"
#include "table.h"

// Default constructor
Table::Table() {}
// Constructor that takes in a vector of attribute names
Table::Table(std::vector<std::string> attributeNames) {}
// Copy constructor
Table::Table(const Table& t) {}
// Destructor
Table::~Table() {}

// get key of table 
std::string Table::getTableKey() const {
	std::string text = "dummy text";
	return text;
}

// set key for table 
void Table::specifyKey(const std::string& key) {}

//add a new column to the table 
void Table::addAttribute(std::string& attributeName) {}
// delete a column from the table 
void Table::deleteAttribute(std::string& attributeName) {}
// add a record to the table 
void Table::insertRecord(Record& record) {}
// get all attributes name from the table 
std::vector<std::string> Table::getAttributeNames() {
	std::vector<std::string> dummyVector = { "hello", "world" };
	return dummyVector;
}

// get size of table (the number of records) 
int Table::getTableSize() {
	return 0;
}
// join 2 tables into 1
Table Table::crossJoin(const Table* table1, const Table* table2) {
	Table *tempTable = new Table;
	return *tempTable;
}
// natural join 2 tables
Table Table::naturalJoin(const Table* table1, const Table* table2) {
	Table *tempTable = new Table;
	return *tempTable;
}
// routines, return count, min, and max
std::tuple<std::string, std::string, std::string> Table::findRoutine(const std::string& attributeName) {
	return std::make_tuple("hi", "hello", "hey");
}