class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
        q.push({{0,0},1});
        grid[0][0]=1;
        while(!q.empty()){
            auto [cell,dist]=q.front();
            q.pop();
            auto [i,j]=cell;
            if(i==n-1 && j==m-1)return dist;
            for(auto &dir:directions){
                int x=i+dir[0];
                int y=j+dir[1];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
                    grid[x][y]=1;
                    q.push({{x,y},dist+1});
                }
            }
        }
        return -1;
    }
};