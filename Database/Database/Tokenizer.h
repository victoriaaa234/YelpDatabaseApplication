#pragma once
#include <iostream>
#include <list>

class Tokenizer
{
	std::string delimiters = " ,*";
	std::string strToParse;
	std::list<std::string> tokens;
public:
	Tokenizer(std::string& str);
	std::string get();
	bool hasNext();
	void unget(std::string token);
	unsigned int getSize();
	~Tokenizer();
};

