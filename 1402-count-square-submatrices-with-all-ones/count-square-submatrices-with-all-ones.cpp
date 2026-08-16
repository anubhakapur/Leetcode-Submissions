class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=solve(i,j+1,matrix,dp);
        int bottom=solve(i+1,j,matrix,dp);
        int diag=solve(i+1,j+1,matrix,dp);
        return dp[i][j]=(1+min({right,bottom,diag}));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size(); 
        int ans = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    ans += solve(i,j,matrix,dp);
                }
            }
        }
        
        return ans;
    }
};