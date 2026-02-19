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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int vectorSize = nums.size();
        if (1 == vectorSize) {
            TreeNode* center = new TreeNode(nums[0]);
            return center;
        }
        if (2 == vectorSize) {
            TreeNode* left   = new TreeNode(nums[0]);
            TreeNode* center = new TreeNode(nums[1], left, nullptr);
            return center;
        }
        if (3 == vectorSize) {
            TreeNode* left   = new TreeNode(nums[0]);
            TreeNode* right  = new TreeNode(nums[1]);
            TreeNode* center = new TreeNode(nums[2], left, right);
            return center;
        }
        int centerVal    = nums[vectorSize/2];
        std::vector<int>  leftVector;
        std::vector<int> rightVector;
        leftVector.insert(  leftVector.begin(), nums.begin(), nums.begin() + vectorSize/2 - 1);
        rightVector.insert(rightVector.begin(), nums.begin() + vectorSize/2 + 1, nums.end());
        TreeNode* left   = sortedArrayToBST( leftVector);
        TreeNode* right  = sortedArrayToBST(rightVector);
        TreeNode* center = new TreeNode(centerVal, left, right);
        
        return center;
    }
};
