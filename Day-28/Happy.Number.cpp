#include <iostream>
#include <unordered_set>

class Solution
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> seen;

        while (n != 1)
        {
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            if (seen.count(sum) > 0)
                return false;

            seen.insert(sum);
            n = sum;
        }
        return true;
    }
};

int main(void)
{
    Solution sol;
    int n = 19;
    if (sol.isHappy(n))
        std::cout << n << " is a happy number." << std::endl;

    else
        std::cout << n << " is not a happy number." << std::endl;

    return 0;
}