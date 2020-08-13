//
// Created by Nan Ni on 2020-08-13.
//

#ifndef DP_LINKED_LIST_LIST_NODE_H
#define DP_LINKED_LIST_LIST_NODE_H


class List_Node {

public:
    //could make this private later on
    List_Node* next;
    int val;

    //default constructor
    List_Node();

    //second constructor
    List_Node(int value);

    //copy constructor
    List_Node(const List_Node &Node);

    //free memory
    ~List_Node();



};


#endif //DP_LINKED_LIST_LIST_NODE_H
