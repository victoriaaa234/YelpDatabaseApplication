// Query.cpp : Defines the exported Query functions for the DLL application.
//

#include <iostream>
#include <sstream>
#include "Database.h"
#include "stdafx.h"
#include "Tokenizer.h"

Database::Database::Query::whereComponent::whereComponent(int id, std::string bin, std::string val, std::string child) {
	index = id;
	binOp = bin;
	value = val;
	childVerifyRule = child;
}

bool Database::Database::Query::whereComponent::evaluate(Record rd) {

	if (index >= rd.getSize()) return false;

	std::string valueToCompare = rd.get(index);

	if (binOp == "=") {
		return valueToCompare == value;
	}
	else if (binOp == "<") {
		return valueToCompare < value;
	}
	else if (binOp == ">") {
		return valueToCompare > value;
	}
	else if (binOp == "<=") {
		return valueToCompare <= value;
	}
	else if (binOp == ">=") {
		return valueToCompare >= value;
	}
	else {
		//invalid operation.
	}

	return false;
}
typedef std::map<std::string, Database::Table> database;

Database::Database::Query::Query(std::string select, std::string wherever, Table table) {
	originalTable = table;
	attributes = parseSelect(select, table);
	parsedWhere = parseWhere(wherever);
}

std::vector<std::string> Database::Database::Query::parseSelect(std::string select, Table table) {

	std::vector<std::string> tableAttributes; // End result table attribute names

	if (select == "*") { // Handling Wildcard
		tableAttributes = table.getAttributes();
	}
	else { // Handling arbitrary number of attribute names

		Tokenizer tk(select);

		while (tk.hasNext()) {
			Token token = tk.get();
			tableAttributes.push_back(token.value);
		}

	}

	return tableAttributes;

}

std::vector<std::string> Database::Database::Query::getAttributes() {
	return attributes;
}

std::vector<std::string> Database::Database::Query::getParsedWhere() {
	return parsedWhere;
}

Database::Table Database::Database::Query::getResult() { // Generates the result of the query.

	/* Last step is to remove the attributes that were not present in the select query. The select query should be parsed in the constructor
	** and assigned to attributes. From this, the code below removes any attribute that is present in the where table but not in select. 
	*/
	std::vector<std::string> originalAttributes = originalTable.getAttributes();

	for (std::string str : originalAttributes) {
		if (std::find(attributes.begin(), attributes.end(), str) == attributes.end()) {
			originalTable.deleteAttribute(str);
		}
	}
	return originalTable;
}

std::vector<std::string> Database::Database::Query::parseWhere(std::string whereClause) {
	using namespace std;
	cout << "WHERE: " << whereClause << endl;
	Tokenizer tk(whereClause);
	vector<string> attr = originalTable.getAttributes();

	while (tk.hasNext()) {
		Token token = tk.peek();

		if (token.type == "_OTHER") {

			Token identifier = tk.get(); // Relying on default constructor for now.
			// Find index.
			
			int pos = -1;

			for (int i = 0; i < attr.size(); i++) {
				if (attr[i] == identifier.value) {
					pos = i;
					break;
				}
			}

			if (pos == -1) {
				// throw error. attribute not found.
			}

			Token op = tk.get();

			if (op.type != "_BinOp") {
				// throw error. not matching format.
			}

			Token val = tk.get();

			if (op.type != "_OTHER") {
				// throw error. either symbol or binary operation that is invalid.
			}

			whereComponent condition(pos, op.value, val.value, "AND");

			validationRules.push_back(condition);

		}
		else if (token.type == "_Symbol") {
			Token t = tk.get();
		}

	}

	for (whereComponent wC : validationRules) {
		cout << wC.binOp << endl;
	}

	return parsedWhere;
}

