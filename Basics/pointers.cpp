#include <iostream>
using namespace std;

int changeA(int *ptr) // pass by reference using pointers
{
    *ptr = 20;
}

int changesA(int &b) // pass by reference using alias
{
    b = 20;
}
int main()
{
    // int a = 10;
    // int *ptr = &a;
    // Address of 'a'
    // cout << "Address of 'a': " << ptr << endl;
    // cout << "Address of 'a': " << &a << endl;
    // Address of ptr
    // cout << "Address of ptr: " << &ptr << endl;
    // Value of a
    // cout << "Value of a: " << *(&a) << endl;

    // cout << "Pointer to pointer concept" << endl;
    // int **ptr2 = &ptr;
    // cout << ptr2 << endl;   // address of ptr
    // cout << *ptr2 << endl;  // address of a
    // cout << **ptr2 << endl; // value of a

    // int a = 10;
    // changeA(&a);
    // changesA(a);

    // cout << "Inside main function: " << a << endl;

    // Array pointer
    //  int arr[3] = {10, 20, 30};
    //  int *ptr = arr;

    // cout << ptr << endl; //0x61ff00
    // cout << *ptr << endl; //10
    // cout << arr << endl; //0x61ff00

    // int arr[] = {1, 2, 3, 4, 5};

    // cout << *arr << endl;
    // cout << *(arr + 1) << endl;
    // cout << *(arr + 2) << endl;
    // cout << *(arr + 3) << endl;

    // int a = 10;
    // int *ptr = &a;

    // cout << ptr << endl; // 0x61fef4
    // ptr++;
    // cout << ptr << endl; //+4 => 0x61fef8
    // ptr = ptr + 2;
    // cout << ptr << endl; // 0x61ff00
    // cout << endl;

    // int *ptr2;                   // 100
    // int *ptr1 = ptr2 + 2;        // 108
    // cout << ptr1 - ptr2 << endl; // 2 <- no. of bytes

    int *ptr1;
    int *ptr2 = ptr1;

    cout << ptr1 << endl;
    cout << ptr2 << endl;

    cout << (ptr1 != ptr2) << endl;

    return 0;
}