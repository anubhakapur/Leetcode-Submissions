class Solution {
public:
    bool solve(int i,vector<int>&nums,int s1,vector<vector<int>> &dp,int s){
        if(i==nums.size()){
            return (s1==(s-s1));
        }
        if(dp[i][s1]!=-1){
            return dp[i][s1];
        }
        bool addTos1=solve(i+1,nums,s1+nums[i],dp,s);
        bool addTos2=solve(i+1,nums,s1,dp,s);
        return dp[i][s1]=addTos1||addTos2;;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(s+1,-1));
        return solve(0,nums,0,dp,s);
    }
};