#include <iostream>
#include "tests/Coin.test.hpp"
#include "tests/Data.test.hpp"
#include "tests/Position.test.hpp"
#include "tests/LinkedList.test.hpp"
#include "tests/Snail.test.hpp"

int main() {
    int countFail = 0;

    countFail += testCoin();
    countFail += testData();
    countFail += testPosition();
    countFail += testLinkedList();
	countFail += testSnail();
    std::cout << "Done testing with " << countFail << " number(s) of fail test" << std::endl;

    return 0;
}
