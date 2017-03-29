#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include <iostream>

struct data {
    int key;
    std::string value;
    ~data() {std::cout<<"data Dtor"<<std::endl;}
};
    
class Node {
   
public:
    Node(data* data):_data(data),
       _left(nullptr),
       _right(nullptr) {
           
    }    
    
    Node(const Node& copy){
    }
    
    ~Node() {
        std::cout<<"~Node"<<std::endl;

        delete _data;
        _data = nullptr;

        delete _left;
        _left = nullptr;
        
        
        delete _right;
        _right = nullptr;
    }

    inline void setLeft(Node* left) {this->_left = left;}
    inline void setRight(Node* right) {this->_right = right;}

   Node *left() {
       return this->_left;
   }
   
   Node *right() {
       return this->_right;
   }   
    
    int key(){
        return this->_data->key;
    }
    
    
    std::string value(){
        return this->_data->value;
    }

private:
    data* _data;

    Node* _left;
    Node* _right;
};

#endif //ifndef __NODE_H__