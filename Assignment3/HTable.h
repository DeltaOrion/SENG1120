// Hash Table Class Header
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: A hashtable is a data structure which stores data values. It offers constant time performance for basic operations such as insert, add, search,
// and remove. However iterating over the hashtable will have a time performance proportional to the capacity of the hashtable. 
//
// The hashtable works by storing an array with all of the data values. Each slot in the array contains buckets and the buckets contain one or many data values. When a data 
// value is inserted into the hash table a function is used to map it to its relevant position in the array. However as the space of potential values T to be inserted into the hashtable 
// is infinite and because the amount of spaces in the array is finite there will be collisions, i.e when two data values are mapped to the same position in the array. When this occurs the 
// data value is inserted into the 'bucket' at that position. Each bucket is a 'linked list' and the value is simply added to the linked list at that position. 
//


#ifndef HTABLE_H
#define HTABLE_H

#include "LinkedList.h"
#include <string>
#include <sstream> 
#include "MechPart.h"

template<typename T>
class HTable {  
    
    public:
        /**
         *  Creates a new instance of a hashtable
         * 
         * //precondition none
         * //postcondition A hashtable is instansiated. It will be empty by default. 
         * 
         */
        HTable();

        /**
         *  Destroys a hashtable
         * 
         * //precondition none
         * //postcondition The hashtable is destroyed. 
         * 
         */

        ~HTable();

        /**
         *  Inserts an element into the hashtable
         * 
         * //precondition none
         * //postcondition The element is inserted into the hashtable 
         * 
         * @param value The data value to be entered into the hashtable
         */

        void add(const T& value);        

        /**
         *  Inserts an element into the hashtable
         * 
         * //precondition none
         * //postcondition The element is inserted into the hashtable 
         * 
         * @param value The data value to be entered into the hashtable
         */

        void remove(const T& value);

        /**
         *  Converts the hashtable into a string representation. Each value will be tab spaced from the next
         * 
         * //precondition none
         * //postcondition The element is inserted into the hashtable 
         * 
         * @param value The data value to be entered into the hashtable
         */

        std::string toString() const;

        /**
         *  Calculates the amount of unique parts in the table
         * 
         * //precondition none
         * //postcondition Retruns the amount of unique parts in the table
         * 
         * @param return the amount of unique parts in the tree.
         */


        int calculateParts() const;

        /**
         *  Calculates the amount of parts in the inventory. Each mechpart has a quantity and this essentially sums the quantity of items
         * 
         * //precondition none
         * //postcondition returns the sum of the quantity of all of the mechparts in the table
         * 
         * @param return the sum of all the unique parts in the table
         */


        int calculateInventory() const;

        /**
         *  Calculates the amount of parts in the table that have a quantity less than x
         * 
         * //precondition none
         * //postcondition calculates the amount of parts in the table that have a quantity less than x
         * 
         * @param return the amount of parts in the table that have a quantity less than x
         */

        int calculateLessThan(int x) const;
    private:
        /**
         *  Converts the value given into a positional index in the array. The hash function maps a value from an arbitrary size
         *  into a fixed size.
         * 
         * //precondition none
         * //postcondition Maps a given value which is in arbitrary space into a fixed space.
         * 
         * @param return a positional index for an array. 
         */

        int hashfun(const T& value);
        //values dealing with the physical table. 
        int TABLE_SIZE;
        LinkedList<T> **table;
};

template<typename T>
std::ostream& operator << (std::ostream& out, const HTable<T>& table);

template<typename T>
HTable<T>::HTable() {
    //create an array of fixed size representing the table
    TABLE_SIZE = 300;
    table = new LinkedList<T> * [TABLE_SIZE];
}

template<typename T>
HTable<T>::~HTable() {
    //destroy the table by looping through all of the buckets
    //and desatroying them 
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i]!=NULL) {
            delete table[i];
        }
    }
}

template <typename T>
int HTable<T>::hashfun(const T& value) {
    int position = 0;
    std::string temp = value.get_code();
    for (int i=0; i<(int)temp.length(); i++)
    {
        position += (i+1) * (i+1) * temp.at(i);
    }
    return position % TABLE_SIZE;
}


template<typename T>
void HTable<T>::add(const T& value) {
    //get the position of this value from the hashfunction
    int position = hashfun(value);
    //add it to the relevant bucket. 
    LinkedList<T>* bucket = table[position];
    if(bucket==NULL) {
        bucket = new LinkedList<T>();
        table[position] = bucket;
    }
    bucket->addToTail(value);
}

template<typename T>
void HTable<T>::remove(const T& value) {
    //find the position of this value in the hash table.
    int position = hashfun(value);
    LinkedList<T>* bucket = table[position];
    //find the position in the bucket. 
    if(bucket==NULL) {
        return;
    }
    bucket->remove(value);
}

template<typename T> 
std::string HTable<T>::toString() const {
    //loop through all the buckets in the table
    std::stringstream ss;
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i]!=NULL) {
            //add a string representation of the bucket
            if((table[i])->getSize()>0) {
                for(int j=0;j<table[i]->getSize();j++) {
                    ss << table[i]->get(j);
                    ss << " ";
                }
            }
        }
    }
    return ss.str();
}

template<typename T>
int HTable<T>::calculateParts() const {
    int count = 0;
    //loop through the table adding the capacity of the linked list
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i]!=NULL) {
            count += table[i]->getSize();
        }
    }
    return count;
}

template<typename T>
int HTable<T>::calculateInventory() const {
    int count = 0;
    //loop through all elements in the hashtable adding the quantity of each mechpart. 
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i]!=NULL) {
            for(int j=0;j<table[i]->getSize();j++) {
                count += table[i]->get(j).get_quantity();
            }
        }
    }
    return count;
}

template<typename T>
int HTable<T>::calculateLessThan(int x) const {
    //loop through all elements in the hashtable adding any element that has less than x parts.
    int count = 0;
    for(int i=0;i<TABLE_SIZE;i++) {
        if(table[i]!=NULL) {
            for(int j=0;j<table[i]->getSize();j++) {
                if(table[i]->get(j).get_quantity()<x) {
                    count++;
                }
            }
        }
    }
    return count;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const HTable<T>& table) {
    out << table.toString();
    return out;
}

#endif // HTABLE_H