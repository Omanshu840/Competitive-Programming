/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isSame(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
    {
        return true;
    }
    else if (A == NULL)
    {
        return false;
    }
    else if (B == NULL)
    {
        return false;
    }
    else
    {
        if (A->val != B->val)
        {
            return false;
        }

        if (!(isSame(A->left, B->left)))
        {
            return false;
        }

        if (!(isSame(A->right, B->right)))
        {
            return false;
        }

        return true;
    }
}

bool isSame(Tr)

    int Solution::isSymmetric(TreeNode *A)
{
}
