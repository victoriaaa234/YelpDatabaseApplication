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


		// Returns a + b  
		//static MATHLIBRARY_API double Add(double a, double b);

		// Returns a * b  
		//static MATHLIBRARY_API double Multiply(double a, double b);

		// Returns a + (a * b)  
		//static MATHLIBRARY_API double AddMultiply(double a, double b);
	};

	class Table
	{
	public:
	};

	class Record
	{
	public:
	};

	
}
