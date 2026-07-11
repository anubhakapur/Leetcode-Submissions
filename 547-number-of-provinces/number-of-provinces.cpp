class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool> &visited,int node){
        visited[node]=1;
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 && visited[i]==false){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                cnt++;
            }
        }
        return cnt;
    }
};