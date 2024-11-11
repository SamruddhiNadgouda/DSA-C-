#include <iostream>  /* pre-processor directory */
using namespace std; /* file contain cout, cin, etc */

bool isPrime(int n)
{
    int i = 2;
    while (i < n)
    {
        if (n % i == 0)
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return true;
}

void AllPrimeNos(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

int fibonacci(int n)
{
    // Iterative approach
    //  int n1 = 0, n2 = 1, n3;
    //  for (int i = 2; i <= n; i++)
    //  {
    //      n3 = n1 + n2;
    //      n1 = n2;
    //      n2 = n3;
    //  }
    //  return n2;

    // Recursive approach
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int decimalToBinary(int decNum)
{
    int ans = 0;
    int pow = 1;
    while (decNum > 0)
    {
        int rem = decNum % 2;
        decNum = decNum / 2;
        ans += rem * pow;
        pow = pow * 10;
    }
    return ans;
}
int reverseN(int n)
{
    int rev = 0;
    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}
int main()
{
    // AllPrimeNos(20);

    // cout << fibonacci(5);

    // cout << "Binary number is " << decimalToBinary(5) << endl;

    // cout << "reverse number: " << reverseN(156);

    // int age;
    // cout << "Enter age: ";
    // cin >> age;
    // cout << "Hello Samruddhi Nadgouda! Your age is " << age << endl;

    // Unary Operator
    // int a = 10;

    // int b = a++; // => b = 10, a = 11
    // int b = ++a; // => b = 11, a = 11
    // cout << "b = " << b << endl;
    // cout << "a = " << a << endl;

    return 0;
}
