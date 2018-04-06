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
         * Adds a new LinkedListItem
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
         * @return {LinkedListItem<Type>} i-th element in the LinkedList
         */
        Type get(int index);
        
        /**
         * The List is not empty
         * @return {LinkedListItem} first LinkedListItem
         */
        Type getFirst();
        
        /**
         * The List is not empty
         * @return {LinkedListItem} last LinkedListItem
         */
        Type getLast();
};

#include "LinkedList.cpp"

#endif