// Table.cpp : Defines the exported Table functions for the DLL application.
//

#include "Database.h"
#include "stdafx.h"

Database::Table::Table() {

}

Database::Table::Table(std::vector<std::string> name) {

}

bool Database::Table::addAttribute(std::string name) {
	return false;
}

bool Database::Table::deleteAttribute(std::string name) {
	return false;
}

bool Database::Table::insert(Record record) {
	return false;
}

std::vector<std::string> Database::Table::getAttributes() {
	std::vector<std::string> attributes;
	return attributes;
}

unsigned int Database::Table::getSize() {
	return 0;
}

Database::tblIterator Database::Table::begin() {
	return tblIterator();
}

Database::tblIterator Database::Table::end() {
	return tblIterator();
}

bool Database::Table::defineKey(std::string name) {
	return false;
}

Database::Table Database::Table::crossJoin(Table tblOne, Table tblTwo) {
	return Table();
}

Database::Table Database::Table::naturalJoin(Table tblOne, Table tblTwo) {
	return Table();
}

std::map<std::string, std::string> Database::Table::routines(std::string name) {
	std::map<std::string, std::string> procedures;
	return procedures;
} 