#include <algorithm>
#include <string>


class Solution {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        
        std::transform(s.begin(), s.end(), s.begin(), [](char c) { return std::toupper(c); });
        s.erase(std::remove(s.begin(), s.end(), '-'), s.end());

        int n = s.length();
        std::string result;
        int count = 0; 

        for (int i = n - 1; i >= 0; i--) {
            if (count == k) { 
                result.insert(result.begin(), '-');
                count = 0;
            }
            result.insert(result.begin(), s[i]); 
            count++;
        }

        return result;
    }
};
