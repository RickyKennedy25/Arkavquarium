#ifndef LINKLIST_HPP
#define LINKLIST_HPP

#include <iostream>
#include "Node.hpp"
#define Nil NULL

template<class Type>
class LinkedList {
    private:
        Node<Type> *first;
        Node<Type> *last;
    public:
        /**
         * Construct linked list with first = NULL and last = NULL
         */
        LinkedList(){
            first=Nil;
            last=Nil;
        }


        /**
         * Find particular element in LinkedList
         * @param {Node<Type>} element to find
         * @return {int} index of element
         */
        int find(Node<Type> element){
            int count = 0;
            bool found = false;
            Node<Type> *TempNode;
            TempNode = first;
            while (TempNode != Nil && !found) {
                if (TempNode->getContent() == element.getContent()) {
                    found = true;
                } else {
                    TempNode = (*TempNode).getNext();
                    count++;
                }
            }
            return count;
        }

        /**
         * @return {bool} LinkedList is empty
         */
        bool isEmpty() {
            return first != Nil || last != Nil;
        }

        /**
         * Adds a new node
         * @param {Node<Type>} elemenet
         */
        void add(Type element) {
            Node<Type> *newNode;
            newNode = new Node<Type>(element);
            Node<Type> *lastNode;

            newNode->setPrev(this->last);
            if (this->first == Nil) {
                this->first = newNode;
            }
            if (this->last != Nil) {
                lastNode = this->last;
                lastNode->setNext(newNode);
            }
            this->last = newNode;
        }
         
        /**
         * Removes firs occurence node with content element
         * @param {Node<Type>} element to delete
         */
        void remove(Type element) {
            int count = 0;
            Node<Type> *TempNode;
            TempNode = this->first;

            while (TempNode != Nil && TempNode->getContent() != element) {
                TempNode = TempNode->getNext();
            }

            if (TempNode != Nil) {
                Node<Type> *Prev = TempNode->getPrev();
                Node<Type> *Next = TempNode->getNext();

                if(Prev == Nil) {
                    this->first = TempNode->getNext();
                } else {
                    Prev->setNext(Next);
                }

                if (Next == Nil){
                    this->last = TempNode->getPrev();
                } else {
                    Next->setPrev(Prev);
                }
            }
            
        }
        
        /**
         * @param {int} Element index, must less than sizeof LinkedList
         * @return {Node<Type>} i-th element in the LinkedList
         */
        Type get(int index) {
            Node<Type> *TempNode;
            TempNode = this->first;
            int i = 0;
            
            while (i < index && TempNode != this->last) {
                TempNode = TempNode->getNext();
                i++;
            }
            return TempNode->getContent();
        }
        
        /**
         * The List is not empty
         * @return {Node} first node
         */
        Type getFirst() {
            return (this->first)->getContent();
        }
        
        /**
         * The List is not empty
         * @return {Node} last node
         */
        Type getLast() {
            return (this->last)->getContent();
        }
        
};

#endif