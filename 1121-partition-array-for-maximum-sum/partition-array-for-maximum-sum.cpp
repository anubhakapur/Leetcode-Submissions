class Solution {
public:
    int solve(vector<int>& arr,int i,int k,vector<int>&dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxSum=INT_MIN;
        int len=0;
        int maxElement=INT_MIN;
        for(int j=i;j<min((int)arr.size(),i+k);j++){
            len++;
            maxElement=max(maxElement,arr[j]);
            int currSum=len*maxElement+solve(arr,j+1,k,dp);
            maxSum=max(maxSum,currSum);
        }
        return dp[i]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,0,k,dp);
    }
};