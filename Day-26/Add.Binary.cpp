#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        std::reverse(begin(ans), end(ans));
        return ans;
    }
};

int main(void)
{
    Solution sol;
    std::string a = "1010", b = "1011";
    std::cout << sol.addBinary(a, b) << std::endl;

    return 0;
}