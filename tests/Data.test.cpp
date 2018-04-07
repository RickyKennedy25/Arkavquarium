#include "tester.hpp"
#include "../models/Data.hpp"

int testDataGuppies() {
    int countFail = 0;

    itTestUnit("add data to guppies");
    Data::getGuppies()->add(new Guppy());

    if (!Data::getGuppies()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }

    Data::clear();
    return countFail;
}

int testDataPiranhas() {
    int countFail = 0;

    itTestUnit("add data to piranhas");
    Data::getPiranhas()->add(new Piranha());

    if (!Data::getPiranhas()->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }

    Data::clear();
    return countFail;
}

int testData() {
    int countFail = 0;

    itTestClass("Model/Data");
    countFail += testDataGuppies();
    countFail += testDataPiranhas();
    
    return countFail;
}