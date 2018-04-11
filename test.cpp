#include <iostream>
#include "tests/Coin.test.hpp"
#include "tests/Data.test.hpp"
#include "tests/Position.test.hpp"
#include "tests/LinkedList.test.hpp"
<<<<<<< HEAD
#include "tests/Snail.test.hpp"
=======
#include "tests/Food.test.hpp"
#include "tests/LinkedListItem.test.hpp"
>>>>>>> 0323b6d4cedd1ce70207a01164f67f743bb1e6a7

int main() {
    int countFail = 0;

    countFail += testCoin();
    countFail += testData();
    countFail += testPosition();
    countFail += testLinkedList();
	countFail += testSnail();
    countFail += testFood();
    countFail += testLinkedListItem();

    std::cout << "Done testing with " << countFail << " number(s) of fail test" << std::endl;

    return 0;
}
