#include "tester.hpp"
#include "LinkedList.test.hpp"
#include "../models/LinkedList.hpp"

int testPrimitifLinkedList(){
    int countFail = 0;
    LinkedList<int> *LL;

    itTestUnit("constructor should create empty linked list");
    LL = new LinkedList<int>;
    if(LL->getFirstItem() ==  NULL && LL->getLastItem() == NULL) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("isEmpty return true on new linked list");
    LL = new LinkedList<int>;
    if (LL->isEmpty()) { itSuccess(); }
    else  {itFailed(); countFail++; }
    delete LL;

    return countFail;
}

int testUpdateAndFindLinkedList(){
    int countFail = 0;
    LinkedList<int> *LL;

    itTestUnit("add should not make list empty");
    LL = new LinkedList<int>;
    LL->add(3);
    if (!(LL->isEmpty())) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("getFirstContent should return first added item");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5);
    if (LL->getFirstContent() == 3) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("remove single element linked list should make linked list empty");
    LL = new LinkedList<int>;
    LL->add(3);
    LL->remove(3);
    if (LL->isEmpty()) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("find index result should be correspond to get");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5); LL->add(8);
    if (LL->getContentAt(LL->find(8)) == 8 &&
        LL->getContentAt(LL->find(5)) == 5 &&
        LL->getContentAt(LL->find(3)) == 3) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    return countFail;
}

int testGetterContentLinkedList(){
    int countFail = 0;
    LinkedList<int> *LL;

    itTestUnit("getFirstContent should return first added element");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5);
    if (LL->getFirstContent() == 3){ itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("getLastContent should return last added element");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5);
    if (LL->getLastContent() == 5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    itTestUnit("getContentAt should return exact position");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5); LL->add(8);
    if (LL->getContentAt(1) == 5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete LL;

    return countFail;
}

int testGetterItemLinkedList(){
    int countFail = 0;
    LinkedList<int> *LL;

    itTestUnit("getFirstItem should return item for first added element");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5);
    if ((LL->getFirstItem())->getContent() == 3 ) { itSuccess(); }
    else { itFailed(); countFail++; }

    itTestUnit("getLastItem should return item for last added element");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5);
    if ((LL->getLastItem())->getContent() == 5 ) { itSuccess(); }
    else { itFailed(); countFail++; }

    itTestUnit("getItemAt  should return item for exact index");
    LL = new LinkedList<int>;
    LL->add(3); LL->add(5); LL->add(8);
    if ((LL->getItemAt(1))->getContent() == 5 ) { itSuccess(); }
    else { itFailed(); countFail++; }

    return countFail = 0;
}

int testLinkedList(){
    int countFail = 0;
    itTestClass("Model/LinkedList");
    countFail += testPrimitifLinkedList();
    countFail += testUpdateAndFindLinkedList();
    countFail += testGetterContentLinkedList();
    countFail += testGetterItemLinkedList();

    return countFail;
}
