/*
Let’s assume that a singly linked list is implemented with a header node, but no tail node, and that
it maintains only a pointer to the header node.
1. Write a class that includes methods to:
(a) return the size of the linked list
(b) print the linked list
(c) test if a value x is contained in the linked list
(d) add a value x at the beginning of the list if it is not already contained in the linked list
(e) add a value x at the end of the list if it is not already contained in the linked list
(f) remove the first occurrence of a value x if x is contained in the linked list
*/

#include <iostream>
using namespace std;

template <typename Object>
class node
{
public:
    Object data;
    node *next;

    node(const Object &O = Object(), node *n = nullptr) : data(O), next(n) {};
};

template <typename Object>
class singly_linked_list
{
private:
    node<Object> *head;

public:
    singly_linked_list()
    {
        head = new node<Object>;
    }
    // (a) return the size of the linked list
    int size()
    {
        int size = 0;
        node<Object> *temp = head->next;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    //(b) print the linked list
    void print()
    {
        node<Object> *temp = head->next;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    //(c) test if a value x is contained in the linked list
    bool itHas(const Object &O)
    {
        node<Object> *temp = head->next;
        while (temp != nullptr)
        {
            if (temp->data == O)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //(d) add a value x at the beginning of the list if it is not already contained in the linked list
    bool add(const Object &O)
    {
        if (itHas(O))
        {
            return false;
        };

        node<Object> *newNode = new node<Object>(O);
        newNode->next = head->next;
        head->next = newNode;
        return true;
    }
    //(e) add a value x at the end of the list if it is not already contained in the linked list
    bool addAtEnd(const Object &O)
    {
        if (itHas(O))
        {
            return false;
        }
        node<Object> *newNode = new node<Object>(O);
        node<Object> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return true;
    }

    // (f) remove the first occurrence of a value x if x is contained in the linked list
    bool remove(const Object &O)
    {
        node<Object> *current = head->next;
        node<Object> *previous = head;

        while (current != nullptr)
        {
            if (current->data == O)
            {
                previous->next = current->next;
                delete current;
                return true;
            }
            current = current->next;
            previous = previous->next;
        }
        return false;
    }
};