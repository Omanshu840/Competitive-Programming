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
    int Height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + max(Height(root->left), Height(root->right));
        }
    }

    void leveltraverse(TreeNode *root, int h, vector<int> &temp)
    {
        if (root != NULL)
        {
            if (h == 0)
            {
                temp.push_back(root->val);
            }
            else
            {
                leveltraverse(root->left, h - 1, temp);
                leveltraverse(root->right, h - 1, temp);
            }
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {

        int h = Height(root);

        vector<vector<int>> ans;
        vector<int> temp;

        int i;

        for (i = 0; i < h; i++)
        {
            temp.clear();
            leveltraverse(root, i, temp);
            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};