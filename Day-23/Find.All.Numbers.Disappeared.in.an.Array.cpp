#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        std::vector<int> missingNumbers;

        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                missingNumbers.push_back(i + 1);
            }
        }

        return missingNumbers;
    }
};

int main(void)
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;
    std::vector<int> result = sol.findDisappearedNumbers(nums);
    std::cout << "Missing numbers: ";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}