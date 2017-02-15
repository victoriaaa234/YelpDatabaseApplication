// Record.cpp : Defines the exported Record functions for the DLL application.
//

#include "Database.h"
#include "stdafx.h"

Database::Record::Record(unsigned int size) {
	std::cout << "Record: One Argument Constructor" << std::endl;
	record = std::vector<std::string>(size, "NULL");
}

unsigned int Database::Record::getSize() {
	std::cout << "Record: Get Size" << std::endl;
	return record.size();
}

bool Database::Record::set(unsigned int index, std::string characteristic) {
	std::cout << "Record: Set Record" << std::endl;
	if (index < record.size()) {
		record[index] = characteristic;
		return true;
	}
	return false;
}

std::string Database::Record::get(unsigned int index) {
	std::cout << "Record: Get Record" << std::endl;
	if (index < record.size()) {
		return record[index];
	}
	return "";
}

void Database::Record::testLinkage() {
	std::cout << "Size: " << getSize() << std::endl;
	set(4, "hello");
	std::cout << get(4) << std::endl;
	std::cout << get(3) << std::endl;
	std::cout << "Record: All Functions Work!" << std::endl;
}