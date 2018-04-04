#ifndef NODE_HPP
#define NODE_HPP

#define Nil NULL

template<class Type>
class Node {
    private:
        Type content;
        Node *next;
        Node *prev;
    public:
        /** 
         * Construct Node with content = content, next = NULL, and prev = NULL
         */
        Node(Type content) {
            this->next = Nil;
            this->prev = Nil;
            this->content = content;
        }

        /**
         * @return {Type} Get content of current node
         */
        Type getContent(){
            return content;
        }
        
        /**
         * @return {Node} previous Node
         */
        Node* getPrev(){
            return prev;
        }
        
        /**
         * @return {Node} next Node
         */
        Node* getNext(){
            return next;
        }

        /**
         * Set content of current node
         * @param {Type} new node content
         */
        void setContent(Type content){
            this->content =content;
        }
        
        /**
         * Set address to previous Node
         * @param {Node*} address of previous node
         */
        void setPrev(Node* prev){
            this->prev = prev;
        }
        
        /**
         * Set address to next Node
         * @param {Node*} address of next node
         */
        void setNext(Node* next){
            this->next = next;
        }
};


#endif