#include "tester.hpp"
#include "LinkedListItem.test.hpp"
#include "../models/LinkedListItem.hpp"

int testLinkedListItemContent() {
    int countFail = 0;
    LinkedListItem<int> *itInt;
    LinkedListItem<double> *itDouble;

    itTestUnit("constructor set content");
    itInt = new LinkedListItem<int>(2);
    itDouble = new LinkedListItem<double>(2.5);
    if (itDouble->getContent() == 2.5 &&
        itInt->getContent() == 2) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete itInt; delete itDouble;

    itTestUnit("constructor set prev and next NULL");
    itDouble = new LinkedListItem<double>(2.5);
    if (itDouble->getPrev() == NULL &&
        itDouble->getNext() == NULL) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete itInt; delete itDouble;

    itTestUnit("setter");
    itInt = new LinkedListItem<int>(2);
    itDouble = new LinkedListItem<double>(2.5);
    itInt->setContent(5);
    itDouble->setContent(9.2);
    if (itDouble->getContent() == 9.2 &&
        itInt->getContent() == 5) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete itInt; delete itDouble;

    return countFail;
}

int testLinkedListItemLink() {
    int countFail = 0;
    LinkedListItem<double> *it1, *it2;

    itTestUnit("getPrev and setPrev");
    it1 = new LinkedListItem<double>(2.5);
    it2 = new LinkedListItem<double>(7.4);
    it1->setPrev(it2);
    if (it1->getPrev()->getContent() == 7.4) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete it1; delete it2;

    itTestUnit("getNext and setNext");
    it1 = new LinkedListItem<double>(2.5);
    it2 = new LinkedListItem<double>(7.4);
    it1->setNext(it2);
    if (it1->getNext()->getContent() == 7.4) { itSuccess(); }
    else { itFailed(); countFail++; }
    delete it1; delete it2;

    return countFail;
}

int testLinkedListItem() {
    int countFail = 0;

    itTestClass("Model/LinkedListItem");
    countFail += testLinkedListItemContent();
    countFail += testLinkedListItemLink();
    
    return countFail;
}