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
    TreeNode*solve(TreeNode* root, int key){
        if(!root)return nullptr;
        if(root->val==key){
            if(!root->left)return root->right;
            root->left->right=root->right;
            TreeNode*temp=root->left;
            root->left=root->right=nullptr;
            return temp;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val==key){
            if(!root->left)return root->right;
            if(!root->right)return root->left;
            TreeNode*temp=root->left->right;
            root->left->right=root->right;
            if(temp){
                TreeNode* curr=root->right;
                while(curr && curr->left){
                    curr=curr->left;
                }
                if(curr)curr->left=temp;
            }
            return root->left;
        }
        return solve(root,key);
    }
};