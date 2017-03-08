// Application.cpp : Defines the entry point for the console application.
// Other team gave us dlibrary.h file too late, so we aren't using/including it.
#include "stdafx.h"
#include "json.hpp"
#include <iostream>
#include "database.h"
#include "record.h"
#include "table.h"
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <map>

struct business {
	std::string businessId;
	std::string name;
	std::string neighborhood;
	std::string address;
	std::string city;
	std::string state;
	std::string postalCode;
	double latitude;
	double longitude;
	double stars;
	double reviewCount;
	int isOpen;
	std::map < std::string, std::string > attributes;
	std::vector<std::string> categories;
	std::vector<std::string> hours;
	std::string type;
};

struct review {
	std::string reviewId;
	std::string userId;
	std::string businessId;
	double stars;
	std::string date;
	std::string text;
	double useful;
	double funny;
	double cool;
	std::string type;
};

struct user {
	std::string userId;
	std::string name;
	double reviewCount;
	std::string yelpingSince;
	std::vector<std::string> friends;
	double useful;
	double funny;
	double cool;
	double fans;
	std::vector<std::string> elite;
	double avgStars;
	double complimentHot;
	double complimentMore;
	double complimentProfile;
	double complimentCute;
	double complimentList;
	double complimentNote;
	double complimentPlain;
	double complimentCool;
	double complimentFunny;
	double complimentWriter;
	double complimentPhotos;
	std::string type;
};

using json = nlohmann::json;

std::vector<struct business> loadBusinessData(std::string fileName) {
	std::string line;
	std::vector<struct business> allBusiness;
	std::ifstream myfileBusiness(fileName);
	if (myfileBusiness.is_open()) {
		while (getline(myfileBusiness, line)) {
			/* Normalizing the data for hours. The JSON parser we are using now does not accept the null keyword.
			** Solved by manually searching for the "hours":null and changing to "hours":["null"]. We are ensuring that
			** in the end the database matches.
			*/
			std::size_t found = line.find("\"hours\":null");
			if (found != std::string::npos) {
				line.insert(found + 8, "[\"");
				line.insert(found + 14, "\"]");
			}

			auto business = json::parse(line);

			struct business businessstruct;
			businessstruct.businessId = business["business_id"];
			businessstruct.name = business["name"];
			businessstruct.neighborhood = business["neighborhood"];
			businessstruct.address = business["address"];
			businessstruct.city = business["city"];
			businessstruct.state = business["state"];
			businessstruct.postalCode = business["postal_code"];
			businessstruct.latitude = business["latitude"];
			businessstruct.longitude = business["longitude"];
			businessstruct.stars = business["stars"];
			businessstruct.reviewCount = business["review_count"];
			businessstruct.isOpen = business["is_open"];
			// There is an issue with the json internal mapping to a map. Must analyze and implement later.
			//businessstruct.attributes = business["attributes"]; @TODO Implement this later.
			businessstruct.categories = business["categories"];
			businessstruct.hours = business["hours"];
			businessstruct.type = business["type"];
			allBusiness.push_back(businessstruct);
		}

		myfileBusiness.close();
	}
	return allBusiness;
}

std::vector<struct user> loadUserData(std::string fileName) {
	std::string line;
	std::vector<struct user> allUser;
	std::ifstream myfileUser(fileName);
	if (myfileUser.is_open()) {
		while (getline(myfileUser, line)) {
			auto user = json::parse(line);
			struct user userStruct;
			userStruct.userId = user["user_id"];
			userStruct.name = user["name"];
			userStruct.reviewCount = user["review_count"];
			userStruct.yelpingSince = user["yelping_since"];
			userStruct.friends = user["friends"];
			userStruct.useful = user["useful"];
			userStruct.funny = user["funny"];
			userStruct.cool = user["cool"];
			userStruct.fans = user["fans"];
			userStruct.elite = user["elite"];
			userStruct.avgStars = user["average_stars"];
			userStruct.complimentHot = user["compliment_hot"];
			userStruct.complimentMore = user["compliment_more"];
			userStruct.complimentProfile = user["compliment_profile"];
			userStruct.complimentCute = user["compliment_cute"];
			userStruct.complimentList = user["compliment_list"];
			userStruct.complimentNote = user["compliment_note"];
			userStruct.complimentPlain = user["compliment_plain"];
			userStruct.complimentCool = user["compliment_cool"];
			userStruct.complimentFunny = user["compliment_funny"];
			userStruct.complimentWriter = user["compliment_writer"];
			userStruct.complimentPhotos = user["compliment_photos"];
			userStruct.type = user["type"];
			allUser.push_back(userStruct);
		}
		myfileUser.close();
	}
	return allUser;
}

std::vector<struct review> loadReviewData(std::string fileName) {
	std::string line;
	std::vector<struct review> allReview;
	std::ifstream myfileReview(fileName);
	if (myfileReview.is_open()) {
		while (getline(myfileReview, line)) {
			auto review = json::parse(line);
			struct review reviewStruct;
			reviewStruct.reviewId = review["review_id"];
			reviewStruct.userId = review["user_id"];
			reviewStruct.businessId = review["business_id"];
			reviewStruct.stars = review["stars"];
			reviewStruct.date = review["date"];
			reviewStruct.text = review["text"];
			reviewStruct.useful = review["useful"];
			reviewStruct.funny = review["funny"];
			reviewStruct.cool = review["cool"];
			reviewStruct.type = review["type"];
			allReview.push_back(reviewStruct);
		}
		myfileReview.close();
	}
	return allReview;
}

std::vector<std::string> getBusinessAttributes() {
	std::vector<std::string> businessAttributes = { "BusinessID", "Name", "Neighborhood",
		"Address", "City", "State", "PostalCode", "Latitude", "Longitude", "Stars", "ReviewCount",
		"IsOpen", "Attributes", "Categories", "Hours", "Type" };
	return businessAttributes;
}

std::vector<std::string> getUserAttributes() {
	std::vector<std::string> userAttributes = { "UserID", "Name", "ReviewCount", "YelpingSince",
		"Friends", "Useful", "Funny", "Cool", "Fans", "Elite", "AverageStars", "ComplimentHot",
		"ComplimentMore", "ComplimentProfile", "ComplimentCute", "ComplimentList", "ComplimentNote",
		"ComplimentPlain", "ComplimentCool", "ComplimentFunny", "ComplimentWriter", "ComplimentPhotos",
		"Type" };
	return userAttributes;
}

std::vector<std::string> getReviewAttributes() {
	std::vector<std::string> reviewAttributes = { "ReviewID", "UserID", "BusinessID", "Stars",
		"Date", "Text", "Useful", "Funny", "Cool", "Type" };
	return reviewAttributes;
}

Table addBusinessRecords(std::vector<struct business> businesses) {

	std::vector<std::string> businessAttributes = getBusinessAttributes();
	Table businessTable = Table(businessAttributes);

	for (unsigned int i = 0; i < businesses.size(); i++) {
		Record record = Record(businessAttributes.size());
		record[0] = businesses[i].businessId;
		record[1] = businesses[i].name;
		record[2] = businesses[i].neighborhood;
		record[3] = businesses[i].address;
		record[4] = businesses[i].city;
		record[5] = businesses[i].state;
		record[6] = businesses[i].postalCode;
		record[7] = std::to_string(businesses[i].latitude);
		record[8] = std::to_string(businesses[i].longitude);
		record[9] = std::to_string(businesses[i].stars);
		record[10] = std::to_string(businesses[i].reviewCount);
		record[11] = std::to_string(businesses[i].isOpen);
		//std::vector<std::string> attributes = businesses[i].attributes;
		std::string totalAttributes;
		//for (unsigned int j = 0; j < attributes.size(); j++) {
		//	totalAttributes += attributes[i] + ", ";
		//}
		if (totalAttributes != "") {
			totalAttributes = totalAttributes.substr(0, totalAttributes.length() - 2);
		}
		record[12] = totalAttributes;
		std::vector<std::string> categories = businesses[i].categories;
		std::string totalCategories;
		for (unsigned int j = 0; j < categories.size(); j++) {
			totalCategories += categories[j] + ", ";
		}
		if (totalCategories != "") {
			totalCategories = totalCategories.substr(0, totalCategories.length() - 2);
		}
		record[13] = totalCategories;
		std::vector<std::string> hours = businesses[i].hours;
		std::string totalHours;
		for (unsigned int j = 0; j < hours.size(); j++) {
			totalHours += hours[j] + ", ";
		}
		if (totalHours != "") {
			totalHours = totalHours.substr(0, totalHours.length() - 2);
		}
		record[14] = totalHours;
		record[15] = businesses[i].type;
		businessTable.insertRecord(record);
	}
	return businessTable;
}

Table addUserRecords(std::vector<struct user> users) {
	Table userTable = Table(getUserAttributes());
	for (unsigned int i = 0; i < users.size(); i++) {
		Record record = Record(getUserAttributes().size());
		record[0] = users[i].userId;
		record[1] = users[i].name;
		record[2] = std::to_string(users[i].reviewCount);
		record[3] = users[i].yelpingSince;
		std::vector<std::string> friends = users[i].friends;
		std::string totalFriends;
		for (unsigned int j = 0; j < friends.size(); j++) {
			totalFriends += friends[j] + ", ";
		}
		if (totalFriends != "") {
			totalFriends = totalFriends.substr(0, totalFriends.length() - 2);
		}
		record[4] = totalFriends;
		record[5] = std::to_string(users[i].useful);
		record[6] = std::to_string(users[i].funny);
		record[7] = std::to_string(users[i].cool);
		record[8] = std::to_string(users[i].fans);
		std::vector<std::string> elite = users[i].elite;
		std::string totalElite;
		for (unsigned int j = 0; j < elite.size(); j++) {
			totalElite += elite[j] + ", ";
		}
		if (totalElite != "") {
			totalElite = totalElite.substr(0, totalElite.length() - 2);
		}
		record[9] = totalElite;
		record[10] = std::to_string(users[i].avgStars);
		record[11] = std::to_string(users[i].complimentHot);
		record[12] = std::to_string(users[i].complimentMore);
		record[13] = std::to_string(users[i].complimentProfile);
		record[14] = std::to_string(users[i].complimentCute);
		record[15] = std::to_string(users[i].complimentList);
		record[16] = std::to_string(users[i].complimentNote);
		record[17] = std::to_string(users[i].complimentPlain);
		record[18] = std::to_string(users[i].complimentCool);
		record[19] = std::to_string(users[i].complimentFunny);
		record[20] = std::to_string(users[i].complimentWriter);
		record[21] = std::to_string(users[i].complimentPhotos);
		record[22] = users[i].type;
		userTable.insertRecord(record);
	}
	return userTable;
}

Table addReviewRecords(std::vector<struct review> reviews) {
	Table reviewTable = Table(getReviewAttributes());
	for (unsigned int i = 0; i < reviews.size(); i++) {
		Record record = Record(getReviewAttributes().size());
		record[0] = reviews[i].reviewId;
		record[1] = reviews[i].userId;
		record[2] = reviews[i].businessId;
		record[3] = std::to_string(reviews[i].stars);
		record[4] = reviews[i].date;
		record[5] = reviews[i].text;
		record[6] = std::to_string(reviews[i].useful);
		record[7] = std::to_string(reviews[i].funny);
		record[8] = std::to_string(reviews[i].cool);
		record[9] = reviews[i].type;
		reviewTable.insertRecord(record);
	}
	return reviewTable;
}

void displayUserInfo(Table table) {
	for (unsigned int i = 0; i < table.tableRecord.size(); i++) {
		std::cout << "User found!" << std::endl;
		std::cout << "Name: " << table.tableRecord[i][1] << std::endl;
		std::cout << "Review Count: " << table.tableRecord[i][2] << std::endl;
		std::cout << "Yelping Since: " << table.tableRecord[i][3] << std::endl;
		std::cout << "Friends: " << table.tableRecord[i][4] << std::endl;
		std::cout << "Useful: " << table.tableRecord[i][5] << std::endl;
		std::cout << "Funny: " << table.tableRecord[i][6] << std::endl;
		std::cout << "Cool: " << table.tableRecord[i][7] << std::endl;
		std::cout << "Fans: " << table.tableRecord[i][8] << std::endl;
		std::cout << "Elite: " << table.tableRecord[i][9] << std::endl;
		std::cout << "Average Stars: " << table.tableRecord[i][10] << std::endl;
		std::cout << "Compliment Hot: " << table.tableRecord[i][11] << std::endl;
		std::cout << "Compliment More: " << table.tableRecord[i][12] << std::endl;
		std::cout << "Compliment Profile: " << table.tableRecord[i][13] << std::endl;
		std::cout << "Compliment Cute: " << table.tableRecord[i][14] << std::endl;
		std::cout << "Compliment List: " << table.tableRecord[i][15] << std::endl;
		std::cout << "Compliment Note: " << table.tableRecord[i][16] << std::endl;
		std::cout << "Compliment Plain: " << table.tableRecord[i][17] << std::endl;
		std::cout << "Compliment Cool: " << table.tableRecord[i][18] << std::endl;
		std::cout << "Compliment Funny: " << table.tableRecord[i][19] << std::endl;
		std::cout << "Compliment Writer: " << table.tableRecord[i][20] << std::endl;
		std::cout << "Compliment Photos: " << table.tableRecord[i][21] << std::endl;
		std::cout << "Type: " << table.tableRecord[i][22] << std::endl;
	}
}

void displayBusinessInfo(Table table) {
	for (unsigned int i = 0; i < table.tableRecord.size(); i++) {
		std::cout << "Business found!" << std::endl;
		std::cout << "Name: " << table.tableRecord[i][1] << std::endl;
		std::cout << "Neighborhood: " << table.tableRecord[i][2] << std::endl;
		std::cout << "Address: " << table.tableRecord[i][3] << std::endl;
		std::cout << "City: " << table.tableRecord[i][4] << std::endl;
		std::cout << "State: " << table.tableRecord[i][5] << std::endl;
		std::cout << "Postal Code: " << table.tableRecord[i][6] << std::endl;
		std::cout << "Latitude: " << table.tableRecord[i][7] << std::endl;
		std::cout << "Longitude: " << table.tableRecord[i][8] << std::endl;
		std::cout << "Stars: " << table.tableRecord[i][9] << std::endl;
		std::cout << "Review Count: " << table.tableRecord[i][10] << std::endl;
		std::cout << "Is Open: " << table.tableRecord[i][11] << std::endl;
		std::cout << "Attributes: " << table.tableRecord[i][12] << std::endl;
		std::cout << "Categories: " << table.tableRecord[i][13] << std::endl;
		std::cout << "Hours: " << table.tableRecord[i][14] << std::endl;
		std::cout << "Type: " << table.tableRecord[i][15] << std::endl;
	}
}

void showBusinessReviews(Table table) {
	for (unsigned int i = 0; i < table.tableRecord.size(); i++) {
		std::cout << "Review ID: " << table.tableRecord[i][16] << std::endl;
		std::cout << "User ID: " << table.tableRecord[i][17] << std::endl;
		std::cout << "Business ID: " << table.tableRecord[i][0] << std::endl;
		std::cout << "Stars: " << table.tableRecord[i][19] << std::endl;
		std::cout << "Date: " << table.tableRecord[i][20] << std::endl;
		std::cout << "Text: " << table.tableRecord[i][21] << std::endl;
		std::cout << "Useful: " << table.tableRecord[i][22] << std::endl;
		std::cout << "Funny: " << table.tableRecord[i][23] << std::endl;
		std::cout << "Cool: " << table.tableRecord[i][24] << std::endl;
		std::cout << "Type: " << table.tableRecord[i][25] << std::endl;
		std::cout << std::endl;
	}
}

void showUserReviews(Table table) {
	for (unsigned int i = 0; i < table.tableRecord.size(); i++) {
		std::cout << "Review ID: " << table.tableRecord[i][23] << std::endl;
		std::cout << "User ID: " << table.tableRecord[i][0] << std::endl;
		std::cout << "Business ID: " << table.tableRecord[i][25] << std::endl;
		std::cout << "Stars: " << table.tableRecord[i][26] << std::endl;
		std::cout << "Date: " << table.tableRecord[i][27] << std::endl;
		std::cout << "Text: " << table.tableRecord[i][28] << std::endl;
		std::cout << "Useful: " << table.tableRecord[i][29] << std::endl;
		std::cout << "Funny: " << table.tableRecord[i][30] << std::endl;
		std::cout << "Cool: " << table.tableRecord[i][31] << std::endl;
		std::cout << "Type: " << table.tableRecord[i][32] << std::endl;
		std::cout << std::endl;
	}
}

Table crossJoin(Table tblOne, Table tblTwo) {
	if (tblOne.getAttributeNames().empty()) {
		if (tblTwo.getAttributeNames().empty()) {
			return Table();
		}
		else {
			return tblTwo;
		}
	}
	else if (!tblOne.getAttributeNames().empty()) {
		if (tblTwo.getAttributeNames().empty()) {
			return tblOne;
		}
	}
	std::vector<std::string> totalAttributes;
	unsigned int recordIndex = 0;
	unsigned int tableOneIndex = 0;
	unsigned int tableTwoIndex = 0;
	std::vector<std::string> tblOneAttributes = tblOne.getAttributeNames();
	std::vector<std::string> tblTwoAttributes = tblTwo.getAttributeNames();
	unsigned int count = 0;
	for (unsigned int i = 0; i < tblOneAttributes.size(); i++) {
		for (unsigned int j = 0; j < tblTwoAttributes.size(); j++) {
			if (tblOneAttributes[i] == tblTwoAttributes[j]) {
				count++;
				std::string attributeOne = tblOneAttributes[i];
				std::string attributeTwo = tblTwoAttributes[j];
				attributeOne = std::to_string(count) + attributeOne;
				count++;
				attributeTwo = std::to_string(count) + attributeTwo;
				tblOneAttributes[i] = attributeOne;
				tblTwoAttributes[j] = attributeTwo;
			}
			count = 0;
		}
	}
	totalAttributes = tblOneAttributes;
	totalAttributes.insert(totalAttributes.end(), tblTwoAttributes.begin(), tblTwoAttributes.end());
	unsigned int attributeSize = totalAttributes.size();
	Table crossJoinTable(totalAttributes);
	for (int i = 0; i < tblOne.getTableSize(); i++) {
		for (int j = 0; j < tblTwo.getTableSize(); j++) {
			Record newRecord(attributeSize);
			while (tableOneIndex < tblOneAttributes.size()) {
				newRecord[recordIndex] = tblOne.tableRecord[i][tableOneIndex];
				tableOneIndex++;
				recordIndex++;
			}
			while (tableTwoIndex < tblTwoAttributes.size()) {
				newRecord[recordIndex] = tblTwo.tableRecord[j][tableTwoIndex];
				tableTwoIndex++;
				recordIndex++;
			}
			tableTwoIndex = 0;
			tableOneIndex = 0;
			recordIndex = 0;
			crossJoinTable.insertRecord(newRecord);
		}
	}
	return crossJoinTable;
}
Table naturalJoin(Table tblOne, Table tblTwo) {
	if (tblOne.getAttributeNames().empty()) {
		if (tblTwo.getAttributeNames().empty()) {
			std::cerr << "Both tables are empty!";
		}
		else {
			std::cerr << "There is no key!";
		}
	}
	else if (!tblOne.getAttributeNames().empty()) {
		if (tblTwo.getAttributeNames().empty()) {
			std::cerr << "There are no attributes matching!";
		}
	}
	unsigned int tblOneAttribute = 0;
	unsigned int tblTwoAttribute = 0;
	std::vector<std::string> tblOneAttributes = tblOne.getAttributeNames();
	std::vector<std::string> tblTwoAttributes = tblTwo.getAttributeNames();
	bool verify = false;
	std::string tableKey;
	tableKey = tblTwo.getTableKey();
	if (tblTwo.getTableKey() != "") {
		for (unsigned int i = 0; i < tblOneAttributes.size(); i++) {
			if (tblOneAttributes[i] == tblTwo.getTableKey()) {
				verify = true;
				tblOneAttribute = i;
				break;
			}
		}
	}
	else {
		std::cerr << "There is no key!";
	}
	for (unsigned int i = 0; i < tblTwoAttributes.size(); i++) {
		if (tblTwoAttributes[i] == tableKey) {
			tblTwoAttribute = i;
			break;
		}
	}
	if (!verify) {
		std::cerr << "There are no attributes matching!";
	}
	unsigned int recordIndex = 0;
	unsigned int tableOneIndex = 0;
	std::vector<std::string> totalAttributes;
	totalAttributes = tblOneAttributes;
	for (unsigned int i = 0; i < tblTwoAttributes.size(); i++) {
		if (tblTwoAttributes[i] != tableKey) {
			totalAttributes.push_back(tblTwoAttributes[i]);
		}
	}
	unsigned int attributeSize = totalAttributes.size();
	unsigned int tblTwoElement = 0;
	Table naturalJoinTable(totalAttributes);
	for ( int i = 0; i < tblOne.getTableSize(); i++) {
		Record newRecord(attributeSize);
		while (tableOneIndex < tblOneAttributes.size()) {
			newRecord[recordIndex] = tblOne.tableRecord[i][tableOneIndex];
			tableOneIndex++;
			recordIndex++;
		}
		for (int j = 0; j < tblTwo.getTableSize(); j++) {
			if (tblOne.tableRecord[i][tblOneAttribute] == tblTwo.tableRecord[j][tblTwoAttribute]) {
				while (tblTwoElement < tblTwoAttributes.size()) {
					if (tblTwoElement != tblTwoAttribute) {
						newRecord[recordIndex] = tblTwo.tableRecord[j][tblTwoElement];
						recordIndex++;
					}
					tblTwoElement++;
				}
				tblTwoElement = 0;
				break;
			}
		}
		tableOneIndex = 0;
		recordIndex = 0;
		naturalJoinTable.insertRecord(newRecord);
	}
	return naturalJoinTable;
}


int main() {

	std::string businessJSONFilename = "business.json";
	std::string userJSONFilename = "user.json";
	std::string reviewJSONFilename = "review.json";

	std::vector<struct business> businesses = loadBusinessData(businessJSONFilename);
	std::vector<struct user> users = loadUserData(userJSONFilename);
	std::vector<struct review> reviews = loadReviewData(reviewJSONFilename);

	Database db = Database();

	Table businessTable = addBusinessRecords(businesses);
	Table userTable = addUserRecords(users);
	Table reviewTable = addReviewRecords(reviews);


	db.addTable("Business", businessTable);
	db.addTable("User", userTable);
	db.addTable("Review", reviewTable);

	std::cout << "Welcome to the Yelp Database Application!" << std::endl;

	std::string again = "y";
	//while (again == "y") {

	std::string choice;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "DU: Display User Information" << std::endl;
	std::cout << "DB: Display Business Information" << std::endl;
	std::cout << "C: Combine Information from Two Tables" << std::endl;
	std::cout << "DR: Display all Businesses with a Certain Rating" << std::endl;
	std::cout << "DSBR: Display Summary for Business Ratings" << std::endl;
	std::cout << "DSUR: Display Reviews by Name" << std::endl;
	std::cin.clear();
	std::cin >> choice;
	std::cin.ignore(100, '\n');
	if (choice == "DU") {
		std::cout << "What is User ID of the User?" << std::endl;
		std::string userId;
		std::cin >> userId;
		//Test string: KpkOkG6RIf4Ra25Lhhxf1A
		Table table = db.Querry("*", "User", "UserID = " + userId);
		displayUserInfo(table);
	}
	else if (choice == "DB") {
		std::cout << "What is Business ID of the Business?" << std::endl;
		std::string businessId;
		std::cin >> businessId;
		//Test string: 2aFiy99vNLklCx3T_tGS9A 
		Table table = db.Querry("*", "Business", "BusinessID = " + businessId);
		displayBusinessInfo(table);
	}
	else if (choice == "C") {
		int choiceJoin;
		std::cout << "Do you want to: " << std::endl;
		std::cout << "1. Show reviews for a business?" << std::endl;
		std::cout << "2. Show reviews for a user?" << std::endl;
		std::cin >> choiceJoin;
		if (choiceJoin == 1) {
			//Test string: 2aFiy99vNLklCx3T_tGS9A 
			std::cout << "What is Business ID of the Business?" << std::endl;
			std::string businessId;
			std::cin >> businessId;
			Table businessReviewTable;
			businessReviewTable = crossJoin(businessTable, reviewTable);
			db.addTable("BusinessReview", businessReviewTable);
			Table businessIDTable = db.Querry("*", "BusinessReview", "1BusinessID = " + businessId);
			db.addTable("BusinessIDTable", businessIDTable);
			Table finalTable = db.Querry("*", "BusinessIDTable", "2BusinessID = " + businessId);
			showBusinessReviews(finalTable);
		}
		else if (choiceJoin == 2) {
			//Test string: KpkOkG6RIf4Ra25Lhhxf1A 
			std::cout << "What is User ID of the User?" << std::endl;
			std::string userId;
			std::cin >> userId;
			Table userReviewTable;
			userReviewTable = crossJoin(userTable, reviewTable);
			db.addTable("UserReview", userReviewTable);
			Table userIDTable = db.Querry("*", "UserReview", "1UserID = " + userId);
			db.addTable("UserIDTable", userIDTable);
			Table finalTable = db.Querry("*", "UserIDTable", "2UserID = " + userId);
			showUserReviews(finalTable);
		}
		else {
			std::cout << "You have entered the wrong code!" << std::endl;
		}
	}
	else if (choice == "DR") {
		std::cout << "Select an option from 1-5: ";
		int number;
		std::cin >> number;

		Table query;
		switch (number) {
		case 1:
			query = db.Querry("Name, City, State, Hours", "Business", "Stars = 1.000000");
			break;
		case 2:
			query = db.Querry("Name, City, State, Hours", "Business", "Stars = 2.000000");
		case 3:
			query = db.Querry("Name, City, State, Hours", "Business", "Stars = 3.000000");
		case 4:
			query = db.Querry("Name, City, State, Hours", "Business", "Stars = 4.000000");
		case 5:
			query = db.Querry("Name, City, State, Hours", "Business", "Stars = 5.000000");
		}

		for (unsigned int i = 0; i < query.tableRecord.size(); i++) {
			Record rd = query.tableRecord[i];

			for (int j = 0; j < rd.getRecordSize(); j++) {
				std::cout << rd[j] << " | ";
			}

			std::cout << std::endl;
		}
	}
	else if (choice == "DSUR") {
		std::cout << "Get all reviews by reviewer name: ";
		std::string username;
		std::getline(std::cin, username);

		std::vector<Table> allTables = db.getTables();
		Table usernames = allTables[1];
		usernames.specifyKey("UserID");
		Table reviews = allTables[2];

		//Table desiredUsernames(usernames.getAttributeNames());
		Table tb = naturalJoin(reviews, usernames);

		for (Record rd : tb.tableRecord) {
			if (rd[1] == username) {
				std::cout << "Name: " << rd[1] << " - Review Count: " << rd[2] << " - Text: " << rd[27] << std::endl;
			}
		}
	}
	else if (choice == "DSBR") {
		std::cout << "Enter a business name: ";
		std::string str;
		std::getline(std::cin, str);

		/* The given database does not provide working query functionality and leaves all records public.
			Utilizing the improper implementation to the best of our ability, manually searching for the proper business name.
			Grab business ID after and then match with the reviews for matching business IDs.
		*/
		std::vector<Table> allTables = db.getTables();
		Table businesses = allTables[0];

		Table desiredBusiness(businesses.getAttributeNames());
		for (Record rd : businesses.tableRecord) {
			if (rd[1] == str) {
				desiredBusiness.insertRecord(rd);
				break;
			}
		}

		if (desiredBusiness.getTableSize() == 1) {
			Record rd = desiredBusiness.tableRecord[0];

			std::string businessID = rd[0];

			Table reviewsForIDOnly = db.Querry("BusinessID, Stars, Date", "Review", "BusinessID = " + businessID);
			std::tuple<std::string, std::string, std::string> t = reviewsForIDOnly.findRoutine("Stars");

			std::cout << "Business: " << str << std::endl;
			std::cout << "Number of Ratings: " << std::get<0>(t) << std::endl;
			std::cout << "Lowest Rating: " << std::get<2>(t) << std::endl;
			std::cout << "Maximum Rating: " << std::get<1>(t) << std::endl;
		}
		else if (choice == "DSUR") {
			std::cout << "Enter a user ID: ";
			std::string str;
			std::getline(std::cin, str);
			Table userName = db.Querry("*", "User", "UserID = KpkOkG6RIf4Ra25Lhhxf1A");

			if (userName.getTableSize() > 0) {
				Record rd = userName.tableRecord[0];

				//std::string businessID = rd[0];
				std::string userID = "KpkOkG6RIf4Ra25Lhhxf1A";

				Table reviewsForIDOnly = db.Querry("BusinessID, Stars, Date", "Review", "BusinessID = 2LfIuF3_sX6uwe-IR-P0jQ");
				std::cout << reviewsForIDOnly.tableRecord.size() << std::endl;
				std::tuple<std::string, std::string, std::string> t = reviewsForIDOnly.findRoutine("Stars");

				std::cout << "Restaurant: " << str << std::endl;
				std::cout << "Number of Ratings: " << std::get<0>(t) << std::endl;
				std::cout << "Lowest Rating: " << std::get<1>(t) << std::endl;
				std::cout << "Maximum Rating: " << std::get<2>(t) << std::endl;
			}
			else {
				std::cout << "Unable to find a business with that name." << std::endl;
			}
		}
		else {

		}
	}
		/*std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Again?";
		std::cin >> again;*/
	//}
		//std::cout << "Again? " << std::endl;
		//std::cin >> again;
	//} while (again == "Y");
	
	// Display business with range of ratings from x to x.
	// Summary of reviews and compliments for a user.
	// Summary information about reviews/users for a business.
	// Table for 5 star/4/3/2/1
	// Favorite business from a user
	// Display user with the most number of reviews
	// Display user with the minimum number of reviews
	// Coolest user
	// Oldest user
	// business search by state
	// business search by city
	// User with the most number of friends.
	// Longest review from a user

	return 0;
}