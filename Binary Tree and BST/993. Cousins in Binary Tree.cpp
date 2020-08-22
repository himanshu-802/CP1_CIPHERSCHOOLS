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
   
    void level(TreeNode* root, int x, int lev, int &ans)
    {
        if(root==NULL){
            return;
        }
        if(root->val==x)
        {
            ans=lev; 
            return;
        }
        level(root->left,x,lev+1,ans);
        level(root->right,x,lev+1,ans);
    }
     bool parent(TreeNode* root, int x, int y)
     {
         if(root==NULL)return false;
         if(root->left!=NULL && root->right!=NULL)
         {
             if(root->left->val==x && root->right->val==y)
             {
                 cout<<"root is "<<root->val<<endl;
                 return true;
             }
             if(root->left->val==y && root->right->val==x)
             {
                 cout<<"root is "<<root->val<<endl;
                 return true;
             }
         }
         return parent(root->left,x,y) || parent(root->right,x,y);
     }
     bool isCousins(TreeNode* root, int x, int y) {
     int l1=1,l2=1;
          int z=0;
      level(root,x,z,l1);
      level(root,y,z,l2);
         cout<<l1<<" "<<l2<<endl;
     if(l1==l2)
     {
         if(parent(root,x,y))return false;
         else return true;
     }
      return false;   
    }
};
