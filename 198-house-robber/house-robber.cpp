class Solution {
public:
    int solve(int i,int &n,vector<int>&nums,vector<int>&dp){
        if(i==n-1||i==n-2)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int amtRobbed=INT_MIN;
        for(int h=i+2;h<n;h++){
            amtRobbed=max(amtRobbed,solve(h,n,nums,dp)); 
        }
        return dp[i]=amtRobbed+nums[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return nums[0];
        vector<int>dp(n,-1);
        return max(solve(0,n,nums,dp),solve(1,n,nums,dp));
    }
};