// Table.cpp : Defines the exported Table functions for the DLL application.
//

#include <iostream>
#include "Database.h"
#include "stdafx.h"

Database::Table::Table() {
	std::cout << "Table: No Argument Constructor" << std::endl;
}

Database::Table::Table(std::vector<std::string> name) {
	std::cout << "Table: One Argument Constructor" << std::endl;
	attributes = name;
}

bool Database::Table::addAttribute(std::string name) {
	std::cout << "Table: Adding Attribute" << std::endl;
	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == name) {
			std::cout << "Attribute name already exists" << std::endl;
			return false;
		}
	}
	attributes.push_back(name);
	return true;
}

bool Database::Table::deleteAttribute(std::string name) {
	std::cout << "Table: Deleting Attribute" << std::endl;
	for (int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == name) {
			attributes.erase(attributes.begin() + i);
			return true;
		}
	}
	std::cout << "Attribute name does not exist" << std::endl;
	return false;
}

bool Database::Table::insert(Record record) {
	std::cout << "Table: Inserting" << std::endl;
	return false;
}

std::vector<std::string> Database::Table::getAttributes() {
	std::cout << "Table: Getting Attributes" << std::endl;
	std::vector<std::string> attributes;
	return attributes;
}

unsigned int Database::Table::getSize() {
	std::cout << "Table: Getting Size" << std::endl;
	return 0;
}

Database::tblIterator Database::Table::begin() {
	std::cout << "Table: Table Iterator Begin" << std::endl;
	return tblIterator();
}

Database::tblIterator Database::Table::end() {
	std::cout << "Table: Table Iterator End" << std::endl;
	return tblIterator();
}

bool Database::Table::defineKey(std::string name) {
	std::cout << "Table: Defining Key" << std::endl;
	return false;
}

Database::Table Database::Table::crossJoin(Table tblOne, Table tblTwo) {
	std::cout << "Table: Cross Join" << std::endl;
	return Table();
}

Database::Table Database::Table::naturalJoin(Table tblOne, Table tblTwo) {
	std::cout << "Table: Natural Join" << std::endl;
	return Table();
}

std::map<std::string, std::string> Database::Table::routines(std::string name) {
	std::cout << "Table: Routines" << std::endl;
	std::map<std::string, std::string> procedures;
	return procedures;
} 

void Database::Table::testLinkage() {
	std::vector<std::string> test;
	test.push_back("Name");
	test.push_back("Date");
	test.push_back("City");
	test.push_back("Country");
	Table table = Table(test);
	std::cout << std::boolalpha << table.addAttribute("Size") << std::endl;
	std::cout << std::boolalpha << table.addAttribute("Name") << std::endl;
	std::cout << std::boolalpha << table.deleteAttribute("Size") << std::endl;
	std::cout << std::boolalpha << table.deleteAttribute("Size") << std::endl;
	insert(Record(5));
	getAttributes();
	getSize();
	begin();
	end();
	defineKey("Hello");
	crossJoin(Table(), Table());
	naturalJoin(Table(), Table());
	routines("Hello");
	std::cout << "Table: All Functions Work!" << std::endl;
}