#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> vec = {1, 2, 3};
    // cout << vec[0] << endl;
    // cout << vec[1] << endl;
    // cout << vec[2] << endl;

    // cout << "Size of vector: " << vec.size() << endl;
    // vec.push_back(4);
    // vec.push_back(5);
    // cout << "After push, Size of vector: " << vec.size() << endl;

    // cout << "Front element: " << vec.front() << endl;
    // cout << "Back element: " << vec.back() << endl;

    // vec.pop_back();
    // cout << "After pop, Size of vector: " << vec.size() << endl;

    // cout << "element at index 2 is " << vec.at(2) << endl;

    vector<int> vec;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << "Size of this vector is " << vec.size() << endl;
    cout << "Capacity of this vector is " << vec.capacity() << endl;
    return 0;
}