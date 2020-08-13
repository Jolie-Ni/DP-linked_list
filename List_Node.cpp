//
// Created by Nan Ni on 2020-08-13.
//

#include "List_Node.h"

//default constructor
List_Node::List_Node(){
    next = nullptr;
    val = 0;
}

//second constructor
List_Node::List_Node(int value){
    next = nullptr;
    val = value;
}

//copy constructor only copies the value
List_Node::List_Node(const List_Node &Node){
    next = nullptr;
    val = Node.val;
}

//free memory
List_Node::~List_Node(){
}

