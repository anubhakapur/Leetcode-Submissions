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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode*rightMostNode=nullptr;
            while(n--){
                TreeNode*curr=q.front();
                rightMostNode=curr;
                q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            res.push_back(rightMostNode->val);
        }
        return res;
    }
};
