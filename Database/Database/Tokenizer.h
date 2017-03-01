#pragma once
#include <iostream>
#include <list>
#include <vector>

struct Token {
	std::string value;
	std::string type = "_OTHER";
};

class Tokenizer
{
	std::string delimiters = " ,*";

	std::vector<std::string> keywords = { "AND", "OR", "NOT", "True" };
	std::vector<std::string> binaryOperations = { "=", "<", ">", "<=", ">=" };

	std::string strToParse;
	std::list<std::string> tokens;
public:
	Tokenizer(std::string& str);
	Token get();
	bool hasNext();
	void unget(std::string token);
	unsigned int size();
	Token peek();
	~Tokenizer();
};