// Query.cpp : Defines the exported Query functions for the DLL application.
//

#include <iostream>
#include <sstream>
#include "Database.h"
#include "stdafx.h"

typedef std::map<std::string, Database::Table> database;

Database::Database::Query::Query(std::string select, std::string from, std::string wherever) {
	//attributes = parseSelect(select);
	parsedWhere = parseWhere(wherever);
}

std::vector<std::string> Database::Database::Query::parseWhere(std::string wherever) {
	return parsedWhere;
}

std::vector<std::string> Database::Database::Query::parseSelect(std::string select, Table table) {
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

std::vector<std::string> Database::Database::Query::getAttributes() {
	return attributes;
}

std::vector<std::string> Database::Database::Query::getParsedWhere() {
	return parsedWhere;
}