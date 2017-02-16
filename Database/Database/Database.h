#pragma once  

#ifdef DATABASE_EXPORTS  
#define DATABASE_API __declspec(dllexport)   
#else  
#define DATABASE_API __declspec(dllimport)   
#endif  

#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace Database {

	struct tblIterator {

	};

	class Record {
	private:
		std::vector<std::string> record;

	public:
		DATABASE_API Record(unsigned int size);
		DATABASE_API unsigned int getSize();
		DATABASE_API bool set(unsigned int index, std::string characteristic);
		DATABASE_API std::string get(unsigned int index);
		DATABASE_API void testLinkage();
	};

	class Table {
	public:
		DATABASE_API Table();
		DATABASE_API Table(std::vector<std::string> name);
		DATABASE_API bool addAttribute(std::string name);
		DATABASE_API bool deleteAttribute(std::string name);
		DATABASE_API bool insert(Record record);
		DATABASE_API std::vector<std::string> getAttributes();
		DATABASE_API unsigned int getSize();
		DATABASE_API tblIterator begin();
		DATABASE_API tblIterator end();
		DATABASE_API bool defineKey(std::string name);
		DATABASE_API Table crossJoin(Table tblOne, Table tblTwo);
		DATABASE_API Table naturalJoin(Table tblOne, Table tblTwo);
		DATABASE_API std::map<std::string, std::string> routines(std::string name);
		DATABASE_API void testLinkage();
	};

	// This class is exported from the Database.dll
	class Database {
		static std::map<std::string, Table> databaseTables;
		class Query {
			std::vector<std::string> attributes;
			std::vector<std::string> parsedWhere;
			std::vector<Record> records;
			Table table;
			Table outputTable;
		public:
			Query(std::string select, std::string from, std::string wherever);
			Table findTable(std::string from);
			void createTable();
			std::vector<std::string> parseSelect(std::string select);
			std::vector<std::string> parseWhere(std::string wherever);
			void addRecords();
			std::vector<Record> findRecords();
			Table getOutputTable();
		};
	public:
		DATABASE_API Database();
		DATABASE_API bool addTable(Table tbl, std::string name);
		DATABASE_API bool dropTable(std::string tblName);
		DATABASE_API std::vector<std::string> listTables();
		DATABASE_API std::map<std::string, Table> getTables();
		DATABASE_API Table query(std::string select, std::string from, std::string wherever);
		DATABASE_API void testLinkage();
	};
}
