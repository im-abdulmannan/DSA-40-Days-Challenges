#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> adj(n + 1);
        for (auto path : paths)
        {
            int u = path[0], v = path[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n);
        for (int i = 1; i <= n; i++)
        {
            vector<int> colors(5);
            for (int v : adj[i])
            {
                int color = ans[v - 1];
                colors[color] = 1;
            }
            for (int c = 1; c <= 4; c++)
            {
                if (colors[c] != 1)
                {
                    ans[i - 1] = c;
                    break;
                }
            }
        }
        return ans;
    }
};
