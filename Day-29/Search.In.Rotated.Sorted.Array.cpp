#include <iostream>
#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        for (int index = 0; index < nums.size(); index++)
        {
            if (nums[index] == target)
                return index;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    std::cout << "Target value " << target << " is at index: " << sol.search(nums, target) << std::endl;

    return 0;
}