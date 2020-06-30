/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *Solution::buildTree(vector<int> &A)
{

    int n = A.size();

    if (n == 0)
    {
        return NULL;
    }

    int i;
    int ans = INT_MIN;
    int j;

    for (i = 0; i < n; i++)
    {
        if (ans < A[i])
        {
            j = i;
            ans = A[i];
        }
    }

    vector<int> temp1;
    vector<int> temp2;
    for (i = 0; i < j; i++)
    {
        temp1.push_back(A[i]);
    }

    for (i = j + 1; i < n; i++)
    {
        temp2.push_back(A[i]);
    }

    TreeNode *X = new TreeNode(ans);

    X->left = buildTree(temp1);
    X->right = buildTree(temp2);

    return X;
}
