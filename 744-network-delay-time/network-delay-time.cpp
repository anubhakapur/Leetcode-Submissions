class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res(n+1,INT_MAX);
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time,node]=pq.top();
            pq.pop();
            for(auto &edge:adj[node]){
                int v=edge.first;
                int wt=edge.second;
                if(res[v]>wt+time){
                    res[v]=wt+time;
                    pq.push({res[v],v});
                }
            }
        }
        int maxTime=INT_MIN;
        for(int i=1;i<=n;i++){
            maxTime=max(maxTime,res[i]);
        }
        return (maxTime==INT_MAX)?-1:maxTime;
    }
};