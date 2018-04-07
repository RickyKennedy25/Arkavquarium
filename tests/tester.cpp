#include <iostream>
#include "tester.hpp"

void itTestClass(std::string className) {
    std::cout << "Testing " << className << std::endl;
}

void itTestUnit(std::string desc) {
    std::cout << "  Test " << desc << " : ";
}

void itFailed() {
    std::cout << "\033[1;31mfail\033[0m\n";
}

void itSuccess() {
    std::cout << "\033[1;32msuccess\033[0m\n";
}