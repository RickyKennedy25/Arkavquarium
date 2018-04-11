#include "tester.hpp"
#include "Snail.test.hpp"
#include "../models/Snail.hpp"

int testSnailConstructor() {
	int countFail = 0;
	Snail *s;

	itTestUnit("constructor position");
	s = new Snail(1366, 768);
	if (s->getPosition()->getAbsis() > 0 && s->getPosition()->getAbsis() < 1366 && s->getPosition()->getOrdinate() > 0 && s->getPosition()->getOrdinate() < 768)
		itSuccess();
	else {
		itFailed();
		countFail++;
	}
	delete s;
}

int testSnailAsset() {
	int countFail = 0;
	Snail *s;
	Position *p;
	itTestUnit("asssetPath return snail_left.png if the orientation is left");
	s = new Snail(1366, 768);
	if (s->getAssetPath() == "assets/img/snail_left.png") { itSuccess(); }
	else {itFailed(); countFail++;}
	delete s;

	itTestUnit("asssetPath return snail_right.png if the orientation is right");
	s = new Snail(1366, 768);
	p = new Position(s->getPosition()->getAbsis() + 100, s->getPosition()->getOrdinate());
	s->moveToDestination(p, 0.1);
	if (s->getAssetPath() == "assets/img/snail_right.png") { itSuccess(); }
	else {itFailed(); countFail++;}
	delete s;

}

int testSnail() {
    int countFail = 0;

    itTestClass("Model/Snail");
    countFail += testSnailConstructor();
    countFail += testSnailAsset();
    
    return countFail;

}
