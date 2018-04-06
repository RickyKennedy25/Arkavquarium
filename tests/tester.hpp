#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>

void itTestClass(std::string className);
void itTestUnit(std::string desc);
void itFailed();
void itSuccess();

#endif