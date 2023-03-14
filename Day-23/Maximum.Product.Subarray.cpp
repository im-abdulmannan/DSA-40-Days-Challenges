#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int n = nums.size();
        int maxSoFar = nums[0], minSoFar = nums[0], ans = nums[0];

        for (int i = 1; i < n; i++)
        {
            int currMax = maxSoFar * nums[i];
            int currMin = minSoFar * nums[i];
            maxSoFar = std::max({nums[i], currMax, currMin});
            minSoFar = std::min({nums[i], currMax, currMin});
            ans = std::max(ans, maxSoFar);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {2, 3, -2, 4};
    std::cout << "Maximum product subarray: " << sol.maxProduct(nums);
    return 0;
}