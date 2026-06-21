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
    int solve(TreeNode*root,int &maxSum){
        if(!root)return 0;
        int lSum=solve(root->left,maxSum);
        int rSum=solve(root->right,maxSum);
        int case1=lSum+root->val+rSum;
        int case2=max(lSum,rSum)+root->val;
        int case3=root->val;
        maxSum=max({maxSum,case1,case2,case3});
        return max(case2,case3);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};