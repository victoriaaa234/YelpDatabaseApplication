#pragma once
// Members: My Pham, Sneha Santani, Leslie Escalante
// Team 17 - section 506
#ifdef DLIBRARY_EXPORTS
#define DLIBRARY __declspec(dllexport)   
#else  
#define DLIBRARY __declspec(dllimport)   
#endif  

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>
#include <string>

class DLIBRARY Record {
public:
	// default constructor
	Record();
	// copy constructor
	Record(const Record& record);
	// assignment operator
	Record& Record::operator = (const Record& record);
	// destructor 
	~Record();
	// get record size
	int getRecordSize();
	// accessor operator
	std::string& operator [] (int index);

private:
	std::vector<std::string> recordData;
};
#endif
