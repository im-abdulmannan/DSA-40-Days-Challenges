#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int writeIndex = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[writeIndex++] = nums[i];
        }

        return writeIndex;
    }
};

int main(void)
{
    Solution sol;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    sol.removeDuplicates(nums);

    return 0;
}