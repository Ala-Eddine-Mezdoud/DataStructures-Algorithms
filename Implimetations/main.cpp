#include <iostream>
#include "singly_linked_list.cpp"
using namespace std;

int main()
{

    singly_linked_list<int> List;

    cout << List.itHas(10) /*False*/ << endl;
    List.add(10);
    List.add(10); // will not add it second time
    List.add(20);
    List.addAtEnd(30);
    cout << List.itHas(10) /*True*/ << endl;
    cout << List.size() /*3*/ << endl;
    List.print();
    List.remove(10);
    cout << "####################" << endl;
    List.print();

    return 0;
}