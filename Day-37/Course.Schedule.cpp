#include <iostream>
#include <vector>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> visited(numCourses, 0);

        for (auto pre : prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, graph, visited))
                    return false;
            }
        }

        return true;
    }

private:
    bool dfs(int course, std::vector<std::vector<int>> &graph, std::vector<int> &visited)
    {
        if (visited[course] == 1)
            return true;

        if (visited[course] == 2)
            return false;

        visited[course] = 1;

        for (auto req : graph[course])
        {
            if (dfs(req, graph, visited))
                return true;
        }

        visited[course] = 2;
        return false;
    }
};

int main(void)
{
    Solution sol;

    std::vector<std::vector<int>> prerequisites = {{1, 0}};
    int numCourses = 2;

    if (sol.canFinish(numCourses, prerequisites))
        std::cout << "You can finish all courses" << std::endl;

    else
        std::cout << "You cannot finish all courses" << std::endl;

    return 0;
}