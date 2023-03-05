#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int carry = 0;

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int digit1 = i >= 0 ? num1[i] - '0' : 0;
            int digit2 = j >= 0 ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;

            int digit = sum % 10;
            result = to_string(digit) + result;

            i--;
            j--;
        }

        return result;
    }
};

int main(void)
{
    Solution S;
    string num1 = "11", num2 = "123";
    cout << S.addStrings(num1, num2);

    return 0;
}