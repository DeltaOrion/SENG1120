// LinkedList Class
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: A stack is a last in first out (LIFO) stack of elements. Only the top element is
// visible in a stack. The stack is a wrapper for the linked list class and has only 4 operands
// to ensure that the linked list works as a stack. That is the pop and push operands as well as
// a way to peek at the first element in the stack and whether the stack is empty or not. 


#ifndef LSTACK_H
#define LSTACK_H

#include "LinkedList.h"
#include <string>

/**
 * IMPORTANT Note
 * The bonus was attempted and thus LStack only contains methods relevant to generic stacks as instructed 
 * by the assignment brief. 
 */

template<typename T>
class LStack {

    public:
        //All stack in the list must have the same value type 
        /**
         *  Creates a new instance of a stack. The new stack
         *  will be empty and contain no elements.
         * 
         * //precondition none  
         * //postcondition Creates an empty stack. 
         *
         */
        LStack();

        /**
         *  Destructs a stack. This will delete the wrapped linked list 
         * 
         * //precondition none  
         * //postcondition Destructs the stack
         * 
         * 
         */

        ~LStack();

        /**
         * Tests if the stack is empty
         * 
         * precondition none
         * postcondition tests if the stack is empty 
         * 
         * @return whether the stack is empty 
         */

        bool empty() const;

        /**
         * Looks at the object on the top of the stack without removing it from the stack
         * 
         * precondition The stack is not empty 
         * postcondition retrieves the object ontop of the stack
         * 
         * @return The value of the element ontop of the stack
         * @throws runtime_error if the stack is empty
         */

        T peek() const;

        /**
         * Removes the element ontop of this stack and returns the element value 
         * 
         * precondition The stack is not empty
         * postcondition removes the element ontop of the stack,  
         * 
         * @return The value of the element that was ontop of the stack. 
         * @throws runtime_error is the stack is empty
         */

        T pop();

        /**
         * Pushes an item ontop of the stack. This would be the equivalent of adding an element to the
         * end of a list  
         * 
         * precondition none
         * postcondition tests if the stack is empty 
         * 
         * @param item the object which to push into the stack 
         */

        void push(const T& item);

        /**
         * Adds all of the elements from stack 2 to this stack. This will simply append stack2 onto 
         * this stack. That is the first element on stack2 will be appended to this stack and the last
         * element of stack 2 will be the last element of this stack. 
         * 
         * precondition none
         * postcondition tests if the stack is empty 
         * 
         * @return whether the stack is empty 
         */

        void operator += (LStack& stack2);

    private:
        LinkedList<T>* linkedlist; 
        std::string ERR_EMPTY_STACK;
};

//Class Implementation
//The stack implementation assumes that the HEAD is the top of the stack. This means that only the head
//is visible at any given tiem 

template<typename T>
LStack<T>::LStack() {
    linkedlist = new LinkedList<T>;
    //this would be a constant however using this syntax would only work on c++ 11 or higher
    //and thus to enusre this always compiled it is done as is. 
    ERR_EMPTY_STACK = "Stack is empty. Cannot perform requested operation.";
}

template<typename T>
LStack<T>::~LStack() {
    //call the wrapped linked list destructor
    delete linkedlist;
}

template<typename T>
bool LStack<T>::empty() const {
    //if the head (top) is NULL then the list and in turn the stack is empty 
    return this->linkedlist->getSize() == 0;
}

template<typename T>
T LStack<T>::peek() const {
    
    if(empty()) {
        throw std::runtime_error(ERR_EMPTY_STACK);
    }
    return linkedlist->getHead();
}

template<typename T>
T LStack<T>::pop() {
    if(empty()) {
        throw std::runtime_error(ERR_EMPTY_STACK);
    }
    //retrieve the value before deleting it from the list
    T value = linkedlist->removeHead();
    return value; 
}

template<typename T>
void LStack<T>::push(const T& item) {
    linkedlist->addToHead(item);
}

template<typename T>
void LStack<T>::operator+=(LStack<T>& stack2) {
    LStack<T> temp;
    while(!stack2.empty()) {
        EToll value = stack2.pop();
        temp.push(value);
        this->push(value);
    }

    while(!temp.empty()) {
        stack2.push(temp.pop());
    }

}

#endif