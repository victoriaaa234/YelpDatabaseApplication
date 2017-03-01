// Table.cpp : Defines the exported Table functions for the DLL application.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
#include "stdafx.h"

Database::Table::Table() {}

Database::Table::Table(std::vector<std::string> name) {
	attributes = name;
}

bool Database::Table::addAttribute(std::string name) {
	for (unsigned int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == name) {
			std::cout << "Attribute name already exists" << std::endl;
			return false;
		}
	}
	attributes.push_back(name);
	return true;
}

bool Database::Table::deleteAttribute(std::string name) {

	int position = -1; 

	for (unsigned int i = 0; i < attributes.size(); ++i) {
		if (attributes[i] == name) {
			position = i;
			break;
		}
	}

	if (position == -1) {
		std::cout << "Unable to find attribute." << std::endl;
		return false;
	}

	attributes.erase(attributes.begin() + position);

	for (unsigned int i = 0; i < allRecords.size(); i++) {
		allRecords[i].remove(position);
	}
	
	return true;

}

bool Database::Table::insert(Record record) {
	if (record.getSize() <= attributes.size()) {
		allRecords.push_back(record);
		return true;
	}
	return false;
}

std::vector<std::string> Database::Table::getAttributes() {
	return attributes;
}

unsigned int Database::Table::getSize() {
	return allRecords.size();
}

Database::tblIterator Database::Table::begin() {
	tableIterator.table = this;
	tableIterator.value = 0;
	return tableIterator;
}

Database::tblIterator Database::Table::end() {
	tableIterator.table = this;
	tableIterator.value = allRecords.size();
	return tableIterator;
}

std::string Database::Table::getKey() {
	return key;
}

bool Database::Table::defineKey(std::string name) {
	for (unsigned int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == name) {
			key = name;
			return true;
		}
	}
	return false;
}

std::vector<Database::Record> Database::Table::getAllRecords() {
	return allRecords;
}

Database::Record& Database::Table::getRecord(int index) {
	return allRecords[index];
}

Database::Table Database::Table::crossJoin(Table tblOne, Table tblTwo) {
	if (tblOne.getAttributes().empty()) {
		if (tblTwo.getAttributes().empty()) {
			return Table();
		}
		else {
			return tblTwo;
		}
	}
	else if (!tblOne.getAttributes().empty()) {
		if (tblTwo.getAttributes().empty()) {
			return tblOne;
		}
	}
	std::vector<std::string> totalAttributes;
	unsigned int recordIndex = 0;
	unsigned int tableOneIndex = 0;
	unsigned int tableTwoIndex = 0;
	std::vector<std::string> tblOneAttributes = tblOne.getAttributes();
	std::vector<std::string> tblTwoAttributes = tblTwo.getAttributes();
	unsigned int count = 0;
	for (unsigned int i = 0; i < tblOneAttributes.size(); i++) {
		for (unsigned int j = 0; j < tblTwoAttributes.size(); j++) {
			if (tblOneAttributes[i] == tblTwoAttributes[j]) {
				count++;
				std::string attributeOne = tblOneAttributes[i];
				std::string attributeTwo = tblTwoAttributes[j];
				attributeOne = std::to_string(count) + attributeOne;
				count++;
				attributeTwo = std::to_string(count) + attributeTwo;
				tblOneAttributes[i] = attributeOne;
				tblTwoAttributes[j] = attributeTwo;
			}
			count = 0;
		}
	}
	totalAttributes = tblOneAttributes;
	totalAttributes.insert(totalAttributes.end(), tblTwoAttributes.begin(), tblTwoAttributes.end());
	unsigned int attributeSize = totalAttributes.size();
	Table crossJoinTable(totalAttributes);
	for (unsigned int i = 0; i < tblOne.getSize(); i++) {
		for (unsigned int j = 0; j < tblTwo.getSize(); j++) {
			Record newRecord(attributeSize);
			while (tableOneIndex < tblOneAttributes.size()) {
				newRecord.set(recordIndex, tblOne.getAllRecords()[i].get(tableOneIndex));
				tableOneIndex++;
				recordIndex++;
			}
			while (tableTwoIndex < tblTwoAttributes.size()) {
				newRecord.set(recordIndex, tblTwo.getAllRecords()[j].get(tableTwoIndex));
				tableTwoIndex++;
				recordIndex++;
			}
			tableTwoIndex = 0;
			tableOneIndex = 0;
			recordIndex = 0;
			crossJoinTable.insert(newRecord);
		}
	}
	return crossJoinTable;
}

Database::Table Database::Table::naturalJoin(Table tblOne, Table tblTwo) {
	if (tblOne.getAttributes().empty()) {
		if (tblTwo.getAttributes().empty()) {
			std::cerr << "Both tables are empty!";
		}
		else {
			std::cerr << "There is no key!";
		}
	}
	else if (!tblOne.getAttributes().empty()) {
		if (tblTwo.getAttributes().empty()) {
			std::cerr << "There are no attributes matching!";
		}
	}
	unsigned int tblOneAttribute = 0;
	unsigned int tblTwoAttribute = 0;
	std::vector<std::string> tblOneAttributes = tblOne.getAttributes();
	std::vector<std::string> tblTwoAttributes = tblTwo.getAttributes();
	bool verify = false;
	std::string tableKey;
	tableKey = tblTwo.getKey();
	if (tblTwo.getKey() != "") {
		for (unsigned int i = 0; i < tblOneAttributes.size(); i++) {
			if (tblOneAttributes[i] == tblTwo.getKey()) {
				verify = true;
				tblOneAttribute = i;
				break;
			}
		}
	}
	else {
		std::cerr << "There is no key!";
	}
	for (unsigned int i = 0; i < tblTwoAttributes.size(); i++) {
		if (tblTwoAttributes[i] == tableKey) {
			tblTwoAttribute = i;
			break;
		}
	}
	if (!verify) {
		std::cerr << "There are no attributes matching!";
	}
	unsigned int recordIndex = 0;
	unsigned int tableOneIndex = 0;
	std::vector<std::string> totalAttributes;
	totalAttributes = tblOneAttributes;
	for (unsigned int i = 0; i < tblTwoAttributes.size(); i++) {
		if (tblTwoAttributes[i] != tableKey) {
			totalAttributes.push_back(tblTwoAttributes[i]);
		}
	}
	unsigned int attributeSize = totalAttributes.size();
	unsigned int tblTwoElement = 0;
	Table naturalJoinTable(totalAttributes);
	for (unsigned int i = 0; i < tblOne.getSize(); i++) {
		Record newRecord(attributeSize);
		while (tableOneIndex < tblOneAttributes.size()) {
			newRecord.set(recordIndex, tblOne.getAllRecords()[i].get(tableOneIndex));
			tableOneIndex++;
			recordIndex++;
		}
		for (unsigned int j = 0; j < tblTwo.getSize(); j++) {
			if (tblOne.getAllRecords()[i].get(tblOneAttribute) == tblTwo.getAllRecords()[j].get(tblTwoAttribute)) {
				while (tblTwoElement < tblTwoAttributes.size()) {
					if (tblTwoElement != tblTwoAttribute) {
						newRecord.set(recordIndex, tblTwo.getAllRecords()[j].get(tblTwoElement));
						recordIndex++;
					}
					tblTwoElement++;
				}
				tblTwoElement = 0;
				break;
			}
		}
		tableOneIndex = 0;
		recordIndex = 0;
		naturalJoinTable.insert(newRecord);
	}
	return naturalJoinTable;
}

std::map<std::string, std::string> Database::Table::routines(std::string name) {
	std::map<std::string, std::string> procedures;
	std::string minimum = "";
	std::string maximum = "";
	unsigned int j = 0;
	unsigned int count = 0;
	unsigned int attributeLocation = -1;
	for (unsigned int i = 0; i < attributes.size(); i++) {
		if (attributes[i] == name) {
			attributeLocation = i;
			break;
		}
	}
	if (attributeLocation == -1) {
		std::cerr << "Name doesn't exist in the attributes" << std::endl;
	}
	if (allRecords.empty()) {
		std::cerr << "There are no records in the table!" << std::endl;
	}
	else {
		for (unsigned int i = 0; i < allRecords.size(); i++) {
			if (allRecords[i].get(attributeLocation) != "") {
				count++;
				if (j == 0) {
					minimum = allRecords[i].get(attributeLocation);
					maximum = allRecords[i].get(attributeLocation);
					j++;
				}
				if (maximum < allRecords[i].get(attributeLocation)) {
					maximum = allRecords[i].get(attributeLocation);
				}
				if (minimum > allRecords[i].get(attributeLocation)) {
					minimum = allRecords[i].get(attributeLocation);
				}
			}
		}
		std::string stringCount = std::to_string(count);
		procedures.insert(std::pair<std::string, std::string>("count", stringCount));
		procedures.insert(std::pair<std::string, std::string>("min", minimum));
		procedures.insert(std::pair<std::string, std::string>("max", maximum));
	}
	return procedures;
} 

bool Database::Table::deleteRecord(unsigned int index) {
	if (index >= allRecords.size()) {
		return false;
	}

	allRecords.erase(allRecords.begin() + index);
	return true;
}

