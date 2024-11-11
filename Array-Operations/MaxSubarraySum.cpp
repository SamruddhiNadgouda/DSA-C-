#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 7;
    int arr[] = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = INT_MIN;
    // int currSum = 0;

    // Brute force
    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    // Kadane's Algorithm
    // for (int i = 0; i < n; i++)
    // {
    //     currSum += arr[i];
    //     maxSum = max(currSum, maxSum);
    //     if (currSum < 0)
    //     {
    //         currSum = 0;
    //     }
    // }

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}