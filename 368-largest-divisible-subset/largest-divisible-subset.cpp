class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>parent(n);
        int maxLen=1;
        int lastIndex=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                lastIndex=i;
            }
        }
        vector<int>res(maxLen);
        int idx=maxLen-1;
        while(lastIndex!=parent[lastIndex]){
            res[idx]=nums[lastIndex];
            lastIndex=parent[lastIndex];
            idx--;
        }
        res[idx]=nums[lastIndex];
        return res;
    }
};