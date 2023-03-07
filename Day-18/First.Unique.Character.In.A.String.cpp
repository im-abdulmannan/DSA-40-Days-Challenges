#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int count[26] = {0};

        for (char c : s)
        {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main(void)
{
    Solution S;
    string s = "loveleetcode";
    cout << "First Unique Character of String at Index: " << S.firstUniqChar(s);

    return 0;
}