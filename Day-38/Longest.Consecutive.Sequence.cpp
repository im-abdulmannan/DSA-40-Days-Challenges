#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestSeq = 0;

        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int currSeq = 1;
                while (numSet.find(num + currSeq) != numSet.end())
                {
                    currSeq++;
                }

                longestSeq = max(longestSeq, currSeq);
            }
        }
        return longestSeq;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "The length of the longest consecutive elements sequence is: " << sol.longestConsecutive(nums) << endl;

    return 0;
}