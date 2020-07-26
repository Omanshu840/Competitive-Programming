/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans;
    
    void findans(TreeNode*root, TreeNode *p, TreeNode *q)
    {
        if(root==NULL)
            return;
        
        int x = p->val;
        int z = q->val;
        int y = root->val;
        
        if( x < y && y < z)
            ans = root;
        else if( x < y && z < y)
            findans(root->left, p, q);
        else if(x > y && z > y)
            findans(root->right, p, q);
        else if(x==y)
            ans = p;
        else if(z==y)
            ans = q;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val > q->val)
            findans(root, q, p);
        else
            findans(root, p, q);
        
        return ans;
        
        
        
    }
};
