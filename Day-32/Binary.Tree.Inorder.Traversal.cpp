#include <iostream>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        inorder(root, result);
        return result;
    }

private:
    void inorder(TreeNode *root, std::vector<int> &result)
    {
        if (!root)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};

int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);

    std::vector<int> res = sol.inorderTraversal(root);
    for (int num : res)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}