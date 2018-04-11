#include "tester.hpp"
#include "Data.test.hpp"
#include "../models/Data.hpp"

int testDataGuppies() {
    int countFail = 0;

    itTestUnit("add data to guppies");
    Data::getGuppies()->add(new Guppy(20, 30));
    if (!Data::getGuppies()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }

    Data::clear();
    return countFail;
}

int testDataPiranhas() {
    int countFail = 0;

    itTestUnit("add data to piranhas");
    Data::getPiranhas()->add(new Piranha(20, 30));
    if (!Data::getPiranhas()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }

    Data::clear();
    return countFail;
}

int testDataFoods() {
    int countFail = 0;

    itTestUnit("add data to foods");
    Data::getFoods()->add(new Food(20, 30));
    if (!Data::getPiranhas()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }
 
    Data::clear();      
}
int testDataCoins() {
    int countFail = 0;

    itTestUnit("add data to coins");
    Data::getCoins()->add(new Coin(20, *(new Position(2,3))));
    if (!Data::getCoins()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }

    Data::clear();
    return countFail;
}

int testData() {
    int countFail = 0;

    itTestClass("Model/Data");
    countFail += testDataGuppies();
    countFail += testDataPiranhas();
    countFail += testDataCoins();
    countFail += testDataFoods();
    
    return countFail;
}