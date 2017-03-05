// YelpDataApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "database.h"
#include "record.h"
#include "table.h"

using namespace std;

int main()
{
	RECORD_H Record r(4);
	cout << r.getRecordSize();
    return 0;
}

