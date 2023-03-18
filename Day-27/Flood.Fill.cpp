#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int currColor = image[sr][sc];
        if (currColor != newColor)
        {
            dfs(image, sr, sc, currColor, newColor);
        }
        return image;
    }

private:
    void dfs(vector<vector<int>> &image, int row, int col, int currColor, int newColor)
    {

        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != currColor)
        {
            return;
        }

        image[row][col] = newColor;

        dfs(image, row - 1, col, currColor, newColor);
        dfs(image, row + 1, col, currColor, newColor);
        dfs(image, row, col - 1, currColor, newColor);
        dfs(image, row, col + 1, currColor, newColor);
    }
};
