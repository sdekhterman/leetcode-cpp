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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            vector<int>dud;
            return dud;
        }
        vector<int>output{root->val};
        if (root->left != nullptr) {
            vector<int>leftVec = inorderTraversal(root->left);
            output.insert(output.begin(), leftVec.begin(), leftVec.end());
        }
        if (root->right != nullptr) {
            vector<int>rightVec = inorderTraversal(root->right);
            output.insert(output.end(), rightVec.begin(), rightVec.end());
        }
        return output;
    }
};
