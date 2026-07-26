class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%2==1)return false;
        int target=s/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int s=1;s<=target;s++){
                bool notPick=dp[i-1][s];
                bool pick=false;
                if(nums[i]<=s){
                    pick=dp[i-1][s-nums[i]];
                }
                dp[i][s]=pick||notPick;
            }
        }
        return dp[n-1][target];
    }
};