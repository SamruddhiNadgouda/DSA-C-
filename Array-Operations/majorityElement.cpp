#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElement(vector<int> nums)
{
    // sort
    // sort(nums.begin(), nums.end());
    // Brute force
    //  for (int val : nums)
    //  {
    //      int freq = 0;
    //      for (int ele : nums)
    //      {
    //          if (ele == val)
    //          {
    //              freq++;
    //          }
    //      }
    //      if (freq > nums.size() / 2)
    //      {
    //          return val;
    //      }
    //  }
    //  return -1;

    // Optimize one
    // int freq = 1, ans = nums[0];
    // for (int i = 1; i < nums.size(); i++)
    // {
    //     if (nums[i] == nums[i - 1])
    //     {
    //         freq++;
    //     }
    //     else
    //     {
    //         freq = 1;
    //         ans = nums[i];
    //     }
    //     if (freq > nums.size() / 2)
    //     {
    //         return ans;
    //     }
    // }
    // return -1;

    // Moore's voting algorithm
    int freq = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 1};
    cout << "Majority element is " << majorityElement(nums) << endl;
    return 0;
}
