#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int prev_bit = n % 2;
        n /= 2;
        while (n > 0)
        {
            int curr_bit = n % 2;
            if (curr_bit == prev_bit)
                return false;

            prev_bit = curr_bit;
            n /= 2;
        }

        return true;
    }
};

int main()
{
    Solution S;
    int n = 5;
    if (S.hasAlternatingBits(n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}