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
    bool isSameTree(TreeNode* rL, TreeNode* rR){
        if(!rL && !rR) {return true;}
        if(!rL || !rR) {return false;}

        if(rL->val != rR->val) {return false;}
        return isSameTree(rL->left, rR->right) && isSameTree(rL->right, rR->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {return true;}
        return isSameTree(root -> left, root ->right);
    }
};