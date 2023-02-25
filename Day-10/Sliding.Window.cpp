#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int maxProfit = 0;

        for (int sell = 0; sell < prices.size(); sell++)
        {
            if (buy > prices[sell])
            {
                buy = prices[sell];
            }

            else if (prices[sell] - buy > maxProfit)
            {
                maxProfit = prices[sell] - buy;
            }
        }
        return maxProfit;
    }
};

int main()
{
    Solution S;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << S.maxProfit(prices) << endl;
    return 0;
}