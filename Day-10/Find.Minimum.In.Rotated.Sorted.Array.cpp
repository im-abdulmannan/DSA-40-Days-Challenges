#include <iostream>
#include <vector>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int minElement = nums[0];

        for (int index = 0; index < nums.size(); index++)
        {
            if (nums[index] < minElement)
                minElement = nums[index];
        }

        return minElement;
    }
};

int main(void)
{
    Solution S;
    std::vector<int> nums = {3, 4, 5, 1, 2};
    std::cout << S.findMin(nums);

    return 0;
}