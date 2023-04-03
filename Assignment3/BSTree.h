// Binary Tree Node Class Header
/*******************************/
// Author: Jacob Boyce
// Course: SENG1120
// Student-Number: c3264527 
// Program Description: A binary search tree is a sorted rooted binary tree data structure who's nodes each act as subtree's themselves. Each
// node in the tree has a left and right subtree. All elements in the left subtree have values less than this node and all elements to the right
// have values greater than this node. There are two different types of nodes, branch nodes and leaf nodes. A node is a leaf node if it has no connections,
// that is the left and right nodes are both NULL, and a node is a branch node if otherwise. 
//
// This class is a wrapper class for BTNode.h or the binary tree node class. This class interacts with a special node in the tree called the root 
// node. Due to the structure of the rooted tree, by interacting with the root all subtrees can be accessed. By interacting with the root node all
// nodes can be accessed and manipulated. 
//


#ifndef BSTREE_H
#define BSTREE_H

#include "BTNode.h"
#include <sstream> 
#include <iostream>
#include <functional>

template<typename T>
class BSTree {
    public:

        /**
         *  Creates a new instance of a binary search tree. 
         * 
         * //precondition none
         * //postcondition A binary tree is instanciated. It will be empty by default. 
         * 
         */

        BSTree();

        /**
         *  Destructor for a binary search tree
         * 
         * //precondition None
         * //postcondition The binary search tree is destroyed
         *
         */


        ~BSTree();

        /**
         *  Inserts an element into the binary search tree. If the element already exists
         *  it simply wont be added into the tree. 
         * 
         * //precondition None
         * //postcondition A node class is instansiated, the default is an empty node 
         * 
         * @param value The data value to be inserted into the tree. 
         */


        void add(const T& value);

        /**
         *  Removes an element from the binary search tree. 
         * 
         * //precondition The element must exist inside of the BST. 
         * //postcondition The element must exist in the binary search tree. 
         * 
         * @param value The data value to be removed from the tree. 
         * @return the data value which was removed from the tree. 
         */

        T remove(const T& value);

        /**
         *  Converts the binary tree into a 2D string representation using an inorder traversal. The
         *  representation is as is
         *   
         *  | | Very Left
         *  | Left
         *  Root
         *  | Right
         *  | | Very Right 
         * 
         * //precondition Type t has a default constructor
         * //postcondition A node class is instansiated, the default is an empty node 
         * 
         * @
         */

        std::string toString() const;

        /**
         *  Calculates the amount of unique parts are in the tree. 
         * 
         * //precondition none
         * //postcondition Retruns the amount of unique parts in the tree
         * 
         * @param return the amount of unique parts in the tree.
         */


        int calculateParts() const;

        /**
         *  Calculates the amount of parts in the inventory. Each mechpart has a quantity and this essentially sums the quantity of items
         * 
         * //precondition none
         * //postcondition returns the sum of the quantity of all of the mechparts in the tree 
         * 
         * @param return the sum of all the unique parts in the tree
         */


        int calculateInventory() const;

        /**
         *  Calculates the amount of parts in the tree that have a quantity less than x
         * 
         * //precondition none
         * //postcondition calculates the amount of parts in the tree that have a quantity less than x
         * 
         * @param return the amount of parts in the tree that have a quantity less than x
         */


        int calculateLessThan(int x) const;

    private: 

        BTNode<T>* root; 

        /**
         *  helper function to add a specified node into the tree. This function inserts it recursively. To
         *  use this function properly one should use the root as the first call with the desired value
         * 
         * //precondition none
         * //postcondition Recursively inserts the specified value into the tree
         * 
         */


        void add(BTNode<T>* node, const T& value);

        /**
         *  helper function to recursively remove the specified value from the tree. To use this function properly
         *  one should use the root as the first call with the desired value. 
         * 
         * //precondition none
         * //postcondition Recursively removes the specified value from the tree
         * 
         */

        BTNode<T>* remove(BTNode<T>* node, const T& value);

        /**
         *  helper function to convert the binary tree into a 2D string representation. To use this function properly
         *  one should use the root as the first function call with a prefix of "". This uses an inorder traversal.
         * 
         * //precondition none
         * //postcondition Recursively inserts the specified node into the tree
         * 
         */

        std::string output(const BTNode<T>* node) const; 

        /**
         *  helper function to destroy the binary tree. To use this function properly
         *  the first call should use the root. This uses an postorder traversal.
         * 
         * //precondition none
         * //postcondition Recursively destroys the binary search tree. 
         * 
         */

        void destroy(BTNode<T>* node);

        /**
         *  Helper function to calculate the amount of unqiue parts in the binary search tree. To use this
         *  function properly the first call should use the root. This uses an inorder traversal.
         * 
         * //precondition none
         * //postcondition Rercursively counts the amount of nodes in the binary search tree.
         * 
         */

        int calculateParts(BTNode<T>* node) const;

        /**
         *  helper function to calculate the inventory size in the binary tree. This recursively counts
         *  the quantity of parts in the tere. To use this function properly the first call shbould use
         *  the root. This uses an inorder traversal.
         * 
         * //precondition none
         * //postcondition Recursively counts the inventory size in the binary search tree. 
         * 
         */

        int calculateInventory(BTNode<T>* node) const;

        /**
         *  helper function to calculate the amount of nodes with quantity less than x in the
         *  binary search tree. This uses an inorder traversal.
         * 
         * //precondition none
         * //postcondition Recursively counts the amount of nodes with quantity less than x in the search tree.
         * 
         */

        int calculateLessThan(BTNode<T>* node, int x) const;

};

/**
 *  Converts the binary tree into a 2D string representation using an inorder traversal. The
 *  representation is as is
 *   
 *  | | Very Left
 *  | Left
 *  Root
 *  | Right
 *  | | Very Right 
 * 
 * //precondition Type t has a default constructor
 * //postcondition A node class is instansiated, the default is an empty node 
 * 
 */


template<typename T>
std::ostream& operator << (std::ostream& out, const BSTree<T>& node);

template<typename T>
BSTree<T>::BSTree() {
    //a null root means the BST is empty. 
    root = NULL;
}

template<typename T>
BSTree<T>::~BSTree() {
    destroy(this->root);
}

template<typename T>
void BSTree<T>::destroy(BTNode<T>* node) {
    if(node!=NULL) {
        //use a postorder traversal to destroy the nodes to the left, then the right and then finnally this node. 
        destroy(node->getLeft());
        destroy(node->getRight());
        delete node;
    }
}

template<typename T>
void BSTree<T>::add(const T& value) {
    if(root==NULL) {
        //instantiate the root
        BTNode<T>* node = new BTNode<T>(value);
        this->root = node;
    } else {
        //otherwise use the helper function
        add(root,value);
    }
}

template<typename T>
void BSTree<T>::add(BTNode<T>* node, const T& value) {
    if(value < node->getValue()) {
        //only insert if the left is empty. 
        if(node->getLeft()==NULL) {
            BTNode<T>* left = new BTNode<T>(value);
            node->setLeft(left);
        }  else {
            add(node->getLeft(),value);
        }
    } else if(value==node->getValue()) {
        //if a match is found skip this insert. 
        return;
    } else {
        if(node->getRight()==NULL) {
            //only insert if the right is null.
            BTNode<T>* right = new BTNode<T>(value);
            node->setRight(right);
        } else {
            add(node->getRight(),value);
        }
    }
}

template<typename T>
std::string BSTree<T>::toString() const {
    if(root!=NULL) {
        return output(root);
    } else {
        return "The tree is empty";
    }
}

template<typename T>
std::string BSTree<T>::output(const BTNode<T>* node) const {
    std::string str = "";
    //if the node exists use inorder traversal
    if(node!=NULL) {
        //add the left node
        str += this->output(node->getLeft());
        //add the current node. Use a stringstream to utilise the the overloaded << that is very common. 
        std::stringstream ss;
        ss << node->getValue();
        //add the right node
        str += ss.str() + " ";
        str += this->output(node->getRight());
    } 
    return str;
}

template<typename T>
T BSTree<T>::remove(const T& value) {
    root = remove(root,value);
    return value;
}

template<typename T>
BTNode<T>* BSTree<T>::remove(BTNode<T>* node, const T& value) {
    if(node==NULL) {
        return node;
    }
    //taking each case improves the performance of this algorithm as we do not need to shift the lowest value from the right
    //when the node only has one child or no child. 
    if(value < node->getValue()) {
        node->setLeft(remove(node->getLeft(),value));
        return node;
    } else if(value > node->getValue()) {
        node->setRight(remove(node->getRight(),value));
        return node;
    } else {
        if(node->getLeft() == NULL && node->getRight() == NULL) {
            //case 1) node has no children, it is safe to delete the leaf node!
            delete node;
            return NULL;
        } else if(node->getLeft() == NULL) {
            //case 2) the node has one child, we can simply replace the parents node with whatever the single child is
            BTNode<T>* temp = node->getRight();
            delete node;
            return temp;
        } else if(node->getRight() == NULL) {
            BTNode<T>* temp = node->getLeft();
            delete node;
            return temp;
        } else {
            //case 3) Both children exist. The comments below should explain the logic of removing this. 
            BTNode<T>* smallestParent = node;
            BTNode<T>* smallestFrom = node->getRight();
            while(smallestFrom->getLeft()!=NULL) {
                smallestParent = smallestFrom;
                smallestFrom = smallestFrom->getLeft();
            }

            if(smallestParent==node) {
                /**
                 * Case 1) The smallest parent is
                 * 
                 * These comments should explain the logic of removing a node when it has two children.
                 * 
                 * Suppose from the tree we are deleting 3
                 *             5
                 *            /  \
                 *           3    8 
                 *         /   \
                 *        2     4
                 *               \
                 *                4.5
                 *                  \ 
                 *                    5
                 * 
                 * In this case the smallest node from the right is simply the 4 and its parent is 3 which we are 
                 * trying to delete. We need to move whatever is right of it (the 4.5) to the right of the 3.
                 * 
                 *             5                   not connected
                 *            /  \                      4
                 *           3    8 
                 *         /   \
                 *        2     4.5
                 *               \
                 *                5
                 * 
                 * Now we can simply replace the value of the 3 with the 4
                 *
                 *             5                   not connected
                 *            /  \                      4
                 *           4    8 
                 *         /   \
                 *        2     4.5
                 *               \
                 *                5
                 * 
                 * As you can see the original 4 node is now junk and should be deleted to avoid memory leaks. 
                 */ 
                smallestParent->setRight(smallestFrom->getRight());
            } else {
                /**
                 * Suppose from the tree we are deleting 4
                 *             5
                 *            /  \
                 *           3    8 
                 *         /   \
                 *        2     4
                 *             /
                 *            3.5
                 *             \
                 *              3.35  
                 *                \
                 *                 3.45
                 * 
                 * In this case the smallest node from the right is now the 3.5. This should be replaced to whatever is to the right of it. 
                 * 
                 *             5                not connected 
                 *            /  \                   3.5
                 *           3    8 
                 *         /   \
                 *        2     4
                 *             /
                 *            3.35
                 *             \ 
                 *               3.45
                 * 
                 * Now we can simply replace the value of the 3 with the 3.5
                 * 
                 *             5                not connected 
                 *            /  \                   3.5
                 *          3.5   8 
                 *         /   \
                 *        2     4
                 *             /
                 *            3.35
                 *             \ 
                 *               3.45
                 * 
                 * As you can see the original 3.5 node is junk and should be deleted to avoid memory leaks. 
                 */ 
                smallestParent->setLeft(smallestFrom->getRight());
            }

            node->setValue(smallestFrom->getValue());

            delete smallestFrom;
            //ensure the parent has the correct connection to this node now. 
            return node;
        }
    }
}

template<typename T>
int BSTree<T>::calculateParts() const {
    return calculateParts(root);
}

template<typename T>
int BSTree<T>::calculateParts(BTNode<T>* node) const {
    int quantity = 0;
    if(node!=NULL) {
        //use inorder traversal and add one for each node that exists. 
        quantity += calculateParts(node->getLeft());
        quantity += 1;
        quantity += calculateParts(node->getRight());
    }
    return quantity;
}

template<typename T>
int BSTree<T>::calculateInventory() const {
    return calculateInventory(root);
}

template<typename T>
int BSTree<T>::calculateInventory(BTNode<T>* node) const {
    int quantity = 0;
    if(node!=NULL) {
        //use inorder traversal adding the quantity of each node that exists
        quantity += calculateInventory(node->getLeft());
        quantity += node->getValue().get_quantity();
        quantity += calculateInventory(node->getRight());
    }
    return quantity;
}

template<typename T>
int BSTree<T>::calculateLessThan(int x) const {
    return calculateLessThan(root,x);
}

template<typename T>
int BSTree<T>::calculateLessThan(BTNode<T>* node, int x) const {
    int quantity = 0;
    if(node!=NULL) {
        //use inorder traversal
        quantity+= calculateLessThan(node->getLeft(),x);
        //if the node has less than x values in it then add its quantity
        if(node->getValue().get_quantity()<x) {
            quantity++;
        }
        quantity+= calculateLessThan(node->getRight(),x);
    }
    return quantity;
}


template<typename T>
std::ostream& operator << (std::ostream& out, const BSTree<T>& tree) {
    //return the string representation of the tree
    out << tree.toString();
    return out;
}



#endif // BSTREE_H