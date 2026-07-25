class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(i>=triangle.size() || j>=triangle[i].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp))+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=(n*(n+1))/2;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0) continue;
                if(i-1>=0)dp[i][j]=min(dp[i][j],dp[i-1][j]);
                if(j-1>=0 && i-1>=0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                dp[i][j]+=triangle[i][j];
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,dp[n-1][i]);
        }
        return res;
    }
};