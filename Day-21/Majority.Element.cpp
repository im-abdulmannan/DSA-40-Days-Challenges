#include <iostream>
#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int count = 0, can = nums[0];

        for (int num : nums)
        {
            if (num == can)
                count++;
            else
                count--;

            if (count == 0)
            {
                can = num;
                count = 1;
            }
        }
        return can;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << sol.majorityElement(nums);

    return 0;
}