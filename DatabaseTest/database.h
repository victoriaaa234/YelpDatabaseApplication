//
// Created by Kevin Nguyen on 2/20/17.
//

#ifndef DATABASETEST_DATABASE_H
#define DATABASETEST_DATABASE_H

#include <string>
#include <iostream>
#include <vector>
#include "table.h"

class Database {
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

#endif //DATABASETEST_DATABASE_H
