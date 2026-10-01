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
    pair<bool,int>solve(TreeNode*root){
        if(!root)return {true,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        if(left.first==false || right.first==false || abs(right.second-left.second)>1)return {false,-1};
        return {true,max(left.second,right.second)+1};
        
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};