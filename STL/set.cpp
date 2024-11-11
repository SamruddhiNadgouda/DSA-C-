#include <iostream>
#include <set>
using namespace std;

int main()
{
    // set<int> s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
    // s.insert(5);
    // s.insert(5);

    // cout << s.size() << endl;
    // for (auto val : s)
    // {
    //     cout << val << " "; //1 2 3 4 5
    // }
    // cout << endl;

    // cout << "Lower bound = " << *(s.lower_bound(3)) << endl;
    // cout << "Upper bound = " << *(s.upper_bound(3)) << endl;

    multiset<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(5);

    for (auto val : s)
    {
        cout << val << " "; // 1 2 3 3 4 5 5 5
    }
    cout << endl;

    return 0;
}