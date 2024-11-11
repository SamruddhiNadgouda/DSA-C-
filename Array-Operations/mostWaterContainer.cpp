#include <iostream>
#include <vector>
using namespace std;

int mostWaterContainer(vector<int> heights)
{
    // Brute force
    // int maxWater = 0;
    // for (int i = 0; i < heights.size(); i++)
    // {
    //     for (int j = i + 1; j < heights.size(); j++)
    //     {
    //         int w = j - i;
    //         int ht = min(heights[i], heights[j]);
    //         int currWater = w * ht;
    //         maxWater = max(maxWater, currWater);
    //     }
    // }
    // return maxWater;

    // Optimized approach => two pointer
    int lp = 0, rp = heights.size() - 1;
    int maxWater = 0;
    while (lp < rp)
    {
        int w = rp - lp;
        int ht = min(heights[lp], heights[rp]);
        int currWater = w * ht;
        maxWater = max(currWater, maxWater);

        heights[lp] < heights[rp] ? lp++ : rp--;
    }
    return maxWater;
}

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container with most water is " << mostWaterContainer(heights) << endl;
    return 0;
}