//
// Created by Nan Ni on 2020-08-13.
//

#include "Linked_List.h"
#include <iostream>

//default constructor
Linked_List::Linked_List(){
    head_ptr = nullptr;
}

//second constructor
Linked_List::Linked_List(vector<int> list){
    head_ptr = nullptr;
    List_Node* tra_ptr = nullptr;
    for(vector<int>::iterator itr = list.begin(); itr != list.end(); itr++){

        List_Node* new_node = new List_Node(*itr);
        if(head_ptr == nullptr){
            head_ptr = new_node;
            tra_ptr = head_ptr;
        }
        else{
            tra_ptr->Set_next(new_node);
            tra_ptr = tra_ptr->Get_next();
        }
    }


}

//copy constructor
Linked_List::Linked_List(List_Node* ptr){
    head_ptr = nullptr;
    List_Node* tra_ptr = nullptr;

    while(ptr != nullptr){
        List_Node* new_node = new List_Node(ptr->Get_val());
        if(head_ptr == nullptr){
            head_ptr = new_node;
            tra_ptr = head_ptr;
        }
        else{
            tra_ptr->Set_next(new_node);
            tra_ptr = tra_ptr->Get_next();
        }
        ptr = ptr->Get_next();
    }
}

//get head
List_Node* Linked_List::Get_head(){
    return head_ptr;
}

//set head
void Linked_List::Set_head(List_Node* head){
    head_ptr = head;
}

//insert function, future can check uniqueness
//list is empty
void Linked_List::Add_Node(int value,int tar){
    List_Node* ptr = Find_Node(tar);
    if(head_ptr == nullptr){
        //empty list
        head_ptr = new List_Node(value);
    }
    else{
        List_Node* new_node = new List_Node(value);
        if(ptr == nullptr){
            //insert at head when no previous found
            new_node->Set_next(head_ptr);
            head_ptr = new_node;
        }
        else {
            new_node->Set_next(ptr->Get_next());
            ptr->Set_next(new_node);
        }
    }
}

//if not found return nullptr
List_Node* Linked_List::Find_Node(int value){
    List_Node* ptr = head_ptr;
    while(ptr != nullptr){
        if(ptr->Get_val() != value){
            ptr = ptr->Get_next();
        }
        else{
            break;
        }
    }
    return ptr;
}


List_Node* Linked_List::Find_prev(List_Node* ptr){
    List_Node* prev = nullptr;
    List_Node* tra_ptr = head_ptr;
    while(tra_ptr != nullptr){
        if(tra_ptr->Get_next() == ptr){
            prev = tra_ptr;
            break;
        }
        else{
            tra_ptr = tra_ptr->Get_next();
        }
    }
    return prev;
}

//delete function,head could be deleted,update head if needed
void Linked_List::Delete_Node(int value){

    //find ptr to be deleted
    List_Node* ptr = Find_Node(value);

    //if found then delete
    if(ptr != nullptr){
        //if head to be deleted
        if(ptr == head_ptr){
            head_ptr = head_ptr->Get_next();
            delete ptr;
        }
        else{
            List_Node* prev = Find_prev(ptr);
            prev->Set_next(ptr->Get_next());
            ptr->Set_next(nullptr);
            delete ptr;
        }
    }
}

void Linked_List::Clear_All(){

    while(head_ptr != nullptr){
        List_Node* to_be_delete = head_ptr;
        head_ptr = head_ptr->Get_next();
        to_be_delete->Set_next(nullptr);
        delete to_be_delete;
    }
}


void Linked_List::Print_List(){

    List_Node* ptr = head_ptr;
    if(ptr == nullptr){
        cout << "linked list is empty" << endl;
    }
    else{
        while(ptr != nullptr){
            cout << ptr->Get_val() << endl;
            ptr = ptr->Get_next();
        }
    }
}
