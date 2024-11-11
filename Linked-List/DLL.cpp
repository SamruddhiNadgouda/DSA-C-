#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        prev = next = NULL;
    }
};

class DLL
{
public:
    Node *head;
    Node *tail;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void displayLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insertionAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertionAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }

    void insertionAtPosition(int val, int k)
    {
        Node *temp = head;
        int count = 0;
        while (count < (k - 1))
        {
            temp = temp->next;
            count++;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }

    void deletionAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *todelete = head;
        head = head->next;
        if (head == NULL) // if dll had only one node
        {
            tail = NULL;
        }
        head->prev = NULL;
        delete todelete;
        return;
    }

    void deletionAtTail()
    {
        if (tail == NULL)
        {
            return;
        }
        Node *todelete = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        tail->next = NULL;
        delete todelete;
        return;
    }
    void deletionAtPosition(int k)
    {
        Node *temp = head;
        int count = 0;
        while (count != k)
        {
            temp = temp->next;
            count++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return;
    }
};

void reverseDLL(Node *&head, Node *&tail)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }

    // Swapping between head and tail
    Node *newHead = tail;
    tail = head;
    head = newHead;
}

bool isPalindrome(Node *&head, Node *&tail)
{
    while (head != tail && tail != head->prev)
    {
        if (head->val != tail->val)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main()
{
    // Node *newNode = new Node(1);
    DLL dll;
    // dll.head = newNode;
    // dll.tail = newNode;
    // cout << dll.head->val << endl;

    dll.insertionAtHead(3);
    dll.insertionAtHead(2);
    dll.insertionAtHead(1);
    dll.displayLL();

    dll.insertionAtTail(4);
    dll.insertionAtTail(5);
    dll.displayLL();

    dll.insertionAtPosition(6, 2);
    dll.displayLL();

    // Deletion
    dll.deletionAtHead();
    dll.displayLL();

    dll.deletionAtTail();
    dll.displayLL();

    dll.deletionAtPosition(2);
    dll.displayLL();

    reverseDLL(dll.head, dll.tail);
    dll.displayLL();

    bool result = isPalindrome(dll.head, dll.tail);
    cout << "result of isPalindrome: " << result << endl;

    return 0;
}