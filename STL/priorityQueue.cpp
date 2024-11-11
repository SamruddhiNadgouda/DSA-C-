#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    // Max heap
    priority_queue<int> pq;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> rpq;

    pq.push(1);
    pq.push(2);
    pq.push(5);
    pq.push(4);
    pq.push(3);
    int size = pq.size();
    for (auto i = 0; i < size; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    rpq.push(1);
    rpq.push(2);
    rpq.push(5);
    rpq.push(4);
    rpq.push(3);
    int Rsize = rpq.size();
    for (auto i = 0; i < size; i++)
    {
        cout << rpq.top() << " ";
        rpq.pop();
    }

    cout << "\nEmpty? " << rpq.empty();
    return 0;
}