#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;

        if (set1.size() < set2.size())
        {
            for (int num : set1)
            {
                if (set2.count(num))
                {
                    result.push_back(num);
                }
            }
        }
        else
        {
            for (int num : set2)
            {
                if (set1.count(num))
                {
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    Solution sol;
    vector<int> result = sol.intersection(nums1, nums2);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
