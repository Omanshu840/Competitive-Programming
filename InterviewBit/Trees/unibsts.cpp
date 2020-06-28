/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode *> findans(int l, int h)
{
    vector<TreeNode *> ans;
    if (l > h)
    {
        ans.push_back(NULL);
        return ans;
    }

    int i;
    int j, k;
    for (i = l; i <= h; i++)
    {
        vector<TreeNode *> lft = findans(l, i - 1);
        vector<TreeNode *> rgt = findans(i + 1, h);

        for (j = 0; j < lft.size(); j++)
        {
            for (k = 0; k < rgt.size(); k++)
            {
                TreeNode *node = new TreeNode(i);

                node->left = lft[j];
                node->right = rgt[k];

                ans.push_back(node);
            }
        }

        lft.clear();
        rgt.clear();
    }

    return ans;
}

vector<TreeNode *> Solution::generateTrees(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<TreeNode *> ans = findans(1, A);

    return ans;
}
