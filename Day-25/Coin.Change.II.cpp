#include <iostream>
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main(void)
{
    Solution sol;
    int amount = 5;
    std::vector<int> coins = {1, 2, 5};
    std::cout << sol.change(amount, coins) << std::endl;

    return 0;
}