#include <iostream>
#include <climits>
using namespace std;

// class Stack
// {
// private:
//     int Maxsize;
//     int top;
//     int *arr;

// public:
//     Stack(int size)
//     {
//         this->Maxsize = size;
//         arr = new int[size];
//         top = -1;
//     }
//     void push(int val)
//     {
//         if (top >= Maxsize - 1)
//         {
//             cout << "Overflow stack";
//             return;
//         }
//         top++;
//         arr[top] = val;
//         cout << arr[top] << " ";
//     }
//     int pop()
//     {
//         if (top < 0)
//         {
//             cout << "Underflow stack";
//             return INT_MIN;
//         }
//         return arr[top--];
//     }
//     int peek()
//     {
//         if (top < 0)
//         {
//             cout << "Underflow stack";
//             return INT_MIN;
//         }
//         return arr[top];
//     }
//     int size()
//     {
//         return top + 1;
//     }
//     bool isEmpty()
//     {
//         return (top == -1);
//     }
//     bool isFull()
//     {
//         return (top == Maxsize - 1);
//     }
// };

// int main()
// {
//     Stack s(5);
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     cout << endl;

//     cout << "Top element is " << s.peek() << endl;
//     int n = s.size();

//     for (int i = 0; i < n; i++)
//     {
//         cout << s.pop() << " ";
//     }
//     cout << endl;
//     s.pop();

//     return 0;
// }

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
class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " ";
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        int val = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
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
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << endl;
    cout << "Top element is " << s.top() << endl;

    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}