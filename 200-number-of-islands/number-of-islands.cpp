class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& board,vector<vector<int>>&visited,int i,int j){
        visited[i][j]=1;
        for(auto&d:directions){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0 && x<board.size() && y>=0 && y<board[i].size() && board[x][y]=='1' && !visited[x][y]){
                dfs(board,visited,x,y);
            }
        }
    }
    int numIslands(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='1' && !visited[i][j]){
                    dfs(board,visited,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};