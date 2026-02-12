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
    vector<int> BreadthFirstSearch(TreeNode* head){
        vector<int> res;
        if(head == nullptr) {return res;}

        res.insert(res.begin(), head->val);
        if((head->left == nullptr) && (head->right == nullptr)) {return res;} 

        vector<int> leftVec  {1};
        vector<int> rightVec {};

        if (head->left  != nullptr) {leftVec  = BreadthFirstSearch(head->left );}
        if (head->right != nullptr) {rightVec = BreadthFirstSearch(head->right);}
        
        res.insert(res.begin(),  leftVec.begin(),  leftVec.end());
        res.insert(res.begin()  , rightVec.begin(), rightVec.end());
        
        return res;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return BreadthFirstSearch(p) == BreadthFirstSearch(q);
    }
};
