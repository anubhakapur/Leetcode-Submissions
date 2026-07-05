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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inorderStart,int inorderEnd,int postorderStart,int postorderEnd){
        if(postorderStart>postorderEnd || inorderStart>inorderEnd)return nullptr;
        int rootVal=postorder[postorderEnd];
        TreeNode*root=new TreeNode(rootVal);
        int i=inorderStart;
        for(;i<=inorderEnd;i++){
            if(inorder[i]==rootVal)break;
        }
        int leftNodes=i-inorderStart;
        root->left=solve(inorder,postorder,inorderStart,i-1,postorderStart,postorderStart+leftNodes-1);
        root->right=solve(inorder,postorder,i+1,inorderEnd,postorderStart+leftNodes,postorderEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        TreeNode*root=solve(inorder,postorder,0,n-1,0,n-1);
        return root;
    }
};