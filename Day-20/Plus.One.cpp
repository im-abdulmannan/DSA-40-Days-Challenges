#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution solution;
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> digits3 = {9, 9, 9};

    vector<int> result1 = solution.plusOne(digits1);
    vector<int> result2 = solution.plusOne(digits2);
    vector<int> result3 = solution.plusOne(digits3);

    for (int digit : result1)
        cout << digit << " ";
    cout << endl;

    for (int digit : result2)
        cout << digit << " ";
    cout << endl;

    for (int digit : result3)
        cout << digit << " ";
    cout << endl;

    return 0;
}