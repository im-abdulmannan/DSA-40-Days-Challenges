#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        std::vector<std::vector<int>> result;
        if (heights.empty())
            return result;

        int rows = heights.size(), cols = heights[0].size();
        std::vector<std::vector<bool>> can_reach_pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> can_reach_atlantic(rows, std::vector<bool>(cols, false));

        for (int i = 0; i < rows; i++)
        {
            dfs(heights, can_reach_pacific, i, 0);
        }

        for (int j = 0; j < cols; j++)
        {
            dfs(heights, can_reach_pacific, 0, j);
        }

        for (int i = 0; i < rows; i++)
        {
            dfs(heights, can_reach_atlantic, i, cols - 1);
        }

        for (int j = 0; j < cols; j++)
        {
            dfs(heights, can_reach_atlantic, rows - 1, j);
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (can_reach_pacific[i][j] && can_reach_atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(std::vector<std::vector<int>> &matrix, std::vector<std::vector<bool>> &can_reach, int i, int j)
    {
        if (can_reach[i][j])
            return;
        can_reach[i][j] = true;

        int rows = matrix.size(), cols = matrix[0].size();
        std::vector<std::vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto direction : directions)
        {
            int x = i + direction[0], y = j + direction[1];
            if (x < 0 || y < 0 || x >= rows || y >= cols || matrix[i][j] > matrix[x][y])
                continue;
            dfs(matrix, can_reach, x, y);
        }
    }
};

int main(void)
{
    Solution sol;

    std::vector<std::vector<int>> heights = {{1, 2, 2, 3, 5},
                                             {3, 2, 3, 4, 4},
                                             {2, 4, 5, 3, 1},
                                             {6, 7, 1, 4, 5},
                                             {5, 1, 1, 2, 4}};

    std::vector<std::vector<int>> result = sol.pacificAtlantic(heights);

    for (auto &row : result)
    {
        for (int x : row)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}