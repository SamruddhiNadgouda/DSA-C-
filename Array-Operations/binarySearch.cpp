#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(vector<int> nums, int target)
{
    int st = 0, end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int> nums, int target, int st, int end)
{
    st = 0;
    end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            return binarySearchRecursive(nums, target, st, mid - 1);
        }
        else
        {
            return binarySearchRecursive(nums, target, mid + 1, end);
        }
    }
    return -1;
}

int peakIndexInMountainArray(vector<int> A)
{
    int st = 1, end = A.size() - 2;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
        {
            return mid;
        }
        else if (A[mid - 1] < A[mid])
        { // right
            st = mid + 1;
        }
        else
        { // left
            end = mid - 1;
        }
    }
    return -1;
}

int singleElementInSortedArray(vector<int> A)
{
    int n = A.size();
    int st = 0, end = n - 1;
    if (n == 1)
        return A[0];

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid == 0 && A[0] != A[1])
            return A[mid];
        if (mid == n - 1 && A[n - 1] != A[n - 2])
            return A[mid];
        if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1])
        {
            return A[mid];
        }
        else if (mid % 2 == 0)
        {
            if (A[mid - 1] == A[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        {
            if (A[mid - 1] == A[mid])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

bool isValid(vector<int> &arr, int n, int m, int maxAllowed) // O(n)
{
    int stu = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowed)
        {
            return false;
        }
        if (pages + arr[i] <= maxAllowed)
        {
            pages += arr[i];
        }
        else
        {
            stu++;
            pages = arr[i];
        }
    }
    return (stu > m) ? false : true;
}
int bookAllocationProblem(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        sum += arr[i];
    }

    int st = 0, end = sum, ans = -1;
    while (st <= end) //(log N * n)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    // cout << "Target present at index " << binarySearchIterative(nums, 9) << endl;
    // cout << "Target present at index " << binarySearchRecursive(nums, 4, 0, nums.size());

    // vector<int> A = {0, 3, 8, 9, 5, 2};
    // cout << "Peak index in mountain array is " << peakIndexInMountainArray(A);

    // vector<int> A = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    // vector<int> B = {3, 3, 7, 7, 10, 11, 11};
    // cout << "Single element in a sorted array is " << singleElementInSortedArray(B) << endl;

    // vector<int> arr = {2, 1, 3, 4};
    // int n = 4, m = 2;
    vector<int> arr = {15, 17, 20};
    int n = 3, m = 2;
    cout << "Minimum possible number is " << bookAllocationProblem(arr, n, m) << endl;
    return 0;
}