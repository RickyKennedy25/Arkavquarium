#ifndef LINKED_LIST_ITEM_HPP
#define LINKED_LIST_ITEM_HPP

#include <iostream>

template<class Type>
class LinkedListItem {
    private:
        Type content;
        LinkedListItem *next;
        LinkedListItem *prev;
    public:
        /** 
         * Construct LinkedListItem with content = *content, next = NULL, and prev = NULL
         */
        LinkedListItem(Type content);

        /**
         * @return {Type} Get content of current item
         */
        Type getContent();
        
        /**
         * @return {LinkedListItem} previous LinkedListItem
         */
        LinkedListItem* getPrev();
        
        /**
         * @return {LinkedListItem} next LinkedListItem
         */
        LinkedListItem* getNext();

        /**
         * Set content of current item
         * @param {Type} new item content
         */
        void setContent(Type content);
        
        /**
         * Set address to previous LinkedListItem
         * @param {LinkedListItem*} address of previous item
         */
        void setPrev(LinkedListItem* prev);
        
        /**
         * Set address to next LinkedListItem
         * @param {LinkedListItem*} address of next item
         */
        void setNext(LinkedListItem* next);
};

#include "LinkedListItem.cpp"

#endif