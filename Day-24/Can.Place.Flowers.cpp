#include <iostream>
#include <vector>

class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;

                if (--n == 0)
                    return true;
            }
        }

        return false;
    }
};

int main(void)
{
    Solution sol;
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    if (sol.canPlaceFlowers(flowerbed, n))
    {
        std::cout << "Yes you can plant flower";
    }
    else
    {
        std::cout << "No you cannot plant flower";
    }

    return 0;
}