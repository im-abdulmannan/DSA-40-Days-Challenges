#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        while (n % 2 == 0)
        {
            n /= 2;
        }

        return n == 1;
    }
};

int main(void)

{
    Solution sol;
    int n = 32;
    cout << sol.isPowerOfTwo(n);

    return 0;
}