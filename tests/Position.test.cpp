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

    itTestUnit("random absis constructor");
    p = new Position(1, 10000);
    if (p->getAbsis() <= 1 && p->getAbsis() >= 0) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    itTestUnit("absis setter and getter");
    p = new Position(0, 0);
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
    if (p->getOrdinate() == 3.5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    itTestUnit("random ordinate constructor");
    p = new Position(10000, 1);
    if (p->getOrdinate() <= 1 && p->getOrdinate() >= 0) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p;

    itTestUnit("ordinate setter and getter");
    p = new Position(0, 0);
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
    dest = new Position(40,180);
    source->move(*dest, 100);
    if (source->getAbsis() == 40 && source->getOrdinate() == 180) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving to destination in more than range");
    source = new Position(100,100);
    dest = new Position(40,180);
    source->move(*dest, 50);
    if (source->getAbsis() == 70 && source->getOrdinate() == 140) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving horizontally to destination in less than range");
    source = new Position(100,100);
    dest = new Position(40,180);
    source->moveHorizontal(*dest, 100);
    if (source->getAbsis() == 40 && source->getOrdinate() == 100) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving horizontally to destination in more than range");
    source = new Position(100,100);
    dest = new Position(40,180);
    source->moveHorizontal(*dest, 50);
    if (source->getAbsis() == 50 && source->getOrdinate() == 100) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving vertically to destination in less than range");
    source = new Position(100,100);
    dest = new Position(40,180);
    source->moveVertical(*dest, 100);
    if (source->getAbsis() == 100 && source->getOrdinate() == 180) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete source;
    delete dest;

    itTestUnit("moving vertically to destination in more than range");
    source = new Position(100,100);
    dest = new Position(40,180);
    source->moveVertical(*dest, 50);
    if (source->getAbsis() == 100 && source->getOrdinate() == 150) { itSuccess(); }
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
    if (*p1 == *p2) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p1;
    delete p2;

    itTestUnit("checking points are not equal");
    p1 = new Position(2.5, 3.5);
    p2 = new Position(2.5001, 3.5001);
    if (*p1 != *p2) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p1;
    delete p2;

    return countFail;
}

int testPositionRandom() {
    int countFail = 0;
    Position *p1, *p2;

    itTestUnit("randomizing position");
    p1 = new Position(10, 3000);
    p1->random(10, 10);
    if (p1->getAbsis() <= 10 && p1->getOrdinate() <= 3000) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete p1;

    itTestUnit("random should create new random, not equal to previous");
    p1 = new Position(2000, 3000, true);
    p2 = new Position(2000, 3000, true);
    if (p1->getAbsis() != p2->getAbsis() && p1->getOrdinate() != p2->getOrdinate()) { itSuccess(); }
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
    countFail += testPositionRandom();
    
    return countFail;
}