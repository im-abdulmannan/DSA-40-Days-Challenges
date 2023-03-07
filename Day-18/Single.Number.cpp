#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> hashset;

        for (int num : nums)
        {
            if (hashset.count(num))
                hashset.erase(num);
            else
                hashset.insert(num);
        }

        return *hashset.begin();
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << sol.singleNumber(nums);

    return 0;
}