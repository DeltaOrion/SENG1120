// LinkedList Class
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: This class is an implementation of a 'doubly linked list'.  
//A linked list essentially acts as a set with size n. Each element of the set stores a value of type T.
// To allow the variable size of the list each element or node contains a reference to both the element after it and the element beofre it
// The nodes themselves are responsible for 'making up' and 'linking the list' together. This class is an interface for accessing, manipulating
// and traversing through elements in the list. 

#include "Node.h"
#include <iostream>
#include <string>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList {

    public:

        //All elements in the list must have the same value type 
        /**
         *  Creates a new instance of a linked list. The new linked list
         *  will be empty and contain no elements.
         * 
         * //precondition none  
         * //postcondition Creates an empty linked list
         * 
         * 
         */
        
        LinkedList();

        /**
         *  Destructs a linked list. This will delete the pointers to ALL nodes
         *  in the linked list to ensure there are no memory leaks. 
         * 
         * //precondition none  
         * //postcondition Destructs the linked list
         * 
         * 
         */

        ~LinkedList();

        //methods involving access

        /**
         *  Adds a new element to the start of linked list and replaces the current
         *  head with that element 
         * 
         * //precondition none  
         * //postcondition adds the element to the head of the linked list
         * 
         * @param value The value of the new element to be added to the linked list 
         */


        void addToHead(const T& value);

        /**
         *  Adds a new element to the end of linked list and replaces the current
         *  tail with thagt element 
         * 
         * //precondition none  
         * //postcondition adds the element to the tail of the linked list
         * 
         *  @param value The value of the new elemnent to be added to the linked list
         */

        void addToTail(const T& value);

        /**
         *  Retrieves the data value of the head of the list 
         * 
         * //precondition the list must be populated with at least one element
         * //postcondition retrieves the data value of the head of the list
         * 
         */

        T& getHead() const;


        /**
         *  Retrieves the data value of the tail of the list 
         * 
         * //precondition the list must be populated with at least one element 
         * //postcondition retrieves the data value of the tail of the list
         * 
         */

        T& getTail() const;

        /**
         *  Populates the output stream with a list representation in string form. This is neccesary for the output stream overload
         *  as friend functions are not allowed and only the value of the head, or tail can be accessed. One cannot have anything return
         *  a Node* so all list traversals must be internal. 
         * 
         * //precondition none
         * //postcondition populates the output stream with the list in a string representation
         * 
         * @return the populated output stream 
         *
         */

        std::ostream& toString(std::ostream& out) const;
        

        //elements for removing elements from the list 


        /**
         *  Removes the head node from the list and replaces the head with the next element in the list. IF 
         *  there is no element after the head then this will become an empty list again.  
         *  This will also delete the node. 
         * 
         * //precondition There is a head in the list 
         * //postcondition Deletes the head node from the list  
         * 
         * @throws std::invalid_argument if there is no head in the list
         * 
         */


        T removeHead();


        /**
         *  Removes the tail node from the list and replaces the tail with the element before it in the list. If this is the only node
         *  then this will become an empty list again. 
         * 
         * //precondition The list has a tail 
         * //postcondition Deletes the head node from the list 
         * 
         * @throws std::invalid_argument if there is no tail in the list 
         * 
         */


        T removeTail();


        /**
         *  Finds the first node with the selected value and if it exists removes it from the list. 
         * 
         * //precondition An element with the selected value must exist. 
         * //postcondition Deletes the head node from the list 
         * 
         * @throws std::invalid_argument if the request elemented cannot be found 
         * 
         */

        void remove(const T& value);

        //misc operations

        /**
         *  Returns the total size of the list. As the list index begins at 0 the tail element
         *  will be of index size-1
         * 
         * //precondition none
         * //postcondition returns a number representing the total size of the list. 
         * 
         * @return the total size of the list 
         * 
         */

        int getSize() const;

        /**
         *  Concatenates all the elements of a second list onto the end of this list. This will make
         *  copies of the elements in list 2 by taking the value of each node and then appending it 
         *  to the tail of this list. This means the two lists will remain distinct. 
         * 
         * //precondition none
         * //postcondition Copies and appends each element of list2 onto this list. 
         * 
         */

        void operator += (const LinkedList& list2);

        /**
         *  Subtracts the elements of list 2 from this list. This will iterate through the elements of list 2 and
         *  if the value of an arbitrary element in list 2 can be found in this list then it will be removed 
         *  from this list. If there are multiple elements with the value of a given arbitrary element in list 2 to then it will 
         *  remove the first one it finds. THis means that if list 2 has 3 elements of value 'a' and this list has 4 elements
         *  of value 'a' then 3 elements of value 'a' will be removed from this list. 
         * 
         * //precondition none
         * //postcondition attempts to subtract the elements from the second linked list from this list. 
         * 
         */

        void operator -= (const LinkedList& list2);

        /**
         *  Counts the number of a elements there is in a list with the specified value. 
         * 
         * //precondition none
         * //postcondition returns the amount of a given element there are in a list. 
         * 
         * @param value The specific value which to count with
         * @return how many elements have the @value as their value. 
         * 
         */

        int count(const T& value) const;


    private:
        Node<T>* head;
        Node<T>* tail; 
        Node<T>* current; 
        int size; 
        //I would make these constant however this will only work on c++ 11 so to be safe and ensure this compiles no matter what
        //these strings are no longer constant. 
        std::string ERR_MSG_OUT_BOUNDS;
        std::string ERR_MSG_NULL_POINTER;
        void swapNext(Node<T>* nodeA, Node<T>* nodeB);


        /**
         *  Retrieves the reference node in the list. This node is used to traverse and iterate
         *  across the linked list. This will return NULL if there are no elements in the linked list. 
         * 
         * //precondition none
         * //postcondition Retrieves a node of said index in the list 
         *
         */

        Node<T>* getCurrent() const;

        /**
         *  Changes the value of the reference node in the list. THis node is used to traverse and iterate across the linked 
         *  list.
         * 
         * //precondition none
         * //postcondition sets the value of current
         * 
         * @param newCurrent The new value of current
         */

        void setCurrent(Node<T>* newCurrent) const; 
        

        /**
         *  Retrieves a node by value type in the list. This will attempt to find a node 
         *  who's value is the same as the value specified. If it cannot find said value
         *  then this will return NULL. This does not filter, it will instead find the first
         *  element with this value. If there are other elements with the value specified they
         *  will by ignored. 
         * 
         * //precondition none
         * //postcondition retrieves a node by value type in the list. If it does not exist it will
         * return null and if there are multiple elements with this value it will return the first. 
         * 
         *  @param value The value which to find an element with 
         *  @return a node with the value specified 
         */

        Node<T>* getNode(const T& value) const;

        /**
         *  Removes the selected node from the list. If this node is the head or tail it will be treated the same
         *  as the removeTail nd the removeHead functions. 
         * 
         * //precondition the node must not be null 
         * //postcondition Deletes the selected node from the list. 
         * 
         * @throws std::invalid_argument if the node is null
         * 
         */

        T remove(Node<T>* node);

        /**
         *  Swaps the position of two arbitrary elements in the list. If element A was in index 3 and element B was in 
         *  index 5 after the swap element B would be in index 3 and element A in index 5.
         * 
         * //precondition Both elements are in the list and neither are null
         * //postcondition swap's the two elements positions in the list 
         *
         * 
         */

        void swap(Node<T>* nodeA, Node<T>* nodeB);
};

/**
 *  Returns an output stream of the linked list. This output stream contains each element's string value
 *  tab seperated from eachother.  
 * 
 * //precondition The type t must have an output stream defined 
 * //postcondition returns an output stream contain
 * 
 * @return An output stream with all the elements in the linked list tab seperated. 
 * 
 */

template<typename T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list);

// LinkedList Class
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: Implementation of the "linkedlist.h" class template 
template<typename T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->current = NULL;
    this->size = 0;
    //standard error messages for when an illegal action is made. 
    ERR_MSG_OUT_BOUNDS = "Received index out of list bounds";
    ERR_MSG_NULL_POINTER = "Null Pointer Exception. Cannot manipulate node as it is null";
}

//Destructs the list by traversing through it and deleting each node one by one. 
template<typename T>
LinkedList<T>::~LinkedList() {
    
    Node<T>* ref = this->head;
    Node<T>* next;

    while(ref != NULL) {
        next = ref->getNext();
        delete ref; 
        ref = next;
    }
}
template<typename T>
void LinkedList<T>::addToHead(const T& value) {
    //instantiate the new node
    Node<T>* newNode = new Node<T>(value);
    
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

template<typename T>
void LinkedList<T>::addToTail(const T& value) {
    
    if(this->tail==NULL) {
        //if list is empty add to head
        addToHead(value);
    } else {
        //instiate the new node
        Node<T>* newNode = new Node<T>(value);
        newNode->setPrev(tail);
        //point the tail to this new node
        tail->setNext(newNode);
        tail = tail->getNext();
        this->size++;
    }
    
}

template<typename T>
T LinkedList<T>::removeHead() {
    //if the list is empty then they are removing an element out of list bounds
    if(this->head==NULL) {
        throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
    }
    //create a temporary reference to the head 
    Node<T>* temp = this->head;  
    T value = temp->getValue();

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

    return value; 

}

template<typename T>
T LinkedList<T>::removeTail() {
    //if the tail is empty then the list is empty thus they are trying
    //to remove an element out of list bounds 

    if(this->tail==NULL) {
        throw std::invalid_argument(ERR_MSG_OUT_BOUNDS);
    }


    Node<T>* temp = this->tail;

    T value = temp->getValue();

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

    return value;
}

template<typename T>
T LinkedList<T>::remove(Node<T>* node) {
    //if the node being removed is null then something very bad has happened. 
    if(node==NULL) {
        throw new std::invalid_argument(ERR_MSG_NULL_POINTER);
    }

    T value = node->getValue();

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

    return value;
}

template<typename T>
void LinkedList<T>::remove(const T& value) {
    Node<T>* node = getNode(value);
    remove(node);
}

template<typename T>
Node<T>* LinkedList<T>::getNode(const T& value) const {
    //traverse the list until one element's data value matches the desired one
    Node<T>* ref = this->head;
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

template<typename T>
T& LinkedList<T>::getHead() const {
    return this->head->getValue();
}

template<typename T>
T& LinkedList<T>::getTail() const {
    return this->tail->getValue();
}


template<typename T>
int LinkedList<T>::getSize() const {
    return this->size;
}

template<typename T>
std::ostream& LinkedList<T>::toString(std::ostream& out) const {
    if(tail != NULL) {
        Node<T>* ref = head;
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

template<typename T>
int LinkedList<T>::count(const T& value) const {
    //traverse the list, every time the value is found incremenet the counter
    Node<T>* ref = head;
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
template<typename T>
void LinkedList<T>::swap(Node<T>* nodeA, Node<T>* nodeB) {
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
template<typename T>
void LinkedList<T>::swapNext(Node<T>* nodeA, Node<T>* nodeB) {
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

template<typename T>
void LinkedList<T>::operator+= (const LinkedList<T>& list2) {
    Node<T>* ref = list2.head;
    //traverse through list2, take the value of each element and create a new node at the end of 
    //this list with the same value.
    while(ref!=NULL) {
        //deep copy
        this->addToTail(ref->getValue());
        ref = ref->getNext();
    }
}

template<typename T>
void LinkedList<T>::operator-= (const LinkedList<T>& list2) {

    Node<T>* ref = list2.head;
    //traverse through list 2
    while(ref!=NULL) {
        //check if the value is present in this list
        Node<T>* thisCopy = this->getNode(ref->getValue());
        if(thisCopy!=NULL) {
            //if it is remove it from this list
            this->remove(thisCopy);
            this->size--;
        }
        ref = ref->getNext();
    }
}

template<typename T>
std::ostream& operator << (std::ostream& out, const LinkedList<T>& list) {
    //traverse through this list, printing each value seperated by tab spacing. 
    return list.toString(out);    
}


#endif
