#include "tester.hpp"
#include "Food.test.hpp"
#include "../models/Food.hpp"


int testFoodContructor(){
    int countFail = 0;
    Food *f;
    
    itTestUnit("constructor Food and test Food Position");
    f = new Food(100, 200);
    if( f->getPosition()->getAbsis() == 100 && f->getPosition()->getOrdinate() == 200 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    itTestUnit("test Food price");
    f = new Food(100, 200);
    if( f->getPrice() == 10 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    return countFail;
}

int testFoodMove(){
    int countFail = 0;
    Food *f;

    itTestUnit("move to destination less than max Velocity");
    f = new Food(100, 200);
    f->move(125,1.0);
    if( f->getPosition()->getOrdinate() == 100 && f->getPosition()->getOrdinate() == 125 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    itTestUnit("move to destination greater than max Velocity");
    f = new Food(100, 200);
    f->move(135,1.0);
    if( f->getPosition()->getOrdinate() == 100 && f->getPosition()->getOrdinate() == 130 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    return countFail;
}

int foodTest(){
    int countFail = 0;
    itTestClass("Model/Food");
    countFail += foodTestConstructor();
    countFail += foodTestMove();

    return countFail;
}
    