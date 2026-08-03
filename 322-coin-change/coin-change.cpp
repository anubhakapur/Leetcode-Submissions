class Solution {
public:
    int solve(int i,vector<int>& coins, int amount,long long currSum,vector<vector<int>>&dp){
        if(currSum==amount)return 0;
        if(i>=coins.size() || currSum>amount)return INT_MAX;
        if(dp[i][currSum]!=-1)return dp[i][currSum];
        int take=INT_MAX;
        if(currSum+coins[i]<=amount){
            take=solve(i,coins,amount,currSum+coins[i],dp);
        }
        if(take!=INT_MAX)take++;
        int skip=solve(i+1,coins,amount,currSum,dp);
        return dp[i][currSum]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int minCoins=INT_MAX;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        minCoins=solve(0,coins,amount,0,dp);
        return (minCoins==INT_MAX)?-1:minCoins;
    }
};