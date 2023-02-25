#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum_sum = INT_MIN;
        int maximum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            maximum = maximum + nums[i];
            if (maximum_sum < maximum)
            {
                maximum_sum = maximum;
            }

            if (maximum < 0)
            {
                maximum = 0;
            }
        }

        return maximum_sum;
    }
};

int main(void)
{
    Solution S;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Contiguous sum is " << S.maxSubArray(nums) << endl;
    return 0;
}