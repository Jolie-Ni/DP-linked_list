#include <iostream>
#include "Linked_List.h"


int main() {
    vector<int> my_list{1,3,4,5,6};
    //vector<int> my_list;
    Linked_List A = Linked_List(my_list);
    //add 2 following 1
    A.Add_Node(2,1);
    A.Delete_Node(2);
    A.Delete_Node(6);
    A.Print_List();
    Linked_List B = Linked_List(A);
    B.Print_List();
    return 0;
}
