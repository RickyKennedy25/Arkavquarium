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
 * @param {Type} element to find
 * @return {int} index of element
 */
template<class Type>
int LinkedList<Type>::find(Type element) {
    int count = 0;
    bool found = false;
    LinkedListItem<Type> *item;

    item = this->first;
    while (item != NULL && !found) {
        if (item->getContent() == element) { found = true; }
        else { item = item->getNext(); count++; }
    }
    return count;
}

/**
 * @return {bool} LinkedList is empty
 */
template<class Type>
bool LinkedList<Type>::isEmpty() {
    return this->first == NULL && this->last == NULL;
}

/**
 * Adds a new LinkedListItem to front of list
 * @param {LinkedListItem<Type>} elemenet
 */
template<class Type>
void LinkedList<Type>::add(Type element) {
    LinkedListItem<Type> *newItem;

    newItem = new LinkedListItem<Type>(element); 
    newItem->setPrev(this->last);
    if (this->last != NULL) { this->last->setNext(newItem); }
    this->last = newItem;
    if (this->first == NULL) {
        this->first = newItem;
    }
}
    
/**
 * Removes firs occurence LinkedListItem with content element
 * @param {LinkedListItem<Type>} element to delete
 */
template<class Type>
void LinkedList<Type>::remove(Type element) {
    LinkedListItem<Type> *item;

    item = this->first;

    while (item != NULL && item->getContent() != element) {
        item = item->getNext();
    }

    if (item != NULL) {
        LinkedListItem<Type> *prev = item->getPrev();
        LinkedListItem<Type> *next = item->getNext();

        if (prev == NULL) { this->first = next; }
        else { prev->setNext(next); }

        if (next == NULL) { this->last = prev; }
        else { next->setPrev(prev); }
    }
}

/**
 * @param {int} Element index, must less than sizeof LinkedList
 * index zero base
 * @return {Type} i-th element in the LinkedList
 */
template <class Type>
Type LinkedList<Type>::getContentAt(int index) {
    return this->getItemAt(index)->getContent();
}

/**
 * @param {int} Element index, must less than sizeof LinkedList
 * @return {LinkedListItem<Type>*} i-th item in the LinkedList
 */
template <class Type>
LinkedListItem<Type>* LinkedList<Type>::getItemAt(int index) {
    LinkedListItem<Type> *item;
    int i = 0;

    item = this->first;
    while (i < index && item != this->last) {
        item = item->getNext();
        i++;
    }
    return item;
}

/**
 * The List is not empty
 * @return {Type} content of first LinkedListItem
 */
template<class Type>
Type LinkedList<Type>::getFirstContent() {
    return this->first->getContent();
}

/**
 * The List is not empty
 * @return {LinkedListItem<Type>*} first LinkedListItem
 */
template<class Type>
LinkedListItem<Type>* LinkedList<Type>::getFirstItem() {
    return this->first;
}

/**
 * The List is not empty
 * @return {Type} content of last LinkedListItem
 */
template<class Type>
Type LinkedList<Type>::getLastContent() {
    return this->last->getContent();
}

/**
 * The List is not empty
 * @return {LinkedListItem<Type>*} last LinkedListItem
 */
template<class Type>
LinkedListItem<Type>* LinkedList<Type>::getLastItem() {
    return this->last;
}

#endif