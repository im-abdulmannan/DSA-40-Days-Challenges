#include <iostream>
#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
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