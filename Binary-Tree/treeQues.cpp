#include <iostream>
#include <queue>
#include <climits>
#include <vector>
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
    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);
    cout << "Left tree of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Right tree of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

void inOrder(Node *root, int &count)
{ // Pass count by reference
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inOrder(root->right, count);
}

int countLeafNodes(Node *root)
{
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    int ht = max(lh, rh) + 1;
    return ht;
}

int diameterOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = diameterOfTree(root->left);
    int opt2 = diameterOfTree(root->right);
    int opt3 = heightOfTree(root->left) + heightOfTree(root->right) + 1;

    int ans = max(opt1, max(opt2, opt3));
    return ans;
}
// pair<int, int> InfoTree(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<int, int> p = make_pair(0, 0);
//         return p;
//     }

//     pair<int, int> left = InfoTree(root->left);
//     pair<int, int> right = InfoTree(root->right);

//     int op1 = left.first;
//     int op2 = right.first;
//     int op3 = left.second + right.second + 1;
//     pair<int, int> ans;
//     ans.first = max(op1, max(op2, op3));
//     ans.second = max(left.second, right.second) + 1;

//     return ans;
// }
// int diameterOfTree2(Node *root)
// {
//     return InfoTree(root).first;
// }

bool isBalancedTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalancedTree(root->left);
    bool right = isBalancedTree(root->right);

    bool diff = (heightOfTree(root->left) - heightOfTree(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// pair<bool, int> InfoTree(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }

//     pair<bool, int> left = InfoTree(root->left);
//     pair<bool, int> right = InfoTree(root->right);

//     int bleft = left.first;
//     int bright = right.first;

//     int diff = (left.second - right.second) <= 1;

//     pair<bool, int> ans;
//     ans.first = (bleft && bright && diff) ? true : false;
//     ans.second = max(left.second, right.second) + 1;

//     return ans;
// }
// bool isBalancedTree2(Node *root)
// {
//     return InfoTree(root).first;
// }

// bool isIdentical(Node *root1, Node *root2)
// {
//     // base cases
//     if (root1 == NULL && root2 == NULL)
//     {
//         return true;
//     }
//     if (root1 == NULL && root2 != NULL)
//     {
//         return false;
//     }
//     if (root1 != NULL && root2 == NULL)
//     {
//         return false;
//     }

//     bool left = isIdentical(root1->left, root2->left);
//     bool right = isIdentical(root1->right, root2->right);

//     bool value = root1->data == root2->data;

//     if (left && right && value)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
pair<bool, int> InfoTree(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = InfoTree(root->left);
    pair<bool, int> right = InfoTree(root->right);

    bool leftsum = left.first;
    bool rightsum = right.first;

    bool condition = root->data == (left.second + right.second);

    pair<bool, int> ans;
    ans.first = (leftsum, rightsum, condition) ? true : false;
    ans.second = left.second + right.second + root->data;

    return ans;
}
int isSumtree(Node *root)
{
    return InfoTree(root).first;
}
int main()
{
    // Node *root = NULL;
    // root = buildTree(root);
    // cout << "Count of leaf nodes: " << countLeafNodes(root) << endl;
    // cout << "Height of tree: " << heightOfTree(root) << endl;
    // cout << "Diameter of tree: " << diameterOfTree(root) << endl;
    // cout << "Diameter of tree(optimal solution): " << diameterOfTree2(root) << endl;
    // cout << "Is this tree balanced or not: " << isBalancedTree(root) << endl;
    // cout << "Is this tree balanced or not(Optimal solution): " << isBalancedTree(root) << endl;

    cout << "Tree 1: " << endl;
    Node *root1 = NULL;
    root1 = buildTree(root1);

    // cout << "Tree 2: " << endl;
    // Node *root2 = NULL;
    // root2 = buildTree(root2);

    // cout << "Is these two tree are identical or not: " << isIdentical(root1, root2) << endl;

    cout << "Is this sum tree: " << isSumtree(root1) << endl;
    return 0;
}
