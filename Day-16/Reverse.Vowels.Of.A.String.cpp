#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            while (i < j && !isVowel(s[i]))
                i++;

            while (i < j && !isVowel(s[j]))
                j--;

            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main(void)
{
    Solution S;
    string s = "hello";
    cout << S.reverseVowels(s);

    return 0;
}