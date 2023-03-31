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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    /* Tree 1 */
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    /* Tree 2 */
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSameTree(root1, root2);
    std::cout << "The two trees are " << (result ? "same" : "not same") << std::endl;

    return 0;
}