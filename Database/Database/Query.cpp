// Query.cpp : Defines the exported Query functions for the DLL application.
//

#include <iostream>
#include <sstream>
#include "Database.h"
#include "stdafx.h"

typedef std::map<std::string, Database::Table> database;

Database::Database::Query::Query(std::string select, std::string from, std::string wherever) {
	table = findTable(from);
	attributes = parseSelect(select);
	parsedWhere = parseWhere(wherever);
	findRecords();
	addRecords();
	getOutputTable();
}

std::vector<Database::Record> Database::Database::Query::findRecords() {
	return records;
}

void Database::Database::Query::addRecords() {
	int index = 0;
	for (int i = 0; i < records.size(); i++) {
		outputTable.insert(records[i]);
	}
}

Database::Table Database::Database::Query::getOutputTable() {
	return outputTable;
}

Database::Table Database::Database::Query::findTable(std::string from) {
	database::iterator databaseTablesIterator = databaseTables.find(from);
	return databaseTablesIterator->second;
}

void Database::Database::Query::createTable() {
	outputTable = Table(attributes);
}

std::vector<std::string> Database::Database::Query::parseWhere(std::string wherever) {
	return parsedWhere;
}

std::vector<std::string> Database::Database::Query::parseSelect(std::string select) {
	if (select == "*") {
		return table.getAttributes();
	}
	else {
		std::stringstream ss(select);
		std::string token;
		while (ss >> token) {
			attributes.push_back(token.c_str());
		}
		return attributes;
	}
}