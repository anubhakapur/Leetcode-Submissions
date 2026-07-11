class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j]='0';
        for(auto&d:directions){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0 && x<board.size() && y>=0 && y<board[i].size() && board[x][y]=='1'){
                dfs(board,x,y);
            }
        }
    }
    int numIslands(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='1'){
                    dfs(board,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};