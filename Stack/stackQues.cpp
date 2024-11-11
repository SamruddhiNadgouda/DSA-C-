#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string str)
{
    stack<string> s;

    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (str[i] != ' ' && i < str.length())
        {
            word += str[i];
            i++;
        }
        s.push(word);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertAtBottom(s, val);

    s.push(topEle);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int val = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, val);
}

int main()
{
    // string str = "Hey, how are you doing?";
    // reverseSentence(str);

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}