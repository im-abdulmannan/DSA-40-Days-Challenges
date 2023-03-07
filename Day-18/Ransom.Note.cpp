#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};
        for (int i = 0; i < magazine.length(); i++)
        {
            count[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (count[ransomNote[i] - 'a'] == 0)
                return false;

            count[ransomNote[i] - 'a']--;
        }

        return true;
    }
};

int main(void)
{
    Solution S;
    string ransomNote = "aa", magazine = "aab";
    cout << S.canConstruct(ransomNote, magazine);

    return 0;
}