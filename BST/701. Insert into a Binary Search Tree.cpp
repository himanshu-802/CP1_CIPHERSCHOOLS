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
    TreeNode* insertHelper(TreeNode* ptr,int val)
    {
        if(ptr==NULL){
            TreeNode* newnode= new TreeNode(val);
            return newnode;
        }
        if(ptr->val<=val){
            ptr->right=insertHelper(ptr->right,val);
        }
        else {
            ptr->left = insertHelper(ptr->left,val);
        }
        return ptr;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       return insertHelper(root,val);
    }
};
