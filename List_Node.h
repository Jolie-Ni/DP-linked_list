//
// Created by Nan Ni on 2020-08-13.
//

#ifndef DP_LINKED_LIST_LIST_NODE_H
#define DP_LINKED_LIST_LIST_NODE_H

template<class T>
class List_Node {

private:
    List_Node<T>* next;
    T val;
public:
    //could make this private later on


    //default constructor
    List_Node();

    //second constructor
    List_Node(T value);

    //copy constructor
    List_Node(const List_Node &Node);

    //get val
    T Get_val();

    //get next
    List_Node<T>* Get_next();

    //set val
    void Set_val(T value);

    //set next
    void Set_next(List_Node<T>* n);

    //free memory
    ~List_Node();



};

template<class T>
//default constructor
List_Node<T>::List_Node(){
    next = nullptr;
    val = 0;
}

template<class T>
//second constructor
List_Node<T>::List_Node(T value){
    next = nullptr;
    val = value;
}

template<class T>
//copy constructor only copies the value
List_Node<T>::List_Node(const List_Node &Node){
    next = nullptr;
    val = Node.val;
}

template<class T>
T List_Node<T>::Get_val(){
    return val;
}

template<class T>
//get next
List_Node<T>* List_Node<T>::Get_next() {
    return next;
}

//set val
template<class T>
void List_Node<T>::Set_val(T value){
    val = value;
}

template<class T>
//set next
void List_Node<T>::Set_next(List_Node<T>* n){
    next = n;
}

//free memory
template<class T>
List_Node<T>::~List_Node(){
}



#endif //DP_LINKED_LIST_LIST_NODE_H
