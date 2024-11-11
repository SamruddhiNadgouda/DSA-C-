#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 6, 8, 2, 1};

    cout << "Target at index " << linearSearch(arr, 5, 8) << endl;
    return 0;
}