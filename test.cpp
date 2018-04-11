#include <iostream>
#include "tests/Coin.test.hpp"
#include "tests/Data.test.hpp"
#include "tests/Position.test.hpp"
#include "tests/LinkedList.test.hpp"
#include "tests/Food.test.hpp"
#include "tests/LinkedListItem.test.hpp"

int main() {
    int countFail = 0;

    countFail += testCoin();
    countFail += testData();
    countFail += testPosition();
    countFail += testLinkedList();
    countFail += testFood();
    countFail += testLinkedListItem();

    std::cout << "Done testing with " << countFail << " number(s) of fail test" << std::endl;

    return 0;
}
