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
    bool func(TreeNode* root, int sum, vector<int>temp)
    {
        if(root==NULL){
            if(sum==0){
                return true;
            }
            else return false;
        }
        if(sum-root->val==0 && root->left==NULL && root->right==NULL){
            
            return true;
        }
        bool f1=false;
        temp.push_back(root->val);
        if(root->left)f1= func(root->left,sum-root->val,temp);
        if(root->right)f1= f1 || func(root->right, sum-root->val, temp);
    
        return f1;
      
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)return root;
        vector<int>temp;
        return func(root,sum,temp);
    }
};
