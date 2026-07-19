class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto[cost,cell]=pq.top();
            pq.pop();
            auto [i,j]=cell;
            for(auto&dir:directions){
                int x=i+dir[0];
                int y=j+dir[1];
                if(x>=0 && x<n && y>=0 && y<m){
                    int d=max(abs(heights[x][y]-heights[i][j]),cost);
                    if(d<dist[x][y]){
                        dist[x][y]=d;
                        pq.push({d,{x,y}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};