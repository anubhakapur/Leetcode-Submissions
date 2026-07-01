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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            while(size--){
                TreeNode*currElement=q.front();
                q.pop();
                temp.push_back(currElement->val);
                if(currElement->left)q.push(currElement->left);
                if(currElement->right)q.push(currElement->right);
            }
            if(level&1)reverse(temp.begin(),temp.end());
            res.push_back(temp);
            level++;
        }
        return res;
    }
};