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
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int s,int e,int &preIndex){
        if(s>e)return nullptr;
        int rootVal=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootVal);
        int i=s;
        for(;i<=e;i++){
            if(inorder[i]==rootVal){
                break;
            }
        }
        root->left=solve(preorder,inorder,s,i-1,preIndex);
        root->right=solve(preorder,inorder,i+1,e,preIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*root;
        int preIndex=0;
        root=solve(preorder,inorder,0,inorder.size()-1,preIndex);
        return root;
    }
};