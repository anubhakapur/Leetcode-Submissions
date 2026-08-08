class Solution {
public:
    int solve(string s1,string s2,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+solve(s1,s2,i+1,j+1,n,m,dp);
        return dp[i][j]=max(solve(s1,s2,i+1,j,n,m,dp),solve(s1,s2,i,j+1,n,m,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int lcs=solve(word1,word2,0,0,n,m,dp);
        return (n+m-lcs-lcs);
    }
};