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
        queue<pair<int,TreeNode*>>q;
        map<int,int>mpp;
        vector<int>res;
        q.push({0,root});
        while(!q.empty()){
            int row=q.front().first;
            TreeNode*currNode=q.front().second;
            q.pop();
            mpp[row]=currNode->val;
            if(currNode->left)q.push({row+1,currNode->left});
            if(currNode->right)q.push({row+1,currNode->right});
        }
        for(auto & it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};