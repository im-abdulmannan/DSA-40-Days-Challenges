#include <iostream>
#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);

        std::vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);

        return dp[n - 1];
    }
};

int main(void)
{
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << "Maximum amount of money you can rob without alerting the police: " << sol.rob(nums) << std::endl;

    return 0;
}