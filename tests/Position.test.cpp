#include "tester.hpp"
#include "../models/Position.hpp"

int testPositionAbsis() {
    int countFail = 0;
    Position *p;

    itTestUnit("absis constructor");
    p = new Position(2.5, 3.5);
    if (p->getAbsis() == 2.5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    itTestUnit("absis setter and getter");
    p = new Position();
    p->setAbsis(2.5);
    if (p->getAbsis() == 2.5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    return countFail;
}

int testPositionOrdinate() {
    int countFail = 0;
    Position *p;

    itTestUnit("ordinate constructor");
    p = new Position(2.5, 3.5);
    if (p->getAbsis() == 3.5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    itTestUnit("ordinate setter and getter");
    p = new Position();
    p->setOrdinate(2.5);
    if (p->getOrdinate() == 2.5) { itSuccess(); }
    else { itFailed(); countFail++; }

    return countFail;
}

int testPositionMove() {
    int countFail = 0;
    Position *source, *dest;

    itTestUnit("moving to destination in less than range");
    source = new Position(100,100);
    dest = new Position(160,180);
    source->move(*dest, 100);
    if (source->getAbsis() == 160 && source->getOrdinate() == 180) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving to destination in more than range");
    source = new Position(100,100);
    dest = new Position(160,180);
    source->move(*dest, 50);
    if (source->getAbsis() == 130 && source->getOrdinate() == 140) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    return countFail;
}

int testPositionEqual() {
    int countFail = 0;
    Position *p1, *p2;

    itTestUnit("checking points are equal");
    p1 = new Position(2.5, 3.5);
    p2 = new Position(2.500, 3.500);
    if (p1 == p2) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p1;
    delete p2;

    itTestUnit("checking points are not equal");
    p1 = new Position(2.5, 3.5);
    p2 = new Position(2.5001, 3.5001);
    if (!(p1 == p2)) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p1;
    delete p2;

    return countFail;
}

int testPosition() {
    int countFail = 0;

    itTestClass("Model/Position");
    countFail += testPositionAbsis();
    countFail += testPositionOrdinate();
    countFail += testPositionMove();
    countFail += testPositionEqual();
    
    return countFail;
}