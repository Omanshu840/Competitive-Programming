/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *ans;

    bool find(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return false;

        int left = find(root->left, p, q);

        int right = find(root->right, p, q);

        int mid = (root == p || root == q);

        if (mid + right + left >= 2)
            ans = root;

        return (left + right + mid);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        int f = 0;

        find(root, p, q);

        return ans;
    }
};