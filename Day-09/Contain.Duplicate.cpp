#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        if (!nums.size())
            return 0;

        std::unordered_set<int> st;

        for (int index : nums)
        {
            st.insert(index);
        }

        return st.size() != nums.size();
    }
};

int main(void)
{
    Solution S;
    std::vector<int> nums = {10, 5, 3, 4, 3, 5, 6};
    if (S.containsDuplicate(nums))
        std::cout << "Yes";

    else
        std::cout << "No";

    return 0;
}