#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;

        if (n < 3)
            return false;

        while (i < n - 1 && arr[i] < arr[i + 1])
            i++;

        if (i == 0 || i == n - 1)
            return false;

        for (int j = 0; j < i; j++)
            if (arr[j] >= arr[j + 1])
                return false;

        for (int j = i; j < n - 1; j++)
            if (arr[j] <= arr[j + 1])
                return false;

        return true;
    }
};

int main(void)
{
    Solution S;
    vector<int> arr = {0, 3, 2, 1};
    cout << S.validMountainArray(arr);

    return 0;
}