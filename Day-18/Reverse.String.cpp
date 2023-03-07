#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    }
};

int main(void)
{
    Solution S;
    vector<char> s = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    S.reverseString(s);
    for (auto c : s)
    {
        cout << c;
    }

    return 0;
}