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
    int solve(TreeNode*root,int &maxLen){
        if(!root)return 0;
        int l=solve(root->left,maxLen);
        int r=solve(root->right,maxLen);
        maxLen=max({maxLen,max(l,r)+1,l+r+1});
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen=0;
        solve(root,maxLen);
        return maxLen-1;
    }
};