#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int lastStoneWeight(std::vector<int> &stones)
    {
        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int x = stones[n - 1], y = stones[n - 2];

            if (x == y)
            {
                stones.resize(n - 2);
            }

            else
            {
                stones[n - 2] = x - y;
                stones.resize(n - 1);
            }
        }

        return stones.size() ? stones[0] : 0;
    }
};

int main(void)
{
    Solution S;
    std::vector<int> stones = {2, 7, 4, 1, 8, 1};
    std::cout << S.lastStoneWeight(stones);

    return 0;
}