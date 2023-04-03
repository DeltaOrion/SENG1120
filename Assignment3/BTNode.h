// Binary Tree Node Class Header
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: A binary search tree is a sorted rooted binary tree data structure who's nodes each act as subtree's themselves.
// This class represents a  node for a binary search tree. Each node stores a data value and is connected to another node
// on the right and on the left. The node to the left has a data value that is less than This node and the node to the right has a data value 
// greater than this node value. Duplicate values are not inserted into the tree. This data structure does not include any kind of balancing.
// Nodes are simply inserted as is.

#include <string>
#include "MechPart.h"

#ifndef BTNODE_H
#define BTNODE_H

template<typename T>
class BTNode {
    public:
        //the element type being stored in the list 
        /**
         *  Creates a new instance of a node. 
         * 
         * //precondition Type t has a default constructor
         * //postcondition A node class is instansiated, the default is an empty node 
         * 
         * @param value The initial element value in the list
         * @param left The initial pointer of the first element to its left element 
         * @param right the initial pointer of the first element to its right element 
         */
        
        BTNode(const T& value = T(), BTNode<T>* left = NULL, BTNode<T>* right = NULL);

        /**
         *  Destroys an instance of a node 
         * 
         * //precondition The node is instantiated 
         * //postcondition a node instance is destroyed
         * 
         */

        ~BTNode();
        
        /**
         *  Retrieves the node and by extension its binary tree which is to the 
         *  left of this node. This node will always contain a value that is 
         *  less than this node. If the left and the right are null than this 
         *  is a leff on the tree.
         * 
         * //precondition none
         * //postcondition The node's pointer to the subtree to the left of it
         * //or null if there is no connection
         * 
         * @return The node's pointer to the subtree to the left of it 
         */

        
        BTNode<T>* getLeft() const;

        /**
         *  Retrieves the node and by extension its binary tree which is to the 
         *  right of this node. This node will always contain a value that is 
         *  greater than this node. If the left and the right are null than this 
         *  is a leff on the tree.
         * 
         * //precondition none
         * //postcondition The node's pointer to the subtree to the tree of it
         * //or null if there is no connection
         * 
         * @return The node's pointer to the subtree to the left of it
         */


        BTNode<T>* getRight() const; 

        /**
         *  retrieves the value stored in this node.
         * 
         * //precondition none
         * //postcondition the value stored in this list element 
         * 
         * @return The value stored in this list element 
         */


        T getValue() const;

        /**
         *  Changes the node's pointer to the subtree to the left of it or NULL
         *  if there is no connections to the left of it. The data value of whatever node 
         *  is stored to the left must be less than this data value for this data structure to function correctly. 
         * 
         * //precondition if there is no connections to the left of it then this should be null. 
         * //postcondition changes the node's the subtree to the left of this node
         * 
         * @param left the subtree to the left of this node
         */


        void setLeft(BTNode<T>* left);
        /**
         *  Changes the node's pointer to the subtree to the right of it or NULL
         *  if there is no connections to the right of it. The data value of whatever node 
         *  is stored to the left must be greater than this data value for this data structure to function correctly. 
         * 
         * //precondition if there is no connections to the right of it then this should be null. 
         * //postcondition changes the node's subtree to the right of this node
         * 
         * @param right the subtree to the rigght of this node
         */

        void setRight(BTNode<T>* right);

        /**
         *  Changes the value stored in this tree node.
         * 
         * //precondition The data value must be of type mechpart. 
         * //postcondition changes the value stored in the element of the list
         * 
         * @param value the new value of the element to be stored in the list 
         */    

        void setValue(const T& value);

    private:
        BTNode<T>* right; 
        BTNode<T>* left;
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
bool operator == (const BTNode<T>& nodeA, const BTNode<T>& nodeB);


/**
 *  Checks if the elements stored in both nodes are not equal
 * 
 * //precondition none
 * //postcondition tests for no equality of the value stored in each node
 * 
 * @return whether the values stored in both nodes are not equal
 */    
template<typename T>
bool operator != (const BTNode<T>& nodeA, const BTNode<T>& nodeB);

/**
 * Prints the value of the stored element 
 * 
 * //precondition The type t has an output stream defined. 
 * //postcondition prints the value of the stored element
 * 
 * @return an output stream with the string value of the stored element. 
 */    

template<typename T>
std::ostream& operator << (std::ostream& out, const BTNode<T>& node);

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
bool operator == (const BTNode<T>& nodeA, const BTNode<T>& nodeB) {
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
bool operator != (const BTNode<T>& nodeA, const BTNode<T>& nodeB) {
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
std::ostream& operator << (std::ostream& out, const BTNode<T>& node) {
    out << node.getValue();
    return out; 
}

//helper function to check the equality of two nodes, both the equals and not
//equals operator overloads use this. 
template<typename T>
bool equals(const BTNode<T>& nodeA, const BTNode<T>& nodeB);

template<typename T>
BTNode<T>::BTNode(const T& value,BTNode<T>* left, BTNode<T>* right) {
    this->left = left;
    this->right = right;
    this->value = value; 
}

template<typename T>
BTNode<T>::~BTNode() {

}
//getter methods
template<typename T>
BTNode<T>* BTNode<T>::getLeft() const {
    return this->left;
}

template<typename T>
T BTNode<T>::getValue() const {
    return this->value; 
}

template<typename T>
BTNode<T>* BTNode<T>::getRight() const {
    return this->right;
}
//setter methods 
template<typename T>
void BTNode<T>::setLeft(BTNode<T>* left) {
    this->left = left;
}

template<typename T>
void BTNode<T>::setRight(BTNode<T>* right) {
    this->right = right; 
}

template<typename T>
void BTNode<T>::setValue(const T& value) {
    this->value = value; 
}

#endif //BTNODE_H