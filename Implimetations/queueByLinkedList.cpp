#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;   // Data of the node
    Node *next; // Pointer to the next node
};

// Queue class using linked list
class Queue
{
private:
    Node *front; // Pointer to the front of the queue
    Node *rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to free memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Enqueue (Add an element to the queue)
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // If the queue is empty, both front and rear point to the new node
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode; // Link the new node to the rear
            rear = newNode;       // Update the rear pointer
        }

        cout << value << " enqueued to the queue." << endl;
    }

    // Dequeue (Remove and return the front element from the queue)
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1; // Indicate error
        }

        Node *temp = front;     // Temporary pointer to the front node
        int value = temp->data; // Store the value to return
        front = front->next;    // Update the front pointer

        // If the queue becomes empty after dequeue, set rear to nullptr
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp; // Free memory
        return value;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue queue;

    // Demonstration of queue operations
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Dequeuing element: " << queue.dequeue() << endl;
    cout << "Dequeuing element: " << queue.dequeue() << endl;

    queue.enqueue(40);

    if (queue.isEmpty())
    {
        cout << "Queue is empty now!" << endl;
    }

    return 0;
}
