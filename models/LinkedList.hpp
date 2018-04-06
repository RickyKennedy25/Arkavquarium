#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include "LinkedListItem.hpp"

template<class Type>
class LinkedList {
    private:
        LinkedListItem<Type> *first;
        LinkedListItem<Type> *last;
    public:
        /**
         * Construct linked list with first = NULL and last = NULL
         */
        LinkedList();

        /**
         * Find particular element in LinkedList
         * @param {LinkedListItem<Type>} element to find
         * @return {int} index of element
         */
        int find(LinkedListItem<Type> element);

        /**
         * @return {bool} LinkedList is empty
         */
        bool isEmpty();

        /**
         * Adds a new LinkedListItem to front of list
         * @param {LinkedListItem<Type>} elemenet
         */
        void add(Type element);
         
        /**
         * Removes firs occurence LinkedListItem with content element
         * @param {LinkedListItem<Type>} element to delete
         */
        void remove(Type element);

        /**
         * @param {int} Element index, must less than sizeof LinkedList
         * @return {Type} i-th element in the LinkedList
         */
        Type getContentAt(int index);

        /**
         * @param {int} Element index, must less than sizeof LinkedList
         * @return {LinkedListItem<Type>*} i-th item in the LinkedList
         */
        LinkedListItem<Type>* getItemAt(int index);

        /**
         * The List is not empty
         * @return {Type} content of first LinkedListItem
         */
        Type getFirstContent();

        /**
         * The List is not empty
         * @return {LinkedListItem<Type>*} first LinkedListItem
         */
        LinkedListItem<Type>* getFirstItem();

        /**
         * The List is not empty
         * @return {Type} content of last LinkedListItem
         */
        Type getLastContent();

        /**
         * The List is not empty
         * @return {LinkedListItem<Type>*} last LinkedListItem
         */
        LinkedListItem<Type>* getLastItem();
};

#include "LinkedList.cpp"

#endif