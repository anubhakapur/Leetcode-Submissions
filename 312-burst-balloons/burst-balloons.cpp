class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxCoins=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins=solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp)+nums[k]*nums[i-1]*nums[j+1];
            maxCoins=max(maxCoins,coins);
        }
        return dp[i][j]=maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,1,nums.size()-2,dp);
    }
};