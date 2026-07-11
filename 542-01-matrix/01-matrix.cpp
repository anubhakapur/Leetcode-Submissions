class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>res(m,vector<int>(n,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
        vector<vector<int>>directions{{0,1}, {1,0}, {0,-1},{-1,0}};
        while(!q.empty()){
            auto [i,j,dist]=q.front();
            q.pop();
            res[i][j]=dist;
            for(auto &d:directions){
                int x=i+d[0];
                int y=j+d[1];
                if(x>=0 && x<m && y>=0 && y<n && !visited[x][y]){
                    visited[x][y]=1;
                    q.push({x,y,dist+1});
                }
            }

        }
        return res;
    }
};