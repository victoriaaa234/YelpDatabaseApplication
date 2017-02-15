// Database.cpp : Defines the exported Database functions for the DLL application.
//

#include "Database.h"
#include "stdafx.h"

Database::Database::Database() {

}

bool Database::Database::addTable(Table tbl, std::string name) {
	return false;
}

bool Database::Database::dropTable(std::string tblName) {
	return false;
}

std::vector<std::string> Database::Database::listTables() {
	std::vector<std::string> tableNames;
	return tableNames;
}

std::map<std::string, Database::Table> Database::Database::getTables() {
	std::map<std::string, Table> tables;
	return tables;
}

Database::Table Database::Database::query(std::string select, std::string from, std::string wherever) {
	return Table();
}


