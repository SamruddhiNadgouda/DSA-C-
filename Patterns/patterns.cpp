#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the numbers N: ";
    cin >> n;

    // Square pattern
    /*
    A B C D E
    A B C D E
    A B C D E
    A B C D E
    A B C D E */
    // for (int i = 1; i <= n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << ch << " ";
    //         ch += 1;
    //     }
    //     cout << endl;
    // }

    /*
    1 2 3
    4 5 6
    7 8 9 */
    // int num = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    /*
    A B C
    D E F
    G H I */
    // char ch = 'A';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ch << " ";
    //         ch += 1;
    //     }
    //     cout << endl;
    // }

    /*
    1
    2 2
    3 3 3
    4 4 4 4 */
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << i + 1 << " ";
    //     }
    //     cout << endl;
    // }

    /*
    A
    B B
    C C C
    D D D D */
    // char ch = 'A';
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << ch << " ";
    //     }
    //     ch += 1;
    //     cout << endl;
    // }

    /*
    1
    1 2
    1 2 3
    1 2 3 4 */
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << j + 1 << " ";
    //     }
    //     cout << endl;
    // }

    // Reverse Triangle pattern
    /*
    1
    2 1
    3 2 1
    4 3 2 1 */
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j > 0; j--)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // Floyd's triangle pattern
    /*
    1
    2 3
    4 5 6
    7 8 9 10 */
    // int num = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    // Inverted Triangle pattern
    /*
    1 1 1 1
      2 2 2
        3 3
          4 */
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         cout << (i + 1);
    //     }
    //     cout << endl;
    // }

    // Pyramid pattern
    /*    1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1 */
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= i + 1; j++)
    //     {
    //         cout << j;
    //     }
    //     for (int j = i; j >= 1; j--)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // Hollow diamond pattern
    /*
     *
     *   *
     *       *
     *           *
     *       *
     *   *
     *
     */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "* ";
        if (i != 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << "* ";
        if (i != n - 2)
        {
            for (int j = 0; j < 2 * (n - 2 - i) - 1; j++)
            {
                cout << " ";
            }
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}