#include <iostream>
using namespace std;

class Solution
{
public:
    int twoSum(int A[], int nums, int target)
    {
        for (int first = 0; first < (nums - 1); first++)
        {
            for (int second = first + 1; second < nums; second++)
            {
                if (A[first] + A[second] == target)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

int main(void)
{
    Solution S;
    int A[] = {2, 7, 11, 15};
    int targetNum = 9;
    int size = sizeof(A) / sizeof(A[0]);
    if (S.twoSum(A, size, targetNum))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}