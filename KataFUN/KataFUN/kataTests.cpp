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
		if (temp < 0) {
			throw "A negative number was given";
		}
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
	REQUIRE(kataFunc("1, 2") == 3);
	REQUIRE(kataFunc("1000, 1300") == 2300);
	REQUIRE(kataFunc("0, -1") == -1);

}

TEST_CASE("Two numbers new line delimited returns the sum") {
	REQUIRE(kataFunc("1 \n1") == 2);
	REQUIRE(kataFunc("1\n2") == 3);
	REQUIRE(kataFunc("1000\n1300") == 2300);
	REQUIRE(kataFunc("0\n-1") == -1);
}

TEST_CASE("Three numbers new line delimited returns the sum") {
	REQUIRE(kataFunc("1 \n1, 1") == 3);
	REQUIRE(kataFunc("1\n2, 1") == 4);
	REQUIRE(kataFunc("1000\n1300\n1") == 2301);
	REQUIRE(kataFunc("0\n-1, 1") == 0);
}

TEST_CASE("Negative Numbers throw an exception") {
	REQUIRE_THROWS(kataFunc("1,1, -1"));
	REQUIRE_THROWS(kataFunc("-11,1, -1"));
	REQUIRE_THROWS(kataFunc("11,-11, 1"));
	REQUIRE_THROWS(kataFunc("-11,-1, -1"));

}