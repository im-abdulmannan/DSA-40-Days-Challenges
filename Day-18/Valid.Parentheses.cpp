#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> mystack;

        for (char c : s)
        {
            if (isOpening(c))
                mystack.push(c);

            else
            {
                if (mystack.empty())
                    return false;
                char top = mystack.top();
                mystack.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }

        return mystack.empty();
    }

private:
    bool isOpening(char c)
    {
        if (c == '(' || c == '{' || c == '[')
            return true;

        return false;
    }
};

int main(void)
{
    Solution sol;
    string s = "{[()]}{}[]";
    if (sol.isValid(s))
        cout << "Valid Parentheses: " << s << endl;

    else
        cout << "Invalid Parentheses: " << s << endl;

    return 0;
}