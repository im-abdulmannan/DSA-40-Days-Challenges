#include <iostream>
#include <climits>

/* Definition for a binary tree node. */
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode *root, long long min_value, long long max_value)
    {
        if (!root)
            return true;

        if (root->val <= min_value || root->val >= max_value)
            return false;

        return isValidBST(root->left, min_value, root->val) && isValidBST(root->right, root->val, max_value);
    }
};

int main(void)
{
    Solution sol;

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    std::cout << "isValidBST: " << sol.isValidBST(root) << std::endl;

    return 0;
}