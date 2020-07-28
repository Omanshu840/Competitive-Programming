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
class Solution {
public:
    vector<string> ans;
    
    void findpath(TreeNode* root, string s)
    {
        if(root==NULL)
            return;
        
        if(s.size()!=0)
        {
            s = s + "->";
        }
        
        s = s + to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(s);
        }
        else if(root->left==NULL)
        {
            findpath(root->right, s);
        }
        else if(root->right==NULL)
        {
            findpath(root->left, s);
        }
        else
        {
            findpath(root->left, s);
            findpath(root->right, s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
     
        string s;
        
        findpath(root, s);
        
        return ans;
        
    }
};
