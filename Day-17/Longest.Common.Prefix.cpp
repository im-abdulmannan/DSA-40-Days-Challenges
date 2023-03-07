#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].length(); ++i)
        {
            for (int j = 0; j < strs.size(); ++j)
            {
                if (i == strs[j].length() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
};

int main(void)
{
    Solution S;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << S.longestCommonPrefix(strs);

    return 0;
}