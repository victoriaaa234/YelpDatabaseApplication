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
	std::vector<std::string> attributes;
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

std::vector<struct business> parseBusiness() {
	std::string line;
	std::vector<struct business> allBusiness;
	std::ifstream myfileBusiness("business.json");
	if (myfileBusiness.is_open()) {
		while (getline(myfileBusiness, line)) {
			auto business = json::parse(line);
			struct business businessStruct;
			businessStruct.businessId = business["business_id"];
			businessStruct.name = business["name"];
			businessStruct.neighborhood = business["neighborhood"];
			businessStruct.address = business["address"];
			businessStruct.city = business["city"];
			businessStruct.state = business["state"];
			businessStruct.postalCode = business["postal_code"];
			businessStruct.latitude = business["latitude"];
			businessStruct.longitude = business["longitude"];
			businessStruct.stars = business["stars"];
			businessStruct.reviewCount = business["review_count"];
			businessStruct.isOpen = business["is_open"];
			businessStruct.attributes = business["attributes"];
			businessStruct.categories = business["categories"];
			businessStruct.hours = business["hours"];
			businessStruct.type = business["type"];
			allBusiness.push_back(businessStruct);
		}
		std::cout << allBusiness.size() << std::endl;

		for (unsigned int i = 0; i < allBusiness.size(); i++) {
			std::cout << allBusiness[i].businessId<< std::endl;
		}

		myfileBusiness.close();
	}
	return allBusiness;
}

std::vector<struct user> parseUser() {
	std::string line;
	std::vector<struct user> allUser;
	std::ifstream myfileUser("user.json");
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
	std::cout << allUser.size() << std::endl;

	for (unsigned int i = 0; i < allUser.size(); i++) {
		std::cout << allUser[i].userId << std::endl;
	}
	return allUser;
}

std::vector<struct review> parseReview() {
	std::string line;
	std::vector<struct review> allReview;
	std::ifstream myfileReview("review.json");
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
	std::cout << allReview.size() << std::endl;

	for (unsigned int i = 0; i < allReview.size(); i++) {
		std::cout << allReview[i].reviewId << std::endl;
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
	Table businessTable = Table(getBusinessAttributes());
	for (unsigned int i = 0; i < businesses.size(); i++) {
		Record record = Record(getBusinessAttributes().size());
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
		std::vector<std::string> attributes = businesses[i].attributes;
		std::string totalAttributes;
		for (unsigned int j = 0; j < attributes.size(); j++) {
			totalAttributes += attributes[i] + ", ";
		}
		if (totalAttributes != "") {
			totalAttributes = totalAttributes.substr(0, totalAttributes.length() - 2);
		}
		record[12] = totalAttributes;
		std::vector<std::string> categories = businesses[i].categories;
		std::string totalCategories;
		for (unsigned int j = 0; j < categories.size(); j++) {
			totalCategories += categories[i] + ", ";
		}
		if (totalCategories != "") {
			totalCategories = totalCategories.substr(0, totalCategories.length() - 2);
		}
		record[13] = totalCategories;
		std::vector<std::string> hours = businesses[i].hours;
		std::string totalHours;
		for (unsigned int j = 0; j < hours.size(); j++) {
			totalHours += hours[i] + ", ";
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
			totalFriends += friends[i] + ", ";
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
			totalElite += elite[i] + ", ";
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

/*Team that gave us database implemented iterators wrong. Therefore, we are unable to use
the iterators from their database to traverse the records of a specific table.*/

void displayUserInfo(std::string userId, std::vector<struct user> users) {
	int location = -1;
	for (unsigned int i = 0; i < users.size(); i++) {
		if (users[i].userId == userId) {
			location = i;
			std::cout << "Found User!" << std::endl;
			std::cout << "Name: " << users[i].name << std::endl;
			std::cout << "Review Count: " << users[i].reviewCount << std::endl;
			std::cout << "Yelping Since: " << users[i].yelpingSince << std::endl;
			std::cout << "Friends: ";
			std::string friends;
			for (unsigned int j = 0; j < users[i].friends.size(); j++) {
				friends += users[i].friends[j] + ", ";
			}
			friends = friends.substr(0, friends.length() - 2);
			std::cout << friends << std::endl;
			std::cout << "Useful: " << users[i].useful << std::endl;
			std::cout << "Funny: " << users[i].funny << std::endl;
			std::cout << "Cool: " << users[i].cool << std::endl;
			std::cout << "Fans: " << users[i].fans << std::endl;
			std::cout << "Elite: ";
			std::string elite;
			for (unsigned int j = 0; j < users[i].elite.size(); j++) {
				elite += users[i].elite[j] + ", ";
			}
			elite = elite.substr(0, elite.length() - 2);
			std::cout << elite << std::endl;
			std::cout << "Average Stars: " << users[i].avgStars << std::endl;
			std::cout << "Compliment Hot: " << users[i].complimentHot << std::endl;
			std::cout << "Compliment More: " << users[i].complimentMore << std::endl;
			std::cout << "Compliment Profile: " << users[i].complimentProfile << std::endl;
			std::cout << "Compliment Cute: " << users[i].complimentCute << std::endl;
			std::cout << "Compliment List: " << users[i].complimentList << std::endl;
			std::cout << "Compliment Note: " << users[i].complimentNote << std::endl;
			std::cout << "Compliment Plain: " << users[i].complimentPlain << std::endl;
			std::cout << "Compliment Cool: " << users[i].complimentCool << std::endl;
			std::cout << "Compliment Funny: " << users[i].complimentFunny<< std::endl;
			std::cout << "Compliment Writer: " << users[i].complimentWriter << std::endl;
			std::cout << "Compliment Photos: " << users[i].complimentPhotos << std::endl;
			std::cout << "Type: " << users[i].type << std::endl;
			break;
		}
	}
	if (location == -1) {
		std::cout << "Couldn't find User!" << std::endl;
	}
}

int main() {
	std::vector<struct business> businesses = parseBusiness();
	std::vector<struct user> users = parseUser();
	std::vector<struct review> reviews = parseReview();
	Database db = Database();
	Table businessTable = addBusinessRecords(businesses);
	Table userTable = addUserRecords(users);
	Table reviewTable = addReviewRecords(reviews);
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
		displayUserInfo(userId, users);
	}
	else if (choice == "DB") {

	}
	else if (choice == "C") {

	}
	else {

	}
	return 0;
}


