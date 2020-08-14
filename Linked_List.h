//
// Created by Nan Ni on 2020-08-13.
// The link list created so far only contains unique int

#ifndef DP_LINKED_LIST_LINKED_LIST_H
#define DP_LINKED_LIST_LINKED_LIST_H

#include <vector>
#include "List_Node.h"
using namespace std;

template<class T>
class Linked_List {

private:

    List_Node<T>* head_ptr;

public:

    //default constructor
    Linked_List();

    //second constructor
    Linked_List(vector<T> list);

    //copy constructor
    Linked_List(List_Node<T>* ptr);

    //get head
    List_Node<T>* Get_head();

    //set head
    void Set_head(List_Node<T>* head);


    //insert function, future can check uniqueness
    void Add_Node(T value,T tar);

    //delete function,head could be deleted,update head if needed
    void Delete_Node(T value);

    //find ptr position with value
    List_Node<T>* Find_Node(T value);

    List_Node<T>* Find_prev(List_Node<T>* ptr);

    //delete all elements in the list
    void Clear_All();

    void Print_List();


};

template<class T>
//default constructor
Linked_List<T>::Linked_List(){
    head_ptr = nullptr;
}

template<class T>
//second constructor
Linked_List<T>::Linked_List(vector<T> list){
    head_ptr = nullptr;
    List_Node<T>* tra_ptr = nullptr;
    for(typename vector<T>::iterator itr = list.begin(); itr != list.end(); itr++){

        List_Node<T>* new_node = new List_Node<T>(*itr);
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

template<class T>
//copy constructor
Linked_List<T>::Linked_List(List_Node<T>* ptr){
    head_ptr = nullptr;
    List_Node<T>* tra_ptr = nullptr;

    while(ptr != nullptr){
        List_Node<T>* new_node = new List_Node<T>(ptr->Get_val());
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

template<class T>
//get head
List_Node<T>* Linked_List<T>::Get_head(){
    return head_ptr;
}

template<class T>
//set head
void Linked_List<T>::Set_head(List_Node<T>* head){
    head_ptr = head;
}

template<class T>
//insert function, future can check uniqueness
//list is empty
void Linked_List<T>::Add_Node(T value,T tar){
    List_Node<T>* ptr = Find_Node(tar);
    if(head_ptr == nullptr){
        //empty list
        head_ptr = new List_Node<T>(value);
    }
    else{
        List_Node<T>* new_node = new List_Node<T>(value);
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

template<class T>
//if not found return nullptr
List_Node<T>* Linked_List<T>::Find_Node(T value){
    List_Node<T>* ptr = head_ptr;
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

template<class T>
List_Node<T>* Linked_List<T>::Find_prev(List_Node<T>* ptr){
    List_Node<T>* prev = nullptr;
    List_Node<T>* tra_ptr = head_ptr;
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

template<class T>
//delete function,head could be deleted,update head if needed
void Linked_List<T>::Delete_Node(T value){

    //find ptr to be deleted
    List_Node<T>* ptr = Find_Node(value);

    //if found then delete
    if(ptr != nullptr){
        //if head to be deleted
        if(ptr == head_ptr){
            head_ptr = head_ptr->Get_next();
            delete ptr;
        }
        else{
            List_Node<T>* prev = Find_prev(ptr);
            prev->Set_next(ptr->Get_next());
            ptr->Set_next(nullptr);
            delete ptr;
        }
    }
}

template<class T>
void Linked_List<T>::Clear_All(){

    while(head_ptr != nullptr){
        List_Node<T>* to_be_delete = head_ptr;
        head_ptr = head_ptr->Get_next();
        to_be_delete->Set_next(nullptr);
        delete to_be_delete;
    }
}

template<class T>
void Linked_List<T>::Print_List(){

    List_Node<T>* ptr = head_ptr;
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



#endif //DP_LINKED_LIST_LINKED_LIST_H
