#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> memo(n + 1, -1);
        return countWays(n, memo);
    }

    int countWays(int n, vector<int> &memo)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (memo[n] != -1)
            return memo[n];

        memo[n] = countWays(n - 1, memo) + countWays(n - 2, memo);
        return memo[n];
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << "There are " << sol.climbStairs(n) << " distinct ways you can climb to the top";

    return 0;
}