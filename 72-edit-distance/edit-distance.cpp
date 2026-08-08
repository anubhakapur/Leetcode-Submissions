class Solution {
public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i==a.length()){
            return (b.length()-j);
        }
        if(j==b.length()){
            return (a.length()-i);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=solve(a,b,i+1,j+1,dp);
        }
        int insertOp=1+solve(a,b,i,j+1,dp);
        int deleteOp=1+solve(a,b,i+1,j,dp);
        int replaceOp=1+solve(a,b,i+1,j+1,dp);
        return dp[i][j]=min({insertOp,deleteOp,replaceOp});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)dp[n][j]=m-j;
        for(int i=0;i<=n;i++)dp[i][m]=n-i;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]})+1;
                }
            }
        }
        return dp[0][0];
    }
};