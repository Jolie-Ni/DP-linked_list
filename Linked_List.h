//
// Created by Nan Ni on 2020-08-13.
// The link list created so far only contains unique int

#ifndef DP_LINKED_LIST_LINKED_LIST_H
#define DP_LINKED_LIST_LINKED_LIST_H

#include <vector>
#include "List_Node.h"
using namespace std;

class Linked_List {

private:

    List_Node* head_ptr;

public:

    //default constructor
    Linked_List();

    //second constructor
    Linked_List(vector<int> list);

    //copy constructor
    Linked_List(List_Node* ptr);

    //get head
    List_Node* Get_head();

    //set head
    void Set_head(List_Node* head);


    //insert function, future can check uniqueness
    void Add_Node(int value,int tar);

    //delete function,head could be deleted,update head if needed
    void Delete_Node(int value);

    //find ptr position with value
    List_Node* Find_Node(int value);

    List_Node* Find_prev(List_Node* ptr);

    //delete all elements in the list
    void Clear_All();

    void Print_List();


};


#endif //DP_LINKED_LIST_LINKED_LIST_H
