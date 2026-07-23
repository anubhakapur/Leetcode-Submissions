class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>dist(n,vector<int>(n, INT_MAX));
        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];

        while(!pq.empty()){
            auto[cost,i,j]=pq.top();
            pq.pop();
            if (i==n-1 && j==n-1)return cost;
            if (cost>dist[i][j])continue;
            for(auto &dir:directions){
                int x=i+dir[0];
                int y=j+dir[1];
                if (x>=0 && x<n && y>=0 && y<n) {
                    int newCost=max(cost,grid[x][y]);
                    if (newCost<dist[x][y]) {
                        dist[x][y]=newCost;
                        pq.push({newCost,x,y});
                    }
                }
            }
        }
        return -1;
    }
};