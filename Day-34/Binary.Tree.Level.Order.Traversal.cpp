#include <iostream>
#include <vector>
#include <queue>

/*   Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (root == nullptr)
            return result;

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int level_size = q.size();
            std::vector<int> level_values;

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *curr_node = q.front();
                q.pop();
                level_values.push_back(curr_node->val);

                if (curr_node->left)
                {
                    q.push(curr_node->left);
                }

                if (curr_node->right)
                {
                    q.push(curr_node->right);
                }
            }

            result.push_back(level_values);
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> level_order = sol.levelOrder(root);

    for (auto &level_values : level_order)
    {
        std::cout << "[ ";
        for (auto &val : level_values)
        {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}