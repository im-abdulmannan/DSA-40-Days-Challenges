#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_map<int, bool> mp;
        for (int num : nums)
            mp[num] = true;

        for (int i = 0; i <= nums.size(); i++)
            if (!mp[i])
                return i;

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << sol.missingNumber(nums);

    return 0;
}