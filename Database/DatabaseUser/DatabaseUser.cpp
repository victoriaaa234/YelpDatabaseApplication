// DatabaseUser.cpp : Defines the entry point for the console application.
//

#include "Database.h"
#include "stdafx.h"


int main()
{
	Database::Database db = Database::Database();
	Database::Table table = Database::Table();
	Database::Record record = Database::Record(5);
    return 0;
}

