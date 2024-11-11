#include <iostream>
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

void insertionAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertionAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertionAtPosition(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);

    if (pos == 0)
    {
        insertionAtHead(head, val);
        return;
    }
    int curr_pos = 0;
    Node *temp = head;
    while (curr_pos != pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void updateAtPosition(Node *head, int k, int val)
{
    Node *temp = head;
    int curr_pos = 0;
    while (curr_pos != k)
    {
        temp = temp->next;
        curr_pos++;
    }
    temp->val = val;
}

void deletionAtHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletionAtEnd(Node *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL) // If there's only one node
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

void deletionAtPostion(Node *&head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 0)
    {
        deletionAtHead(head);
        return;
    }
    int curr_pos = 0;
    Node *prev = head;
    while (curr_pos != pos - 1)
    {
        prev = prev->next;
        curr_pos++;
    }
    Node *todelete = prev->next;
    prev->next = prev->next->next;
    delete todelete;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Node *head = new Node(1);
    // cout << head->val << " " << head->next << endl;

    Node *head = NULL;
    insertionAtHead(head, 2);
    displayList(head);
    insertionAtHead(head, 1);
    displayList(head);

    insertionAtEnd(head, 3);
    displayList(head);

    insertionAtPosition(head, 2, 4);
    displayList(head);

    updateAtPosition(head, 3, 5);
    displayList(head);

    // Deletion
    deletionAtHead(head);
    displayList(head);

    deletionAtEnd(head);
    displayList(head);

    insertionAtHead(head, 1);
    displayList(head);

    insertionAtEnd(head, 3);
    displayList(head);

    deletionAtPostion(head, 1);
    displayList(head);
    return 0;
}