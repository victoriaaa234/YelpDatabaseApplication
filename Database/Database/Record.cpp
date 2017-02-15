// Record.cpp : Defines the exported Record functions for the DLL application.
//

#include "Database.h"
#include "stdafx.h"

Database::Record::Record(unsigned int size) {

}

unsigned int Database::Record::getSize() {
	return 0;
}

bool Database::Record::set(unsigned int index, std::string characteristic) {
	return false;
}

std::string Database::Record::get(unsigned int index) {
	return "";
}