#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Left tree of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Right tree of " << data << " : " << endl;
    root->right = buildTree(root->right);
}

void levelOrderTranversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorderTranversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTranversal(root->left);
    cout << root->data << " ";
    inorderTranversal(root->right);
}

void preorderTranversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTranversal(root->left);
    preorderTranversal(root->right);
}

void postorderTranversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTranversal(root->left);
    postorderTranversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;

    root = buildTree(root);
    cout << "Level order tranversal: " << endl;
    levelOrderTranversal(root);
    cout << "\nInorder tranversal: " << endl;
    inorderTranversal(root);
    cout << "\nPreorder tranversal: " << endl;
    preorderTranversal(root);
    cout << "\nPostorder tranversal: " << endl;
    postorderTranversal(root);
    return 0;
}

/*
Enter the data: 1
Left tree of 1:
Enter the data: 2
Left tree of 2:
Enter the data: 4
Left tree of 4:
Enter the data: -1
Right tree of 4 :
Enter the data: -1
Right tree of 2 :
Enter the data: 5
Left tree of 5:
Enter the data: -1
Right tree of 5 :
Enter the data: -1
Right tree of 1 :
Enter the data: 3
Left tree of 3:
Enter the data: -1
Right tree of 3 :
Enter the data: 6
Left tree of 6:
Enter the data: -1
Right tree of 6 :
Enter the data: -1
Level order tranversal:
1
2 3
4 5 6

Inorder tranversal:
4 2 5 1 3 6
Preorder tranversal:
1 2 4 5 3 6
Postorder tranversal:
4 5 2 6 3 1
*/
