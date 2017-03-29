#include "Node.h"

#include <iostream>
#include "BinaryTree.h"

using namespace std;

void printData(Node* node)
    {
        cout<<node->key()<<":"<<node->value()<<endl;
    }
    
void BinaryTree::printTree(Node * root)
    {
        if (root->left()) {
            printTree(root->left());
        }

        printData(root);

        if (root->right()) {
            printTree(root->right());
        }
    }

void BinaryTree::addNode(Node * newNode)
    {
        //cout<<newNode->key()<<":"<<newNode->value()<<endl;
        //cout<<root()->key()<<":"<<root()->value()<<endl;

        Node* tmp = root();

        while (tmp) {
            if (tmp->key() > newNode->key()) {
                if (nullptr == tmp->left()) {
                    tmp->setLeft(newNode);
                    tmp = nullptr;
                }
                else
                    tmp = tmp->left();
            } else {
                if (nullptr == tmp->right()) {
                    tmp->setRight(newNode);
                    tmp = nullptr;
                }
                else
                    tmp = tmp->left();
            }
        }
    }
