#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string defanged;
        for (char c : address)
        {
            if (c == '.')
                defanged += "[.]";

            else
                defanged += c;
        }

        return defanged;
    }
};

int main(void)
{
    Solution S;
    string address = "255.100.50.0";
    cout << S.defangIPaddr(address);

    return 0;
}