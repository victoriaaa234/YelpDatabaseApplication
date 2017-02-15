// Record.cpp : Defines the exported Record functions for the DLL application.
//

#include "Database.h"
#include "stdafx.h"

Database::Record::Record(unsigned int size) {
	std::cout << "Record: One Argument Constructor" << std::endl;
}

unsigned int Database::Record::getSize() {
	std::cout << "Record: Get Size" << std::endl;
	return 0;
}

bool Database::Record::set(unsigned int index, std::string characteristic) {
	std::cout << "Record: Set Record" << std::endl;
	return false;
}

std::string Database::Record::get(unsigned int index) {
	std::cout << "Record: Get Record" << std::endl;
	return "";
}

void Database::Record::testLinkage() {
	getSize();
	set(4, "hello");
	get(4);
	std::cout << "Record: All Functions Work!" << std::endl;
}