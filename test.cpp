#include <iostream>
#include "tests/Data.test.hpp"
#include "tests/Position.test.hpp"
#include "tests/LinkedList.test.hpp"

int main() {
    int countFail = 0;

    countFail += testData();
    countFail += testPosition();
    countFail += testLinkedList();

    std::cout << "Done testing with " << countFail << " number(s) of fail test" << std::endl;

    return 0;
}
