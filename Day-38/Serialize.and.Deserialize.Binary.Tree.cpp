#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*   Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null";

        string s = to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        s += "," + left + "," + right;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> nodes = split(data, ",");
        int i = 0;
        return deserializeHelper(nodes, i);
    }

private:
    TreeNode *deserializeHelper(vector<string> &nodes, int &i)
    {
        if (nodes[i] == "null")
        {
            i++;
            return nullptr;
        }

        int val = stoi(nodes[i]);
        i++;
        TreeNode *root = new TreeNode(val);
        root->left = deserializeHelper(nodes, i);
        root->right = deserializeHelper(nodes, i);
        return root;
    }

    vector<string> split(string &s, string delimiter)
    {
        vector<string> nodes;
        size_t pos = 0;

        while ((pos = s.find(delimiter)) != string::npos)
        {
            string token = s.substr(0, pos);
            nodes.push_back(token);
            s.erase(0, pos + delimiter.length());
        }

        nodes.push_back(s);
        return nodes;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Helper function for inorder traversal
void inorderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    Codec codec;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the tree
    TreeNode *deserialized = codec.deserialize(serialized);

    // Print the inorder traversal of the deserialized tree to verify it's correct
    cout << "Inorder traversal of deserialized tree: ";
    inorderTraversal(deserialized);
    cout << endl;

    return 0;
}
