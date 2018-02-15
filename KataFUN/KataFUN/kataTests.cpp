#define CATCH_CONFIG_FAST_COMPILE
// Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout;
using std::endl;


int kataFunc(const string & inputString) {

	istringstream inputStream(inputString);
	int numberToReturn = 0;
	int temp = 0;
	
	while (inputStream >> temp) {
		numberToReturn += temp;
		inputStream.ignore(1);
	}


	if (inputString.empty() && numberToReturn != 0) {
		cout << "You would've failed the test!!!!" << endl;
		return 0;
	}
	return numberToReturn;
}



TEST_CASE("Testing that the function returns 0 for and empty string") {
	REQUIRE(kataFunc("") == 0);
}

TEST_CASE("A single number returns its value") {
	REQUIRE(kataFunc("1") == 1);
	REQUIRE(kataFunc("0") == 0);
	REQUIRE(kataFunc("-100") == -100);
	REQUIRE(kataFunc("1000000") == 1000000);
	REQUIRE(kataFunc("-1000000") == -1000000);
}

TEST_CASE("Two numbers comma delimited returns the sum") {
	REQUIRE(kataFunc("1, 1") == 2);
}
