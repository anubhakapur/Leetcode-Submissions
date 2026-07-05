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
    void fillParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parentPointerMap,TreeNode*parent){
        if(!root)return;
        parentPointerMap[root]=parent;
        fillParent(root->left,parentPointerMap,root);
        fillParent(root->right,parentPointerMap,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentPointerMap;
        fillParent(root,parentPointerMap,nullptr);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        vector<int>res;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist==k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            while(n--){
                TreeNode*node=q.front();
                q.pop();
                if(node->left && visited[node->left]==false){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && visited[node->right]==false){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentPointerMap[node]!=nullptr && visited[parentPointerMap[node]]==false){
                    q.push(parentPointerMap[node]);
                    visited[parentPointerMap[node]]=true;
                }
            }
            dist++;
        }
        return res;
    }
};