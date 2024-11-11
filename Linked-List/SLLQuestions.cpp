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

void insertionAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
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

void deleteAlternateNodes(Node *&head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        Node *todelete = curr->next;
        curr->next = curr->next->next;
        delete todelete;
        curr = curr->next;
    }
}

void deleteDuplicateNodes(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        while (curr->next != NULL && curr->val == curr->next->val)
        {
            Node *todelete = curr->next;
            curr->next = curr->next->next;
            delete todelete;
        }
        curr = curr->next;
    }
}
void reverse(Node *&head)
{
    if (head == NULL)
        return;

    reverse(head->next);
    cout << head->val << " ";
}

Node *reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Node *newHead = prev;
    return newHead;
}

Node *reverseLLRecursive(Node *&head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

Node *reversekLL(Node *head, int k)
{
    Node *prev = NULL;
    Node *curr = head;

    int counter = 0; // for counting first k nodes

    while (curr != NULL && counter < k)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }

    // curr will give us (k+1)th node
    if (curr != NULL)
    {
        Node *newHead = reversekLL(curr, k);
        head->next = newHead;
    }
    return prev;
}
int main()
{
    // Node *head = new Node(1);
    // cout << head->val << " " << head->next << endl;

    Node *head = NULL;
    insertionAtEnd(head, 1);
    insertionAtEnd(head, 2);
    insertionAtEnd(head, 3);
    insertionAtEnd(head, 4);
    insertionAtEnd(head, 5);
    insertionAtEnd(head, 6);
    displayList(head);

    // deleteAlternateNodes(head);
    // displayList(head);

    // deleteDuplicateNodes(head);
    // displayList(head);

    // reverse(head);

    // head = reverseList(head);
    // displayList(head);

    head = reversekLL(head, 2);
    displayList(head);
    return 0;
}