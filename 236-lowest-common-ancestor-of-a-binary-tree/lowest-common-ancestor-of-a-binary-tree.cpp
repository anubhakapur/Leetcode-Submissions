/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode*root,TreeNode*target,vector<TreeNode*>&res){
        if(!root)return false;
        res.push_back(root);
        if(root==target)return true;
        bool foundAtLeft=findPath(root->left,target,res);
        bool foundAtRight=findPath(root->right,target,res);
        if(foundAtLeft||foundAtRight)return true;
        res.pop_back();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>rootToP;
        vector<TreeNode*>rootToQ;
        findPath(root,p,rootToP);
        findPath(root,q,rootToQ);
        TreeNode*ans=nullptr;
        int i=0;
        while(i< rootToP.size() && i<rootToQ.size()){
            if(rootToP[i]==rootToQ[i])ans=rootToP[i];
            else break;
            i++;
        }
        return ans;
    }
};