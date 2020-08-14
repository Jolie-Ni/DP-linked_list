#include <iostream>
#include "Linked_List.h"


int main() {
    vector<string> my_list{"one","two","three","five","six"};
    //vector<int> my_list;
    Linked_List<string> A = Linked_List<string>(my_list);
    //add 2 following 1
    A.Add_Node("two","one");
    A.Delete_Node("two");
    A.Delete_Node("six");
    A.Print_List();
    Linked_List<string> B = Linked_List<string>(A);
    B.Print_List();
    return 0;
}
