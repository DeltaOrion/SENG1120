// LinkedList Class
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: Implementation of the "linkedlist.h" class template 

#include "LinkedList.h"
#include "Node.h"
#include "EToll.h"
#include <stdexcept>

LinkedList::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->current = NULL;
    this->size = 0;
    //standard error messages for when an illegal action is made. 
    ERR_MSG_OUT_BOUNDS = "Received index out of list bounds";
    ERR_MSG_NULL_POINTER = "Null Pointer Exception. Cannot manipulate node as it is null";
}

//Destructs the list by traversing through it and deleting each node one by one. 
LinkedList::~LinkedList() {
    
    Node* ref = this->head;
    Node* next;

    while(ref != NULL) {
        next = ref->getNext();
        delete ref; 
        ref = next;
    }
}
void LinkedList::addToHead(const LinkedList::type& value) {
    //instantiate the new node
    Node* newNode = new Node(value);
    
    if(this->head == NULL) {
        //adding first element to list, set head and tail to it
        this->head = newNode;
        this->tail = newNode; 
    } else {
        //point this new node to ther current head, and made it point backward to null
        newNode->setNext(head);
        newNode->setPrev(NULL);
        head->setPrev(newNode);
        this->head = newNode;
    }

    this->size++;
}

void LinkedList::addToTail(const LinkedList::type& value) {
    
    if(this->tail==NULL) {
        //if list is empty add to head
        addToHead(value);
    } else {
        //instiate the new node
        Node* newNode = new Node(value);
        newNode->setPrev(tail);
        //point the tail to this new node
        tail->setNext(newNode);
        tail = tail->getNext();
        this->size++;
    }
    
}


Node* LinkedList::getNode(const int index) const {
    int data = 0;
    Node* ref = this->head;
    //if head is null then the list is empty and thus they are accessing
    //out of list bouds
    if(ref==NULL) {
        throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
    }
    //iterate through the list, counting up each step of iteration
    //until the we are at the nth element
    while(ref!=NULL) {
        if(data==index) {
            return ref; 
        }
        ref = ref->getNext();
        data++;
    }
    //if it cant be found then they are accessing out of list bounds
    throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
}

Node* LinkedList::getNode(const std::string& value) const {
    //iterate through the list, checking the value of each element
    //with the specified value
    Node* ref = this->head;
    while(ref!=NULL) {
        if(ref->getValue().get_licence()==value)  {
            return ref;
        }
        ref = ref->getNext();
    }
    //if it cant be found return null, the user then can deal with this. 
    return NULL;
}

void LinkedList::removeHead() {
    //if the list is empty then they are removing an element out of list bounds
    if(this->head==NULL) {
        throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
    }
    //create a temporary reference to the head 
    Node* temp = this->head;  
    this->head = head->getNext();
    //make the head the next element in the list
    
    if(this->head != NULL) {
        //if the list has more than one element 
        //tidy up the new head 
        head->setPrev(NULL);
        if(this->head->getNext() != NULL) {
            this->head->getNext()->setPrev(this->head);
        }
    } else {
        //if the element after the head is null then the list originally had one element
        //thus removing it will make this an empty list
        tail = NULL; 
    }
    //once list has been cleaned then delete the garbage node 
    delete temp; 
    this->size--; 

}

void LinkedList::removeTail() {
    //if the tail is empty then the list is empty thus they are trying
    //to remove an element out of list bounds 
    if(this->tail==NULL) {
        throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
    }

    Node* temp = this->getTail();
    this->tail = tail->getPrev();
    //make the tail the element before the tail
    //if the element before the tail was null then the original list had one element and thus
    //the new list is the empty list

    if(this->tail != NULL) {
        //clean up the new tail 
        tail->setNext(NULL);
        if(this->tail->getPrev() != NULL) {
            this->tail->getPrev()->setNext(this->tail);
        }
    } else {
        //if the new list is empty
        head=NULL;
    }
    //delete the garbage node once the list has been cleaned. 
    delete temp;
    this->size--; 
}

void LinkedList::remove(Node* node) {
    //if the node being removed is null then something very bad has happened. 
    if(node==NULL) {
        throw new std::invalid_argument(ERR_MSG_NULL_POINTER);
    }
    //if it is the head or tail remove it as the head or tail
    if(node->getPrev()==NULL) {
        removeHead();
    } else if(node->getNext()==NULL) {
        removeTail();
    } else {
        //fix up the pointers to point away from this node
        node->getPrev()->setNext(node->getNext());
        node->getNext()->setPrev(node->getPrev());

        //the node is now garbage, delete it. 
        delete node;
        this->size--;
    }
}

void LinkedList::remove(const std::string& value) {
    Node* node = getNode(value);
    remove(node);
}

void LinkedList::remove(const LinkedList::type& value) {
    Node* node = getNode(value);
    remove(node);
}

Node* LinkedList::getNode(const LinkedList::type& value) const {
    //traverse the list until one element's data value matches the desired one
    Node* ref = this->head;
    while(ref!=NULL) {
        if(ref->getValue() == value) {
            return ref; 
        }
        ref = ref->getNext();
    }
    //if nothing is found return null and allow user to handle 
    return NULL;
}

//methods for getting variables

Node* LinkedList::getHead() const {
    return this->head;
}

Node* LinkedList::getTail() const {
    return this->tail;
}

int LinkedList::getSize() const {
    return this->size;
}


int LinkedList::count(const LinkedList::type& value) const {
    //traverse the list, every time the value is found incremenet the counter
    Node* ref = getHead();
    int count = 0;
    while(ref!=NULL) {
        if(ref->getValue() == value) {
            count++;
        }
        ref=ref->getNext();
    }
    //return the final count 
    return count;
}

int LinkedList::count(const std::string& type) const {
    //traverse the list, every time the value is found incremenet the counter
    Node* ref = getHead();
    int count = 0;
    while(ref!=NULL) {
        if(ref->getValue().get_type() == type) {
            count++;
        }
        ref=ref->getNext();
    }
    return count;
}

int LinkedList::totalIncome() {
    //traverse the list each step adding the charge of the current vehicle. 
    Node* ref = getHead();
    int count = 0;
    while(ref!=NULL) {
        count+=ref->getValue().get_charge();
        ref=ref->getNext();
    }
    return count;
}
//bubble sort application
void LinkedList::order() {
    for(int i=0;i<size-1;i++) {
        Node* jRef = this->head;
        int j = 0;

        while(jRef!=NULL && jRef->getNext()!=NULL && j<size-i-1) {
            if(jRef->getValue().get_licence() > jRef->getNext()->getValue().get_licence()) {
                swap(jRef,jRef->getNext());
            }
            j++;
            jRef = jRef->getNext();
        }
    }
}

//this element does not involve instantiating a new list or even a new node or swapping values 
//For two elements to be swapped then anything pointing to A must be pointing to B, anything pointing to B must be pointing to A
//and A must be pointing to the elements B was pointing to and vice versa. 

//Normally when swapping two variables say int a and int b one must create a temporary variable. For example
// int a = 5;
// int b =7;
//
// int temp = a;
// a = b;
// b=  temp;
// however as we cannot create a temporary variable for this we instead use one one of the redudant links to act as a 'temporary variable' instead


// This works because as only half the links in a linked list are actually required. 
void LinkedList::swap(Node* nodeA, Node* nodeB) {
    //for swapping two elements define nodeA  = A, nodeB = B, A+ is the node after A, A- before A, B+ after node B, B- the node before B
    if(nodeA == NULL || nodeB==NULL) {
        //if either of the two nodes to be swapped are null then something very bad has happened. 
        throw std::invalid_argument(ERR_MSG_NULL_POINTER);
    }
    if(nodeA==nodeB) {
        return;
    } else if(nodeA->getNext() == nodeB) {
        //swapping two nodes next to eachother is fundamentally different to if they are seperated.
        swapNext(nodeA,nodeB);
    } else if(nodeB->getNext()==nodeA) {
        swapNext(nodeB,nodeA);
    } else {
        //swap a and b's forward reference, i.e make a point to b+ and b point to a+ 
        if(nodeA->getPrev()==NULL) {
            this->head = nodeB;
            //B- cannot be null as A is not equal to B
            nodeB->getPrev()->setNext(nodeA->getNext());
            nodeA->setNext(nodeB->getNext());
            nodeB->setNext(nodeB->getPrev()->getNext());
        } else {
            nodeA->getPrev()->setNext(nodeA->getNext());
            nodeA->setNext(nodeB->getNext());
            nodeB->setNext(nodeA->getPrev()->getNext());
        }
        //A+ was the old B+, if B+ pointed to NULL then A+ now points to NULL and thus A+ is now the tail
        if(nodeA->getNext()==NULL) {
            this->tail = nodeA;
            nodeB->getNext()->setPrev(nodeA->getPrev());
            nodeA->setPrev(nodeB->getPrev());
            nodeB->setPrev(nodeB->getNext()->getPrev());
        } else {
            nodeA->getNext()->setPrev(nodeA->getPrev());
            nodeA->setPrev(nodeB->getPrev());
            nodeB->setPrev(nodeA->getNext()->getPrev());
        }
        //clean up and fix the pointers of B-, B+, A-, A+, this must be done after otherwise the links will be lost
        if(nodeA->getPrev()==NULL) {
            this->head = nodeA;
        } else {
            nodeA->getPrev()->setNext(nodeA);
        }

        if(nodeA->getNext()!=NULL) {
            //the tail would have already been set if A+ is null from above
            nodeA->getNext()->setPrev(nodeA);
        }

        if(nodeB->getPrev()!=NULL) {
            //the head would have already been set from above if B- was null
            nodeB->getPrev()->setNext(nodeB);
        }
        
        if(nodeB->getNext()==NULL) {
            this->tail = nodeB;
        } else {
            nodeB->getNext()->setPrev(nodeB);
        }



    }
}

//b is directly after a 
void LinkedList::swapNext(Node* nodeA, Node* nodeB) {
    //swap node A and node B's forward references, i.e the references to a+ and b+
    nodeA->setNext(nodeB->getNext());
    if(nodeA->getNext()==NULL) {
        //as node A's forward pointer has been swapped if A's next is now null then we swapped with the previous head 
        this->tail = nodeA;
    } else {
        //otherwise fix up A+ backward pointer 
        nodeA->getNext()->setPrev(nodeA);
    }
    if(nodeA->getPrev()==NULL) {
        //the assumption is that nodeB is directly after node A, thus nodeB originally cannot be the head (otherwise the list is broken)
        //however is node A is currently the head then it needs to be moved to node B
        this->head = nodeB;
    } else {
        nodeA->getPrev()->setNext(nodeB);
    }
    //clean up the remaining pointers. 
    nodeB->setPrev(nodeA->getPrev());
    nodeB->setNext(nodeA);
    nodeA->setPrev(nodeB);
}


void LinkedList::operator+= (const LinkedList& list2) {
    Node* ref = list2.getHead();
    //traverse through list2, take the value of each element and create a new node at the end of 
    //this list with the same value.
    while(ref!=NULL) {
        //deep copy
        this->addToTail(ref->getValue());
        ref = ref->getNext();
    }
    this->size += list2.getSize();
}

void LinkedList::operator-= (const LinkedList& list2) {

    Node* ref = list2.getHead();
    //traverse through list 2
    while(ref!=NULL) {
        //check if the value is present in this list
        Node* thisCopy = this->getNode(ref->getValue());
        if(thisCopy!=NULL) {
            //if it is remove it from this list
            this->remove(thisCopy);
            this->size--;
        }
        ref = ref->getNext();
    }
}


std::ostream& operator << (std::ostream& out, const LinkedList& list) {
    //traverse through this list, printing each value seperated by tab spacing. 
    if(list.getTail() != NULL) {
        Node* ref = list.getHead();
        while(ref!=NULL) {
            out << ref->getValue();
            out << "    ";
            ref = ref->getNext();
        }
    } else {
        out << "The list is empty";
    }

    
    return out; 
}
