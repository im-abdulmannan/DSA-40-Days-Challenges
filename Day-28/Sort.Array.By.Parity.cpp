#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int> &nums)
    {
        int evenIndex = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                std::swap(nums[i], nums[evenIndex]);
                evenIndex++;
            }
        }

        return nums;
    }
};

int main(void)
{
    Solution sol;
    std::vector<int> nums = {3, 1, 2, 4};
    std::vector<int> result = sol.sortArrayByParity(nums);

    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    return 0;
}