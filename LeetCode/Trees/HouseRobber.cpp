/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, int> map;

    int rob(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        if (map.find(root) != map.end())
            return map[root];

        int left = 0;
        int right = 0;

        if (root->left != NULL)
            left = rob(root->left->left) + rob(root->left->right);

        if (root->right != NULL)
            right = rob(root->right->left) + rob(root->right->right);

        map[root] = max(root->val + left + right, rob(root->left) + rob(root->right));

        return map[root];
    }
};