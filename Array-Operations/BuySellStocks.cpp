#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int stocks(vector<int> prices)
{
    int buyPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (buyPrice < prices[i])
        {
            int profit = prices[i] - buyPrice;
            maxProfit = max(maxProfit, profit);
        }
        else
        {
            buyPrice = prices[i];
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit is " << stocks(prices) << endl;
}