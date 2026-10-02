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
    string serialize(TreeNode*root){
        string res;
        serialize(root,res);
        return res;
    }
    void serialize(TreeNode*root,string &res){
        if(!root){
            res+='$#';
            return;
        }
        res+='$';
        res+=to_string(root->val);
        serialize(root->left,res);
        serialize(root->right,res);
    }
    vector<int> zFunction(string s){
        int l=0,r=0,n=s.length();
        vector<int>z(n,0);
        for(int i=1;i<n;i++){
            if(i<=r){
                z[i]=min(z[i-l],r-i+1);
            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        }
        return z;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root=serialize(root);
        string serialized_subRoot=serialize(subRoot);
        string combined=serialized_subRoot+"|"+serialized_root;
        vector<int>z=zFunction(combined);
        int subLen=serialized_subRoot.length();
        int n=combined.length();
        for(int i=subLen+1;i<n;i++){
            if(z[i]==subLen)return true;
        }
        return false;
    }
};