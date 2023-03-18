#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> uniqueEmails;
        for (const string &email : emails)
        {
            string parsedEmail;
            bool foundAt = false, ignoreChars = false;
            for (char c : email)
            {
                if (c == '@')
                {
                    foundAt = true;
                    ignoreChars = false;
                }
                if (foundAt)
                {
                    parsedEmail += c;
                }
                else
                {
                    if (c == '.')
                    {
                        continue;
                    }
                    else if (c == '+')
                    {
                        ignoreChars = true;
                        continue;
                    }
                    if (!ignoreChars)
                    {
                        parsedEmail += c;
                    }
                }
            }
            uniqueEmails.insert(parsedEmail);
        }
        return uniqueEmails.size();
    }
};