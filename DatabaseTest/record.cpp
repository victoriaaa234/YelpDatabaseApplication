//
// Created by Kevin Nguyen on 2/20/17.
//
#include "record.h"

// default constructor
Record::Record() {}
Record::Record(int n) {}
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

Record& Record::operator = (const Record& record) {

};

