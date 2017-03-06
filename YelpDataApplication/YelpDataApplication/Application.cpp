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
	std::vector<std::string> businessAttributes = { "Business ID", "Name", "Neighborhood",
		"Address", "City", "State", "Postal Code", "Latitude", "Longitude", "Stars", "Review Count",
		"Is Open", "Attributes", "Categories", "Hours", "Type" };
	return businessAttributes;
}

std::vector<std::string> getUserAttributes() {
	std::vector<std::string> userAttributes = { "User ID", "Name", "Review Count", "Yelping Since",
		"Friends", "Useful", "Funny", "Cool", "Fans", "Elite", "Average Stars", "Compliment Hot",
		"Compliment More", "Compliment Profile", "Compliment Cute", "Compliment List", "Compliment Note",
		"Compliment Plain", "Compliment Cool", "Compliment Funny", "Compliment Writer", "Compliment Photos",
		"Type" };
	return userAttributes;
}

std::vector<std::string> getReviewAttributes() {
	std::vector<std::string> reviewAttributes = { "Review ID", "User ID", "Business ID", "Stars",
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
	userTable.specifyKey("User ID");
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

void displayUserInfo(std::string userId, Table userTable) {
	
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

	Table test = db.Querry("*", "Business", "City = Fellbach");
	std::cout << test.getTableSize() << std::endl;

	/*for (int i = 0; i < test.tableRecord.size(); i++) {
	
	}*/
	

	/*std::vector<struct business> businesses = parseBusiness();
	std::vector<struct user> users = parseUser();
	std::vector<struct review> reviews = parseReview();
	Database db = Database();
	db.addTable("Business", businessTable);
	db.addTable("User", userTable);
	db.addTable("Review", reviewTable);

	std::string choice;
	std::cout << "Welcome to the Yelp Database Application!" << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "DU: Display User Information" << std::endl;
	std::cout << "DB: Display Business Information" << std::endl;
	std::cout << "C: Combine Information from Two Tables" << std::endl;
	std::cin >> choice;
	if (choice == "DU") {
		std::cout << "What is User ID of the User?" << std::endl;
		std::string userId;
		std::cin >> userId;
		displayUserInfo(userId, userTable);
	}
	else if (choice == "DB") {

	}
	else if (choice == "C") {

	}
	else {

	}*/
	return 0;
}


