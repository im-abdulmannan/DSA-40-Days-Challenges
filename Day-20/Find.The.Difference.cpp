#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char result = 0;
        for (char ch : s + t)
            result ^= ch;

        return result;
    }
};

int main(void)
{
    Solution sol;
    string s = "abcd", t = "abcde";
    cout << sol.findTheDifference(s, t);

    return 0;
}