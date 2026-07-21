class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<bool>&visited){
        visited[node]=true;
        for(auto&v:adj[node]){
            if(!visited[v])dfs(v,adj,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1)return -1;
        int noOfComponents=0;
        vector<int>adj[n];
        for(auto&edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                noOfComponents++;
            }
        }
        return noOfComponents-1;
    }
};