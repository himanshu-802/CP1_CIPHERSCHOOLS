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
    int ind=0;
    map<int,int>mp;
    TreeNode* func(vector<int>pre,vector<int>in,int st,int end)
    {
           if(st>end)return NULL;
          int num=pre[ind]; ind=ind+1;
          TreeNode* newnode= new TreeNode(num);
          if(st==end){
              return newnode;
          }
        newnode->left=func(pre,in,st,mp[num]-1);
        newnode->right= func(pre,in,mp[num]+1,end);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int st=0, end=inorder.size();
        for(int i=0;i<end;i++)
        {
            mp[inorder[i]]=i;
        }
        return func(preorder,inorder,st,end-1);   
    }
};
