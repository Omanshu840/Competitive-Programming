/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Height(TreeNode *A)
{
    if (A == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(Height(A->left), Height(A->right));
    }
}

void findLevel(TreeNode *A, int s, int level, vector<int> &temp)
{
    if (A == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        temp.push_back(A->val);
    }
    else
    {
        if (s)
        {
            findLevel(A->left, (s ^ 0), level - 1, temp);
            findLevel(A->right, (s ^ 0), level - 1, temp);
        }
        else
        {
            findLevel(A->right, (s ^ 0), level - 1, temp);
            findLevel(A->left, (s ^ 0), level - 1, temp);
        }
    }
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *A)
{

    int h = Height(A);

    int s;

    vector<vector<int>> ans;
    vector<int> temp;

    int i;

    for (i = 1; i <= h; i++)
    {
        s = i % 2;
        temp.clear();
        findLevel(A, s, i, temp);
        ans.push_back(temp);
    }

    return ans;
}
