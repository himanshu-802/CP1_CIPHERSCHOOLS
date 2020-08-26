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
 bool isValidBST(TreeNode* root, TreeNode* nmin = nullptr, TreeNode* nmax = nullptr) {
        if(!root) 
            return true;
        if(nmin && root->val <= nmin->val)
            return false;
        if(nmax && root->val >= nmax->val)
            return false;
        return isValidBST(root->left, nmin, root) && isValidBST(root->right, root, nmax);  
}
};
