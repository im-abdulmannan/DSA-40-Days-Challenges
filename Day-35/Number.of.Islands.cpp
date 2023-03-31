#include <iostream>
#include <vector>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int m = grid.size(), n = grid[0].size();
        int num_island = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num_island++;
                    dfs(grid, i, j);
                }
            }
        }

        return num_island;
    }

private:
    void dfs(std::vector<std::vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;

        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

int main(void)
{
    Solution sol;

    std::vector<std::vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    std::cout << "Number of islands: " << sol.numIslands(grid) << std::endl;

    return 0;
}