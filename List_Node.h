//
// Created by Nan Ni on 2020-08-13.
//

#ifndef DP_LINKED_LIST_LIST_NODE_H
#define DP_LINKED_LIST_LIST_NODE_H


class List_Node {

private:
    List_Node* next;
    int val;
public:
    //could make this private later on


    //default constructor
    List_Node();

    //second constructor
    List_Node(int value);

    //copy constructor
    List_Node(const List_Node &Node);

    //get val
    int Get_val();

    //get next
    List_Node* Get_next();

    //set val
    void Set_val(int value);

    //set next
    void Set_next(List_Node* n);

    //free memory
    ~List_Node();



};


#endif //DP_LINKED_LIST_LIST_NODE_H
