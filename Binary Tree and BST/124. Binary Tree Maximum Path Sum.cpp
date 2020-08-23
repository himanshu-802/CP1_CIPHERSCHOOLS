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
    int func(TreeNode* root, int &maxi)
    {
        if(root==NULL) return 0;
        int ls=func(root->left,maxi);
        int rs= func(root->right,maxi);
        int temp=max(max(ls,rs)+root->val, root->val);
        int temp2= max(temp, ls+rs+root->val);
        maxi=max(maxi,temp2);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        
        int sum=INT_MIN;
        int maxi=INT_MIN;
        func(root,sum);
        return sum;
    }
};
