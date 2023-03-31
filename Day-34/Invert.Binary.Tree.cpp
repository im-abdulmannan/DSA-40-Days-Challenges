#include <iostream>

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};

int main(void)
{
    Solution sol;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode *inverted = sol.invertTree(root);

    std::cout << inverted->val << std::endl;
    std::cout << inverted->left->val << " " << inverted->right->val << std::endl;
    std::cout << inverted->left->left->val << " " << inverted->left->right->val << " "
              << inverted->right->left->val << " " << inverted->right->right->val << std::endl;

    return 0;
}