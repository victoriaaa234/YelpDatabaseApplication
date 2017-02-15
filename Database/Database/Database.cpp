// Database.cpp : Defines the exported Database functions for the DLL application.
//

#include <iostream>
#include "Database.h"
#include "stdafx.h"

Database::Database::Database() {
	std::cout << "Database: Constructor" << std::endl;
}

bool Database::Database::addTable(Table tbl, std::string name) {
	std::cout << "Database: Adding Table" << std::endl;
	return false;
}

bool Database::Database::dropTable(std::string tblName) {
	std::cout << "Database: Dropping Table" << std::endl;
	return false;
}

std::vector<std::string> Database::Database::listTables() {
	std::cout << "Database: Listing Tables" << std::endl;
	std::vector<std::string> tableNames;
	return tableNames;
}

std::map<std::string, Database::Table> Database::Database::getTables() {
	std::cout << "Database: Getting Tables" << std::endl;
	std::map<std::string, Table> tables;
	return tables;
}

Database::Table Database::Database::query(std::string select, std::string from, std::string wherever) {
	std::cout << "Database: Query" << std::endl;
	return Table();
}

void Database::Database::testLinkage() {
	addTable(Table(),"Hello");
	dropTable("Hello");
	listTables();
	getTables();
	query("Select", "From", "Where");
	std::cout << "Database: All Functions Work!" << std::endl;
}

