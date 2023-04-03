// Node Class Header
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: This class acts as a template for a node instance. If a linked list is a set of elements
// then a node is an element in the set. It's main job is to store a value of type t. Each node or element
// in the list also stores a reference to the previous element(node) in the set and the next element(node) in the set. 
// This acts as the main basis of a linked list. 

#include <string>
#include "EToll.h"

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
    public:
        //the element type being stored in the list 
        /**
         *  Creates a new instance of a node. 
         * 
         * //precondition Type t has a default constructor
         * //postcondition A node class is instansiated, the default is an empty node 
         * 
         * @param value The initial element value in the list
         * @param next The initial pointer of the first element to its next element 
         * @param prev the initial pointer of the first element to its prev element 
         */
        
        Node(const T& value = T(), Node<T>* next = NULL, Node<T>* prev = NULL);

        /**
         *  Destroys an instance of a node 
         * 
         * //precondition The node is instantiated 
         * //postcondition a node instance is destroyed
         * 
         */

        ~Node();
        
        /**
         *  Retrieves the node's pointer to the next element in the set. This will 
         *  return NULL if this element is the head of the set.
         * 
         * //precondition none
         * //postcondition the node's pointer to the next element in the set
         * 
         * @return the node's pointer to the element after it in the list 
         */

        
        Node<T>* getNext() const;

        /**
         *  Retrieves the node's pointer to the previous element in the set. This will
         *  return NULL if this element is the head of the set. 
         * 
         * //precondition none  
         * //postcondition The node's pointer to the previous element in the set
         * 
         * @return The node's pointer to the element before it in the list 
         */


        Node<T>* getPrev() const; 

        /**
         *  retrieves the value stored in this list element  
         * 
         * //precondition none
         * //postcondition the value stored in this list element 
         * 
         * @return The value stored in this list element 
         */


        T getValue() const;

        /**
         *  Changes the node's pointer to the element after it in the list. If this is the new
         *  tail of the list it MUST point to NULL. 
         * 
         * //precondition if this is the tail then the value should be null
         * //postcondition changes the node's pointer to the element after it in the list
         * 
         * @param next the element after it in the list
         */


        void setNext(Node<T>* next);
        /**
         *  Changes the node's pointer to the element before it in the list. If this is the new HEAD of the
         *  list then it MUST point to NULL. 
         * 
         * //precondition if this is the head then it should be null
         * //postcondition changes the node's pointer to the element before it in the list
         * 
         * @param prev the element before it in the list
         * 
         */
        void setPrev(Node<T>* prev);

        /**
         *  Changes the value stored in this element of the list
         * 
         * //precondition must be of type t
         * //postcondition changes the value stored in the element of the list
         * 
         * @param value the new value of the element to be stored in the list 
         */    

        void setValue(const T& value);

    private:
        Node<T>* prev; 
        Node<T>* next;
        T value; 

};


/**
 *  Checks if the elements stored in both nodes are equal
 * 
 * //precondition none
 * //postcondition tests for equality of the value stored in each node
 * 
 * @return whether the values stored in both nodes are equal
 */    
template<typename T>
bool operator == (const Node<T>& nodeA, const Node<T>& nodeB);


/**
 *  Checks if the elements stored in both nodes are not equal
 * 
 * //precondition none
 * //postcondition tests for no equality of the value stored in each node
 * 
 * @return whether the values stored in both nodes are not equal
 */    
template<typename T>
bool operator != (const Node<T>& nodeA, const Node<T>& nodeB);

/**
 * Prints the value of the stored element 
 * 
 * //precondition The type t has an output stream defined. 
 * //postcondition prints the value of the stored element
 * 
 * @return an output stream with the string value of the stored element. 
 */    

template<typename T>
std::ostream& operator << (std::ostream& out, const Node<T>& node);

/**
 *  Class Delcaration 
 *
 * 
 */ 

/**
 *  Checks if the elements stored in both nodes are equal
 * 
 * //precondition none
 * //postcondition tests for equality of the value stored in each node
 * 
 * @return whether the values stored in both nodes are equal
 */    

template<typename T>
bool operator == (const Node<T>& nodeA, const Node<T>& nodeB) {
    return equals(nodeA,nodeB);
}


/**
 *  Checks if the elements stored in both nodes are not equal
 * 
 * //precondition none
 * //postcondition tests for no equality of the value stored in each node
 * 
 * @return whether the values stored in both nodes are not equal
 */    

template<typename T>
bool operator != (const Node<T>& nodeA, const Node<T>& nodeB) {
    return !equals(nodeA,nodeB);
}

/**
 * Prints the value of the stored element 
 * 
 * //precondition The type t has an output stream defined. 
 * //postcondition prints the value of the stored element
 * 
 * @return an output stream with the string value of the stored element. 
 */    

template<typename T>
std::ostream& operator << (std::ostream& out, const Node<T>& node) {
    out << node.getValue();
    return out; 
}

//helper function to check the equality of two nodes, both the equals and not
//equals operator overloads use this. 
template<typename T>
bool equals(const Node<T>& nodeA, const Node<T>& nodeB);

template<typename T>
Node<T>::Node(const T& value,Node<T>* next, Node<T>* prev) {
    this->next = next;
    this->prev = prev;
    this->value = value; 
}

template<typename T>
Node<T>::~Node() {

}
//getter methods
template<typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

template<typename T>
T Node<T>::getValue() const {
    return this->value; 
}

template<typename T>
Node<T>* Node<T>::getPrev() const {
    return this->prev;
}
//setter methods 
template<typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template<typename T>
void Node<T>::setPrev(Node<T>* prev) {
    this->prev = prev; 
}

template<typename T>
void Node<T>::setValue(const T& value) {
    this->value = value; 
}

#endif