#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int maxArea = 0;

        while (left < right)
        {
            int area = (right - left) * std::min(height[left], height[right]);
            maxArea = std::max(maxArea, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};

int main(void)
{
    Solution sol;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = sol.maxArea(height);
    std::cout << "The maximum amount of water a container can store is: " << result << std::endl;

    return 0;
}