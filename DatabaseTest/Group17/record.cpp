#include "stdafx.h"
#include "record.h"

// default constructor
Record::Record() {}
// copy constructor
Record::Record(const Record& record) {}
// assignment operator
//Record& Record::Record::operator = (const Record& record) {}
// destructor 
Record::~Record() {}
// get record size
int Record::getRecordSize() {
	return 0;
}
// accessor operator
std::string& Record::operator [] (int index) {
	std::string text = "dummy text";
	return text;
}
