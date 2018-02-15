#define CATCH_CONFIG_FAST_COMPILE
// Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework
#include <string>
using std::string;



int kataFunc(const string & inputString) {
	return 0;
}



TEST_CASE("Testing that the function returns 0 for and empty string") {
	REQUIRE(kataFunc("") == 0);




}


