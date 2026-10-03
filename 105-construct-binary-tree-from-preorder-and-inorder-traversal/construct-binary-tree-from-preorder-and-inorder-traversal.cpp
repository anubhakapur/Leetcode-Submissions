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
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &preIdx,int inStart,int inEnd, unordered_map<int,int>&indices){
        if(inStart>inEnd)return nullptr;
        TreeNode*root=new TreeNode(preorder[preIdx++]);
        int idx=indices[root->val];
        root->left=solve(preorder,inorder,preIdx,inStart,idx-1,indices);
        root->right=solve(preorder,inorder,preIdx,idx+1,inEnd,indices);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        unordered_map<int,int>indices;
        int n=inorder.size();
        for(int i=0;i<n;i++)indices[inorder[i]]=i;
        return solve(preorder,inorder,idx,0,inorder.size()-1,indices);
    }
};