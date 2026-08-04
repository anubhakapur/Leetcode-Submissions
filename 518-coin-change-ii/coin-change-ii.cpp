class Solution {
public:
    int solve(int idx, int sum,int amount, vector<int>& coins, vector<vector<int>>&dp){
        if(sum>amount)return 0;
        if(idx>=coins.size()){
            if(sum==amount)return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int take=0;
        if(sum+coins[idx]<=amount){
            take=solve(idx,sum+coins[idx],amount,coins,dp);
        }
        int skip=solve(idx+1,sum,amount,coins,dp);
        return dp[idx][sum]=(take+skip);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,0,amount,coins,dp);
    }
};