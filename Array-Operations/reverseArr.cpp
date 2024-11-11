#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArr(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        // int temp = arr[end];
        // arr[end] = arr[start];
        // arr[start] = temp;
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printArr(arr, size);
}

int main()
{
    int arr[] = {5, 6, 8, 2, 1};
    reverseArr(arr, 5);
    return 0;
}