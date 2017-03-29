#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "Node.h"

class Node;
class BinaryTree {
    public:
    
    BinaryTree(Node * root): _root(root) {
    
    }
    
    ~BinaryTree()
    {        
        delete _root;
        _root = nullptr;    
    }
    
     BinaryTree(const BinaryTree &  );
     BinaryTree &  operator = (BinaryTree &  );

     // Construction APIS
     void addNode(Node * root);
     
     // Tree Traversal API
     inline Node * root() {return _root;}
     void printTree(Node * root);

    
    private:
    Node * _root;
    
};

#endif //__BINARY_TREE_H__