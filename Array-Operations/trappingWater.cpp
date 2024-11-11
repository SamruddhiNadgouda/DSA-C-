#include <iostream>
#include <vector>
using namespace std;

int trappingWater(vector<int> heights)
{
    // Optimized approach
    vector<int> leftMax(heights.size(), 0);
    leftMax[0] = heights[0];
    for (int i = 1; i < heights.size(); i++)
    {
        leftMax[i] = max(heights[i], leftMax[i - 1]);
    }
    vector<int> rightMax(heights.size(), 0);
    rightMax[heights.size() - 1] = heights[heights.size() - 1];
    for (int i = heights.size() - 2; i >= 0; i--)
    {
        rightMax[i] = max(heights[i], rightMax[i + 1]);
    }
    int trappingWater = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int waterLevel = min(leftMax[i], rightMax[i]);
        trappingWater += waterLevel - heights[i];
    }
    return trappingWater;
}

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container with trapping water is " << trappingWater(heights) << endl;
    return 0;
}