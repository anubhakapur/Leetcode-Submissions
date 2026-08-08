class Solution {
public:
    bool solve(string &s,string&p,int i,int j,vector<vector<int>>&dp){
        //pattern exhausted
        if(j>=p.length())return (i>=s.length());
        //string exhaused
        if(i>=s.length()){
            //remaining pattern must be all '*'
            for(int k=j;k<p.length();k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[j]=='?')return dp[i][j]=solve(s,p,i+1,j+1,dp);
        if(p[j]=='*'){//'*' matches zero characters so move pattern: solve(i, j+1)
        //'*' matches s[i] so move string: solve(i+1, j) ie j again can come to this if 
            return dp[i][j]=solve(s,p,i,j+1,dp)|| solve(s,p,i+1,j,dp);
        }
        if(s[i]==p[j])return dp[i][j]=solve(s,p,i+1,j+1,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[n][m]=true;
        for(int j=m-1;j>=0;j--){ // eg **a
            if(p[j]=='*')dp[n][j]=dp[n][j+1];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(p[j]=='?')dp[i][j]=dp[i+1][j+1];
                else if(p[j]=='*')dp[i][j]=dp[i][j+1] || dp[i+1][j];
                else if(s[i]==p[j])dp[i][j]=dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};