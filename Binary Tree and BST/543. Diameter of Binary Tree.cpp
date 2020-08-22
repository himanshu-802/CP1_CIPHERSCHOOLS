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
    int diameter(TreeNode* root, int *height)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=0,rh=0,ld=0,rd=0;
        ld= diameter(root->left,&lh);
        rd= diameter(root->right,&rh);
        *height= max(lh,rh)+1;
        return max(max(ld,rd), lh+rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
     
        int h=0;
        return diameter(root,&h);
    }
};
