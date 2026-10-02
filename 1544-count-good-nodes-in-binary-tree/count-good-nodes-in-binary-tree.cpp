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
    int solve(TreeNode*root, int maxVal){
        if(!root)return 0;
        if(root->val<maxVal)return solve(root->left,maxVal)+solve(root->right,maxVal);
        return 1+solve(root->left,root->val)+solve(root->right,root->val);
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};