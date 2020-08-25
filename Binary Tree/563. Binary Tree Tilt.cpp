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
    int func(TreeNode* root,int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }
        int ls=func(root->left,ans);
        int rs= func(root->right,ans);
        
        ans+=abs(ls-rs);
        return ls+rs+root->val;
        
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        int num=func(root,ans);
        return ans;
    }
};
