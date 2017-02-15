// Members: My Pham, Sneha Santani, Leslie Escalante
// Team 17 - section 506

#pragma once

#ifdef DLIBRARY_EXPORTS
#define DLIBRARY __declspec(dllexport)   
#else  
#define DLIBRARY __declspec(dllimport)   
#endif   

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <iostream>
#include <vector>
#include "table.h"
class DLIBRARY Database {

public:
	// Default constructor
	Database();
	// Destructor
	~Database();

	// add a table to the database 
	void addTable(Table& table, const std::string& name);
	// delete a table from the database
	void dropTable(const std::string& name);
	// return list of table NAMES
	std::vector<std::string> listTables();
	// return vector of Table object 
	std::vector<Table*> getTables();
	// Querry
	Table Querry(std::string Select, std::string From, std::string Where);

private:
	std::vector<Table*> database;
	std::vector<Table*>::iterator databaseItr;
};

#endif