#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        unordered_set<char> jewel_set(jewels.begin(), jewels.end());

        for (char c : stones)
            if (jewel_set.count(c))
                count++;

        return count;
    }
};

int main()
{
    Solution sol;
    string jewels = "aA", stones = "aAAbbbb";
    cout << sol.numJewelsInStones(jewels, stones);

    return 0;
}