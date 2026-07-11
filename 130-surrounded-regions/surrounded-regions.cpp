class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>&visited){
        visited[i][j]=1;
        for(auto&d:directions){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0 && x<board.size() && y>=0 && y<board[i].size() && board[x][y]=='O' && !visited[x][y]){
                dfs(board,x,y,visited);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if (board[i][0]=='O')dfs(board,i,0,visited);
            if (board[i][n-1]=='O')dfs(board,i,n-1,visited);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')dfs(board,0,i,visited);
            if(board[m-1][i]=='O')dfs(board,m-1,i,visited);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j])board[i][j]='X';
            }
        }
    }
};