#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include "LinkedList.hpp"

/**
 * Construct linked list with first = NULL and last = NULL
 */
template<class Type>
LinkedList<Type>::LinkedList() {
    this->first = NULL;
    this->last = NULL;
}

/**
 * Find particular element in LinkedList
 * @param {LinkedListItem<Type>} element to find
 * @return {int} index of element
 */
template<class Type>
int LinkedList<Type>::find(LinkedListItem<Type> element) {
    int count = 0;
    bool found = false;
    LinkedListItem<Type> *TempLinkedListItem;

    TempLinkedListItem = this->first;
    while (TempLinkedListItem != NULL && !found) {
        if (TempLinkedListItem->getContent() == element.getContent()) {
            found = true;
        } else {
            TempLinkedListItem = TempLinkedListItem->getNext();
            count++;
        }
    }
    return count;
}

/**
 * @return {bool} LinkedList is empty
 */
template<class Type>
bool LinkedList<Type>::isEmpty() {
    return this->first != NULL || this->last != NULL;
}

/**
 * Adds a new LinkedListItem
 * @param {LinkedListItem<Type>} elemenet
 */
template<class Type>
void LinkedList<Type>::add(Type element) {
    LinkedListItem<Type> *newLinkedListItem;
    LinkedListItem<Type> *lastLinkedListItem;

    newLinkedListItem = new LinkedListItem<Type>(element);
    newLinkedListItem->setPrev(this->last);

    if (this->first == NULL) {
        this->first = newLinkedListItem;
    }
    if (this->last != NULL) {
        lastLinkedListItem = this->last;
        lastLinkedListItem->setNext(newLinkedListItem);
    }

    this->last = newLinkedListItem;
}
    
/**
 * Removes firs occurence LinkedListItem with content element
 * @param {LinkedListItem<Type>} element to delete
 */
template<class Type>
void LinkedList<Type>::remove(Type element) {
    int count = 0;
    LinkedListItem<Type> *TempLinkedListItem;

    TempLinkedListItem = this->first;

    while (TempLinkedListItem != NULL && TempLinkedListItem->getContent() != element) {
        TempLinkedListItem = TempLinkedListItem->getNext();
    }

    if (TempLinkedListItem != NULL) {
        LinkedListItem<Type> *Prev = TempLinkedListItem->getPrev();
        LinkedListItem<Type> *Next = TempLinkedListItem->getNext();

        if(Prev == NULL) {
            this->first = TempLinkedListItem->getNext();
        } else {
            Prev->setNext(Next);
        }

        if (Next == NULL){
            this->last = TempLinkedListItem->getPrev();
        } else {
            Next->setPrev(Prev);
        }
    }
    
}

/**
 * @param {int} Element index, must less than sizeof LinkedList
 * @return {LinkedListItem<Type>} i-th element in the LinkedList
 */
template<class Type>
Type LinkedList<Type>::get(int index) {
    LinkedListItem<Type> *TempLinkedListItem;
    int i = 0;

    TempLinkedListItem = this->first;
    
    while (i < index && TempLinkedListItem != this->last) {
        TempLinkedListItem = TempLinkedListItem->getNext();
        i++;
    }
    return TempLinkedListItem->getContent();
}

/**
 * The List is not empty
 * @return {LinkedListItem} first LinkedListItem
 */
template<class Type>
Type LinkedList<Type>::getFirst() {
    return this->first->getContent();
}

/**
 * The List is not empty
 * @return {LinkedListItem} last LinkedListItem
 */
template<class Type>
Type LinkedList<Type>::getLast() {
    return this->last->getContent();
}

#endif