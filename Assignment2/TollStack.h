#ifndef TOLLSTACK_H
#define TOLLSTACK_H

#include "LStack.h"
#include "EToll.h"
#include <string>

/**
 * Note on the template 
 * 
 * The class template in the TollStack is unneccesary. Tollstack is a specialised class and thus will work only when EToll is used as 
 * the type definition. If any other type definition say EToll<int> is used there will be errors. Thus accepting any type definition would
 * make the code far less readable. Thus to improve the readability of this the template type T is ignored and instead a LStack of 
 * type Etoll is inherited. Unforunately the template is neccesary otherwise it wont work with the specifications of the assignment
 * brief. 
 * 
 */

template<typename T>
class TollStack: 
    public LStack<EToll> {

    public:
        //LStack constructor and destructor used (this is a subclass of LStack)

        /**
         *  Removes a node who's value has a license plate number of the string specified. If no element with said license plate
         *  number exists then nothing will happen. If there are multiple nodes with this license plate number then it will only 
         *  delete the first node 
         * 
         * //precondition none
         * //postcondition Deletes the first node with the specified license plate number
         * 
         * @param licenseNumber The license number to be removed 
         */

        void remove(const std::string& licenseNumber);


        /**
         *  Removes a node which matches the Etoll provided.  If no element with this EToll exits then nothing will happen. If
         *  there are multiple nodes matching this Etoll then only the first one will be removed. 
         * 
         * //precondition none
         * //postcondition Deletes the first node that matches this etoll
         * 
         * @param Etoll The Etoll object to be removed
         */

        void remove(const EToll& o);

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

        int count(const std::string& type);

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
        void operator-= (TollStack& stack2);

    private: 
        //nothing to hide yet 
};

/**
 *  Returns an output stream of the stack. This output stream contains each element's string value
 *  tab seperated from eachother. The output stream will have the stack bottom up. That means that the 
 *  first value shown is the bottom and the last value is the top. 
 * 
 * //precondition The type t must have an output stream defined 
 * //postcondition returns an output stream contain
 * 
 * @return An output stream with all the elements in the stack tab seperated bottom up.  
 * 
 */

template<typename T>
std::ostream& operator << (std::ostream& out, TollStack<T>& stack);

//Stack Implementation. 
/**
 * Note -
 * All Stack Traversals work as follows. 
 *   - make a temporary stack
 *   - pop the element off the original stack
 *   - do something with that element 
 *   - put that element on a temporary stack
 *   - when finished move all of the items from the temporary stack back onto the original to ensure
 *     that the stack is not altered
 * 
 */
template<typename T>
void TollStack<T>::remove(const std::string& licenseNumber) {
    //Perform a stack traversal (see note above)
    TollStack<EToll> temp;
    while(!this->empty()) {
        EToll value = this->pop();
        if(value.get_licence() == licenseNumber) {
            //we have found an element with the licesense number, dont place it on the temporary stack
            //so that it is not put back onto the original stack and is thus removed 
            break;
        }
        //only place the element on the temporary stack if it is not the element that is being removed
        //this wont create a memory leak as the pop method would have already destroyed the Node* 
        temp.push(value);
    }

    while(!temp.empty()) {
        this->push(temp.pop());
    }
}

template<typename T>
void TollStack<T>::remove(const EToll& o) {
    //Perform a stack traversal (see note above)
    TollStack<EToll> temp;
    while(!this->empty()) {
        EToll value = this->pop();
        if(o == value) {
            //we have found an element matching this etoll, dont place it on the temporary stack
            //so that it is not put back onto the original stack and is thus removed 
            break;
        }
        //only place the element on the temporary stack if it is not the element that is being removed
        //this wont create a memory leak as the pop method would have already destroyed the Node* 
        temp.push(value);
    }

    while(!temp.empty()) {
        this->push(temp.pop());
    }
}

template<typename T>
int TollStack<T>::count(const std::string& type) {
    TollStack<EToll> temp;
    //Perform a stack traversal (see note above)
    int count = 0;
    while(!this->empty()) {
        EToll value = this->pop();
        if(value.get_type() == type) {
            //every time a value with the specified type is found
            //increment the type
            count++;
        }
        temp.push(value);
    }

    while(!temp.empty()) {
        this->push(temp.pop());
    }
    return count;
}

template<typename T>
int TollStack<T>::totalIncome() {
    //Perform a stack traversal (see note above)
    TollStack<EToll> temp;
    int income = 0;
    while(!this->empty()) {
        EToll value = this->pop();
        //add the value of the charge of the vehicle in the stack. 
        income += value.get_charge();
        temp.push(value);
    }

    while(!temp.empty()) {
        this->push(temp.pop());
    }
    return income; 
}
//the other stack cannot be constant due to the nature of the stack 

template<typename T>
void TollStack<T>::operator-=(TollStack<T>& stack2) {
    TollStack<EToll> temp;
    //Perform a stack traversal (see note above)
    while(!stack2.empty()) {
        EToll value = stack2.pop();
        //attempt to remove this value from the original list 
        this->remove(value);
        temp.push(value);
    }

    while(!temp.empty()) {
        stack2.push(temp.pop());
    }
}

template<typename T>
std::ostream& operator<< (std::ostream& out, TollStack<T>& stack) {

    if(stack.empty()) {
        out << "List is empty";
    } else {
        //Perform a stack traversal (see note above)
        TollStack<EToll> temp;
        while(!stack.empty()) {
            //we want to print the list bottom up thus while we are putting the elements back together in the original stack thus
            //thus should not be added to the output yet as this traverses top down due to LIFO 
            EToll value = stack.pop();
            out << value << "    ";
            temp.push(value);
        }

        while(!temp.empty()) {
            //now that it is being traversed bottom up add the element's string value to the output stream. 
            stack.push(temp.pop());
        }
    }
    return out; 
}



#endif 