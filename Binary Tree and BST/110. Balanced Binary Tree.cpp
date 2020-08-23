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
    // bool func(TreeNode *root, int mini, int maxi)
    // {
    //     if(root==NULL)
    //     {
    //         return true;
    //     }
    //     if(root->val<mini || root->val>maxi)
    //     {
    //         return false;
    //     }
    //     cout<<root->val<<endl;
    //     return func(root->left,mini,root->val-1) && func(root->right,root->val+1,maxi);
    // }
    bool func(TreeNode* root, int *h,bool &flag)
    {
        if(root==NULL){
            return true;
        }
        int lh=0,rh=0;
        bool ls=func(root->left,&lh,flag);
        bool rs=func(root->right,&rh,flag);
        *h=max(lh,rh)+1;
        cout<<root->val<<" "<<lh<<" "<<rh<<endl;
        if(abs(lh-rh)<=1 && ls  && rs)  {
           return true;
        }
        return false;
       
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int height; bool flag=true;
        return func(root,&height,flag);
        
    }
};
