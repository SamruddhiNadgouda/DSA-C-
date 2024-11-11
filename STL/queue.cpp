#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<string> q;
    q.push("abc");
    q.push("xyz");
    q.push("pqr");
    q.push("uvw");

    cout << "First element: " << q.front() << endl;
    cout << "size: " << q.size() << endl;

    q.pop();

    cout << "First element: " << q.front() << endl;
    cout << "size: " << q.size();
    return 0;
}