#pragma once  

#ifdef DATABASE_EXPORTS  
#define DATABASE_API __declspec(dllexport)   
#else  
#define DATABASE_API __declspec(dllimport)   
#endif  

#include <iostream>
#include <vector>
#include <map>

namespace Database
{
	// This class is exported from the Database.dll  
	class Database
	{
		class Query
		{
		public:

		};
	public:
		DATABASE_API Database();
		DATABASE_API bool addTable(Table tbl, std::string name);
		DATABASE_API bool dropTable(std::string tblName);
		DATABASE_API std::vector<std::string> listTables();
		DATABASE_API std::map<std::string, Table> getTables();
		DATABASE_API Table query(std::string select, std::string from, std::string where);
	};

	struct tblIterator {
		
	};

	class Table
	{
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

	};

	class Record
	{
	public:
		DATABASE_API Record();
		DATABASE_API Record(std::vector<std::string> name);
		DATABASE_API unsigned int getSize();
		DATABASE_API std::string get(int index);
	};

	
}
