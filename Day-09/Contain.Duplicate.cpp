class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (!nums.size())
            return 0;

        unordered_set<int> st;

        for (int i : nums)
        {
            st.insert(i);
        }

        return st.size() != nums.size();
    }
};
