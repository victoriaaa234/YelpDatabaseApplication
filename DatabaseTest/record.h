//
// Created by Kevin Nguyen on 2/20/17.
//

#ifndef DATABASETEST_RECORD_H
#define DATABASETEST_RECORD_H

#include <iostream>
#include <vector>
#include <string>

class Record {
    public:
    // default constructor
    Record();
    // copy constructor
    Record(const Record& record);
    Record(int n);
    // assignment operator
    Record& operator = (const Record& record);
    // destructor
    ~Record();
    // get record size
    int getRecordSize();
    // accessor operator
    std::string& operator [] (int index);

    private:
    std::vector<std::string> recordData;
};

#endif //DATABASETEST_RECORD_H
