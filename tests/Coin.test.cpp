#include "tester.hpp"
#include "Coin.test.hpp"
#include "../models/Coin.hpp"

int testCoinConstructor() {
    int countFail = 0;
    Coin *c;
    Position *p;

    itTestUnit("constructor value");
    p = new Position(10, 20, false);
    c = new Coin(25, *p);
    if (c->getValue() == 25) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    itTestUnit("constructor position");
    p = new Position(10, 20, false);
    c = new Coin(25, *p);
    if (c->getPosition()->getAbsis() == 10 &&
        c->getPosition()->getOrdinate() == 20) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    itTestUnit("constructor position copy by value");
    p = new Position(10, 20, false);
    c = new Coin(25, *p);
    p->setAbsis(30); p->setOrdinate(30);
    if (c->getPosition()->getAbsis() != 30 &&
        c->getPosition()->getOrdinate() != 30) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    return countFail;
}

int testCoinMove() {
    int countFail = 0;
    Coin *c;
    Position *p;

    itTestUnit("move less than target");
    p = new Position(10, 20, false);
    c = new Coin(25, *p);
    c->move(500, 1);
    if (c->getPosition()->getAbsis() == 10 &&
        c->getPosition()->getOrdinate() == 60) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    itTestUnit("move farther than target");
    p = new Position(10, 20, false);
    c = new Coin(25, *p);
    c->move(50, 1);
    if (c->getPosition()->getAbsis() == 10 &&
        c->getPosition()->getOrdinate() == 45) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    return countFail;
}

int testCoinAsset() {
    int countFail = 0;
    Coin *c;
    Position *p;

    itTestUnit("assetPath return coin if less than 50");
    p = new Position(10, 20, false);
    c = new Coin(49, *p);
    if (c->getAssetPath() == "assets/img/coin_shine.png") { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    itTestUnit("assetPath return ruby if equal to 50");
    p = new Position(10, 20, false);
    c = new Coin(50, *p);
    if (c->getAssetPath() == "assets/img/ruby.png") { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    itTestUnit("assetPath return coin if less than 50");
    p = new Position(10, 20, false);
    c = new Coin(51, *p);
    if (c->getAssetPath() == "assets/img/ruby.png") { itSuccess(); }
    else { itFailed(); countFail++; }
    delete c; delete p;

    return countFail;
}

int testCoin() {
    int countFail = 0;

    itTestClass("Model/Coin");
    countFail += testCoinConstructor();
    countFail += testCoinMove();
    countFail += testCoinAsset();
    
    return countFail;
}