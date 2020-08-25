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
    TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* ls= func(root->left,p,q);
        TreeNode* rs= func(root->right,p,q);
        
        if(ls && rs){
            return root;
        }
        if(ls==NULL)return rs;
        else return ls;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};




// LCA OF BST USING BST TREE PROPERT (RECURSIVE)


class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL){
            return NULL;
        }
        int num=root->val;
        if(num >p->val && num> q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(num < p->val && num < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
        
    }
        
};
