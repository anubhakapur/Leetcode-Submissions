class Solution {
public:
    int solve(int i,int j,int m,int n, vector<vector<int>>&dp){
        if(i<0 || i>=m || j<0 || j>=n)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0)dp[i][j]=dp[i-1][j];
                if(j-1>=0)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};