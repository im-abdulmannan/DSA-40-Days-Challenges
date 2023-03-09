#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int index = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[j] != 0)
                nums[index++] = nums[j];

            j++;
        }

        while (index < nums.size())
        {
            nums[index++] = 0;
        }
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);

    return 0;
}
