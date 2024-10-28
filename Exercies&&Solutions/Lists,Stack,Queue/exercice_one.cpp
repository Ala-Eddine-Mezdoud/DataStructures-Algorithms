

/*
Exercice:

Let’s suppose you are given a list L, and another list P containing integers sorted in ascending order.
The procedure printLots(L,P) prints the elements in L that are in the positions specified by P.
For example, if P = {1, 3, 4, 6} the elements in positions 1, 3, 4, and 6 in L are printed.

Task:
Write the procedure printLots(L,P). You may only use the public STL list operations.

*/

// Solutions:

#include <iostream>
#include <list>

using namespace std;

template <typename Object>
void printLots(const list<Object> &L, const list<int> &P)
{
    auto L_iterator = L.begin();
    int current_position = 1;

    for (auto P_iterator = P.begin(); P_iterator != P.end(); ++P_iterator)
    {
        int target_position = *P_iterator;
        while (current_position < target_position && L_iterator != L.end())
        {
            ++current_position;
            ++L_iterator;
        }
        if (L_iterator != L.end())
        {
            cout << *L_iterator << endl;
        }
    }
}

int main()
{
    list<string> L = {"Ahmed", "Yassir", "Ala", "Ayoub", "Ossama", "Abd Allah"};
    list<int> P = {1, 3, 4, 6};

    printLots(L, P);

    return 0;
}
