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
    int ans = 0;
    tuple<int,int,int>solve(TreeNode*root){ //return [sum, maxElement,minElement]
        if(!root)return {0,INT_MIN,INT_MAX};
        auto [lsum,lmax,lmin]=solve(root->left);
        auto [rsum,rmax,rmin]=solve(root->right);
        if(root->val>lmax && root->val<rmin){
            int cSum=lsum+rsum+root->val;
            ans=max(ans,cSum);
            return {cSum,max(rmax,root->val),min(lmin,root->val)};
        } 
        return {0,INT_MAX,INT_MIN};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};