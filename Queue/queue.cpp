#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head;

public:
    Queue()
    {
        head = NULL;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            cout << newNode->val << " ";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << newNode->val << " ";
    }
    int dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        int val = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return INT_MIN;
        }
        return head->val;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << endl;

    cout << "Front element is " << q.front() << endl;

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
    return 0;
}