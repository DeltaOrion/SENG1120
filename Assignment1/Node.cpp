// Node Class Instance 
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: This class is the implementation of the node header file. For more documentation see
// "Node.h" 

#include "Node.h"
#include "EToll.h"

//helper function to check the equality of two nodes, both the equals and not
//equals operator overloads use this. 
bool equals(const Node& nodeA, const Node& nodeB);


Node::Node(const Node::type& value,Node* next, Node* prev) {
    this->next = next;
    this->prev = prev;
    this->value = value; 
}

Node::~Node() {

}
//getter methods
Node* Node::getNext() const {
    return this->next;
}

Node::type Node::getValue() const {
    return this->value; 
}

Node* Node::getPrev() const {
    return this->prev;
}
//setter methods 
void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev; 
}

void Node::setValue(const Node::type& value) {
    this->value = value; 
}
//operator overloads 
bool operator==  (const Node& nodeA, const Node& nodeB) {
    return equals(nodeA,nodeB);
}

bool operator!= (const Node& nodeA, const Node& nodeB) {
    return !equals(nodeA,nodeB);
}

bool equals(const Node& nodeA, const Node& nodeB) {
    return nodeA.getValue() == nodeB.getValue();
}
//output stream with the value of the element 
std::ostream& operator << (std::ostream& out, const Node& node) {
    out << node.getValue();
    
    return out; 
}
