class DisjointSet{
    public:
    vector<int>parent;
    vector<int>Size;
    DisjointSet(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        Size.resize(n,1);
    }
    int findParent(int u){
        if(u==parent[u])return u;
        return parent[u]=findParent(parent[u]);
    }
    void Union(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(Size[pu]<Size[pv]){
            parent[pu]=pv;
            Size[pv]+=Size[pu];
        }else{
            parent[pv]=pu;
            Size[pu]+=Size[pv];   
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>emailsToUser;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(emailsToUser.find(accounts[i][j])==emailsToUser.end()){
                    emailsToUser[accounts[i][j]]=i;
                }else{
                    ds.Union(i,emailsToUser[accounts[i][j]]);
                }
            }
        }
        unordered_map<int, vector<string>> mergedEmails;
        for(auto&it:emailsToUser){
            string email=it.first;
            int user=it.second;
            int p=ds.findParent(user);
            mergedEmails[p].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto &it:mergedEmails) {
            int p=it.first;
            vector<string>emails=it.second;
            sort(emails.begin(),emails.end());
            vector<string> temp;
            temp.push_back(accounts[p][0]);
            for (auto &mail:emails){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};