class Solution {
public:
    int solve(int s,int e,vector<int>&nums,vector<int>&dp){
        if(s>=e)return 0;
        if(dp[s]!=-1)return dp[s];
        return dp[s]=max(nums[s]+solve(s+2,e,nums,dp),solve(s+1,e,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1)return nums[0];
        vector<int>dp(n,-1);
        int ans1=solve(0,n-1,nums,dp);
        fill(dp.begin(),dp.end(),-1);
        int ans2=solve(1,n,nums,dp);
        return max(ans1,ans2);
    }
};