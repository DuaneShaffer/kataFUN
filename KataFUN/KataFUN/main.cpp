// kataFUN 
// Duane Shaffer and Samuel Grenon
// Feb 14, 2018
//
// For CS 372 Spring 2018
// Using an altered form of main.cpp from Glen G. Chappell.

#define CATCH_CONFIG_FAST_COMPILE
                             // Disable some features for faster compile
#define CATCH_CONFIG_RUNNER  // We write our own main

#include "catch.hpp"         // For the "Catch" unit-testing framework
#include <iostream>          // For std::cout, endl, cin


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc, char *argv[])
{
    Catch::Session session;  // Primary Catch object
    int catchresult;         // Catch return code; for return by main

    // Handle command line
    catchresult = session.applyCommandLine(argc, argv);

    if (!catchresult)  // Continue only if no command-line error
    {
        // Run test suites
        std::cout << "BEGIN tests for cs372 Kata"
                  << std::endl;
        catchresult = session.run();
        std::cout << "END tests for cs372 Kata"
                  << std::endl
                  << std::endl;
    }

    // Wait for user
    std::cout << "Press ENTER to quit ";
    while (std::cin.get() != '\n') ;

    // Program return value is return code from Catch
    return catchresult;
}