#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int *A = new int[500]{};
        int *B = new int[500]{};

        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - '0';
            A[x]++;

            int y = t[i] - '0';
            B[y]++;
        }

        for (int i = 0; i < 500; i++)
        {
            if (A[i] != B[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution Sol;
    string s = "abba";
    string t = "aabb";

    cout << Sol.isAnagram(s, t);

    return 0;
}