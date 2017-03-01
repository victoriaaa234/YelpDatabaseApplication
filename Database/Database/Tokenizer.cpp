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

Token Tokenizer::get() {
	Token tk;
	tk.value = tokens.front();
	if (std::find(keywords.begin(), keywords.end(), tk.value) != keywords.end()) { // Found a keyword
		tk.type = "_Symbol";
	}
	else if (std::find(binaryOperations.begin(), binaryOperations.end(), tk.value) != binaryOperations.end()) { // Found Binary
		tk.type = "_BinOp";
	}
	tokens.pop_front();
	return tk;
}

bool Tokenizer::hasNext() {
	return tokens.size() > 0;
}

void Tokenizer::unget(std::string token) {
	tokens.push_front(token);
}

unsigned int Tokenizer::size() {
	return tokens.size();
}

Token Tokenizer::peek() {
	Token tk;
	tk.value = tokens.front();
	if (std::find(keywords.begin(), keywords.end(), tk.value) != keywords.end()) { // Found a keyword
		tk.type = "_Symbol";
	}
	else if (std::find(binaryOperations.begin(), binaryOperations.end(), tk.value) != binaryOperations.end()) { // Found Binary
		tk.type = "_BinOp";
	}
	return tk;
}

Tokenizer::~Tokenizer()
{

}