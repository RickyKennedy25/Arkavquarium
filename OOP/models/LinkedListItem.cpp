#ifndef LINKED_LIST_ITEM_CPP
#define LINKED_LIST_ITEM_CPP

#include "LinkedListItem.hpp"
#include <iostream>

/** 
 * Construct LinkedListItem with content = content, next = NULL, and prev = NULL
 */
template<class Type>
LinkedListItem<Type>::LinkedListItem(Type content) { //pointer lli
    this->next = NULL;
    this->prev = NULL;
    this->content = content;
}

/**
 * @return {Type} Get content of current item
 */
template<class Type>
Type LinkedListItem<Type>::getContent() { //pointer lli 
    return this->content;
}

/**
 * @return {LinkedListItem<Type>} previous LinkedListItem
 */
template<class Type>
LinkedListItem<Type>* LinkedListItem<Type>::getPrev() {
    return this->prev;
}

/**
 * @return {LinkedListItem<Type>} next LinkedListItem
 */
template<class Type>
LinkedListItem<Type>* LinkedListItem<Type>::getNext() {
    return this->next;
}

/**
 * Set content of current item
 * @param {Type} new item content
 */
template<class Type>
void LinkedListItem<Type>::setContent(Type content) { //pointer lli
    this->content = content;
}

/**
 * Set address to previous LinkedListItem
 * @param {LinkedListItem*} address of previous item
 */
template<class Type>
void LinkedListItem<Type>::setPrev(LinkedListItem* prev) {
    this->prev = prev;
}

/**
 * Set address to next LinkedListItem
 * @param {LinkedListItem*} address of next item
 */
template<class Type>
void LinkedListItem<Type>::setNext(LinkedListItem* next) {
    this->next = next;
}

#endif