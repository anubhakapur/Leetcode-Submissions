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
    int solve(TreeNode*root){
        if(!root)return 0;
        return max(solve(root->left),solve(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int leftHeight=solve(root->left);
        int rightHeight=solve(root->right);
        int diameter=leftHeight+rightHeight;
        return max({diameter,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
    }
};