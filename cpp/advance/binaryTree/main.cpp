/* Implement a binary search tree to store key/value pairs.
 * It should be possible to use any data type for key and value.
 * Implement needed data structures
 * Implement following methods:
 *  * constructor
 *  * destructor
 *  * printTree() - to print all key/value pairs in sorted order
 *  * it should be possible to use [key] to get the value assotiated with the given key
 *  * fromArray(const T array[], const int arraySize) - assembles binary search tree using sorted
 *      array of keys as input (values should be initialized to their default)
 */

/*
 *      5
 *     / \
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * */

#include <iostream>

#include "Node.h"
#include "BinaryTree.h"

using namespace std;

int main(int argc, char** argv) { 
    data* myData = new data();
    myData->key = 5;
    myData->value = string("Five");

    Node* node = new Node(myData);
    BinaryTree* tree = new BinaryTree(node);
    //tree->printTree(node);

    myData = new data();
    myData->key = 2;
    myData->value = string("Two");

    Node* newNode = new Node(myData);
    tree->addNode(newNode);

    myData = new data();
    myData->key = 7;
    myData->value = string("Seven");

    newNode = new Node(myData);
    tree->addNode(newNode);

    myData = new data();
    myData->key = 4;
    myData->value = string("Four");

    newNode = new Node(myData);
    tree->addNode(newNode);

    cout<<"***********************************Tree**************************************"<<endl;
    tree->printTree(tree->root());

    delete tree;

    return 0;
}
