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

class LinkedList {

    public:

        //All elements in the list must have the same value type 
        typedef Node::type type;

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

        void addToHead(const type& value);

        /**
         *  Adds a new element to the end of linked list and replaces the current
         *  tail with thagt element 
         * 
         * //precondition none  
         * //postcondition adds the element to the tail of the linked list
         * 
         *  @param value The value of the new elemnent to be added to the linked list
         */

        void addToTail(const type& value);

        //methods which retrieve values of elements 

        /**
         *  Retrieves the head of the linked list. If the list is empty this will 
         *  retrieve NULL 
         * 
         * //precondition 
         * //postcondition adds the element to the tail of the linked list
         * 
         *  @return A the head noed of the list 
         */



        Node* getHead() const;

        /**
         *  Retrieves the tail of the linked list. If the list is empty this
         *  will retrieve null 
         * 
         * //precondition 
         * //postcondition retrieves the tail of the linked list
         * 
         *  @return A the tail node of the list 
         */

        Node* getTail() const;

        /**
         *  Retrieves a node in the linked list by element index. The first
         *  element in the list is index 0 while the last is index size - 1. 
         * 
         * //precondition The index is inside of list bounds, i.e between 0 and the size -1. 
         * //postcondition Retrieves a node of said index in the list 
         * 
         *  @return the node in the desired index of the list. 
         *  @throws std::illegal_argument if the index is out of list bounds 
         */

        Node* getNode(const int index) const;

        /**
         *  Retrieves the reference node in the list. This node is used to traverse and iterate
         *  across the linked list. This will return NULL if there are no elements in the linked list. 
         * 
         * //precondition none
         * //postcondition Retrieves a node of said index in the list 
         *
         */

        Node* getCurrent() const;

        /**
         *  Changes the value of the reference node in the list. THis node is used to traverse and iterate across the linked 
         *  list.
         * 
         * //precondition none
         * //postcondition sets the value of current
         * 
         * @param newCurrent The new value of current
         */

        void setCurrent(Node* newCurrent) const; 
    

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

        Node* getNode(const type& value) const;


        /**
         *  Retrieves a node by its etoll license plate number. If no node with said license plate number exists
         *  then this will return null otherwise. If there are multiple values with said license plate number then
         *  this will return the first element with the liense plate number 
         * 
         * //precondition The linked list type must be of 'etoll' 
         * //postcondition retrieves a node by value type in the list. If it does not exist it will
         * return null and if there are multiple elements with this value it will return the first. 
         * 
         *  @param value The license plate number value to find an element with 
         *  @return a node with the value specified 
         */


        Node* getNode(const std::string& value) const;

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


        void removeHead();


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


        void removeTail();

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

        void remove(Node* node);

        /**
         *  Finds the first node with the selected value and if it exists removes it from the list. 
         * 
         * //precondition An element with the selected value must exist. 
         * //postcondition Deletes the head node from the list 
         * 
         * @throws std::invalid_argument if the request elemented cannot be found 
         * 
         */

        void remove(const type& value);

        /**
         *  Removes a node who's value has a license plate number of the string specified. If this node is the head
         *  or the tail then the head or tail will be moved. An element with said license plate number must exist. If
         *  there are multiple nodes with this license plate number then it will only delete the first node 
         * 
         * //precondition An element with the license plate number exists
         * //postcondition Deletes the first node with the specified license plate number
         * 
         * @throws std::invalid_argument if the request elemented cannot be found 
         * 
         */

        void remove(const std::string& name);

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

        //there is a lot of repetition between the count, totalincome and cout functions. In reality 
        //An iterator and a functional foreach interface should be made here but I believe that
        //is out of the scope of this assignment so I have just repeated the code instead. 


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

        int count(const type& value) const;

        /**
         *  Counts the number of a elements there is in a list with the given vehicle type. 
         * 
         * //precondition There type t must be of 'Etoll'
         * //postcondition returns the amount of a given element there are in a list. 
         * 
         * @param value The specific vehicle type to count with
         * @return how many elements have the specified vehicle type as their value
         * 
         */

        int count(const std::string& type) const;

        /**
         *  Sums the 'charge' of all vehicles in the list. 
         * 
         * //precondition The type t must be of 'Etoll'
         * //postcondition returns the summation of the charge of all vehicles in the list 
         * 
         * @return summation of the charge of all vehicles in the list 
         * 
         */

        int totalIncome();

        /**
         *  Orders the elements in the list in ascending order by license number
         * 
         * //precondition The type t must be of 'Etoll'
         * //postcondition Orders the elements in the list in ascending order by license number 
         * 
         * 
         */

        void order();

        /**
         *  Swaps the position of two arbitrary elements in the list. If element A was in index 3 and element B was in 
         *  index 5 after the swap element B would be in index 3 and element A in index 5.
         * 
         * //precondition Both elements are in the list and neither are null
         * //postcondition swap's the two elements positions in the list 
         *
         * 
         */

        void swap(Node* nodeA, Node* nodeB);

    private:
        Node* head;
        Node* tail; 
        Node* current; 
        int size; 
        //I would make these constant however this will only work on c++ 11 so to be safe and ensure this compiles no matter what
        //these strings are no longer constant. 
        std::string ERR_MSG_OUT_BOUNDS;
        std::string ERR_MSG_NULL_POINTER;
        void swapNext(Node* nodeA, Node* nodeB);
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

std::ostream& operator << (std::ostream& out, const LinkedList& list);

#endif
