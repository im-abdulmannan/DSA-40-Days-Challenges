#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                if (isPalindrome(s, left + 1, right))
                    return true;

                if (isPalindrome(s, left, right - 1))
                    return true;

                return false;
            }

            left++;
            right--;
        }

        return true;
    }

private:
    bool isPalindrome(string s, int left, int right)
    {

        while (left < right)
        {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};

int main(void)
{
    Solution S;
    string s = "abca";
    if (S.validPalindrome(s))
        cout << "Palindrome: " << s << endl;
    else
        cout << "Not Palindrome: " << s << endl;

    return 0;
}