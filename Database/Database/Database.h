#pragma once  

#ifdef DATABASE_EXPORTS  
#define DATABASE_API __declspec(dllexport)   
#else  
#define DATABASE_API __declspec(dllimport)   
#endif  

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
