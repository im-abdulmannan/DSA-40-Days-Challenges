#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                set.erase(nums[i - k - 1]);

            if (!set.insert(nums[i]).second)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << sol.containsNearbyDuplicate(nums, k);

    return 0;
}