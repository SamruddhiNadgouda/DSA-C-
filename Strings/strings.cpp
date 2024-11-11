#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // char str[] = "Samruddhi Nadgouda";

    // int len = 0;
    // for (int i = 0; i < str[i] != '\0'; i++)
    // {
    //     len++;
    // }
    // cout << "Length of str: " << len << endl;

    // cout << "Enter char array: ";
    // cin >> str;
    // Enter char array : hello world
    // Output : hello

    // cin.getline(str, 19);
    // Enter char array: hello world
    // Output: hello world
    // cout << "Output: " << str << endl;

    // for (char ch : str)
    // {
    //     cout << ch << " ";
    // }

    string str = "sanjanas";
    if (isPalindrome(str))
    {
        cout << "String is palindrome" << endl;
    }
    else
    {
        cout << "String is not palindrome" << endl;
    }
    return 0;
}