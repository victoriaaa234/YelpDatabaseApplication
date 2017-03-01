#include "stdafx.h"
#include "Tokenizer.h"
#include "string"

Tokenizer::Tokenizer(std::string& str)
{
	strToParse = str;
	std::string::size_type lastPos = strToParse.find_first_not_of(delimiters, 0);
	std::string::size_type pos = strToParse.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}

std::string Tokenizer::get() {

	std::string token = tokens.front();
	tokens.pop_front();
	return token;
}

bool Tokenizer::hasNext() {
	return tokens.size() > 0;
}

void Tokenizer::unget(std::string token) {
	tokens.push_front(token);
}

unsigned int Tokenizer::getSize() {
	return tokens.size();
}


Tokenizer::~Tokenizer()
{

}


/*#include <string>
#include <vector>

//! Tokenize the given string str with given delimiter. If no delimiter is given whitespace is used.
void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ")
{
	tokens.clear();
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}*/