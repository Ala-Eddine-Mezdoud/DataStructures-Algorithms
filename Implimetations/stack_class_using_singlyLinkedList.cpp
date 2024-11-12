#include <iostream>
using namespace std;

// Declaring node for linked list
template <typename Object>
struct node
{
    Object data;
    node *next;
    node(Object dt) : data(dt) {};
};

template <typename Object>
class Stack
{
public:
    Stack()
    {
        top = nullptr;
        theSize = 0;
    }

    void push(const Object &ob)
    {
        node<Object> *temp = new node<Object>(ob);
        temp->next = top;
        top = temp; // incrementing the top to the last element in the list
        theSize++;
    }

    Object pop()
    {
        node<Object> *temp = top;
        top = temp->next; // desincrementing the top to the element before the last one and losing pointer to the last element
        --theSize;
        Object data = temp->data;
        delete temp; // deleting the last element from the memory
        return data;
    }

    void print()
    {
        node<Object> *temptop = top;
        int i = 0;
        while (i < theSize)
        {
            cout << temptop->data << endl;
            temptop = temptop->next; // update the top each time with the next element
            i++;
        }
    }

    int size()
    {
        return theSize;
    }

private:
    node<Object> *top;
    int theSize;
};

int main()
{
    Stack<int> test;
    test.push(5);
    test.push(6);
    test.push(7);
    test.push(8);
    test.print();
    return 0;
}