#include "tester.hpp"
#include "Food.test.hpp"
#include "../models/Food.hpp"


int testFoodConstructor(){
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
    f->move(225,1.0);
    if( f->getPosition()->getAbsis() == 100 && f->getPosition()->getOrdinate() == 225 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    itTestUnit("move to destination greater than max Velocity");
    f = new Food(100, 200);
    f->move(235,1.0);
    if( f->getPosition()->getAbsis() == 100 && f->getPosition()->getOrdinate() == 230 ) {
        itSuccess();
    } else {
        itFailed(); countFail++;
    }
    delete f;

    return countFail;
}

int testFood(){
    int countFail = 0;
    itTestClass("Model/Food");
    countFail += testFoodConstructor();
    countFail += testFoodMove();

    return countFail;
}
    