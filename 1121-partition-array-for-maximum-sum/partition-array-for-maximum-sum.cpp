class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxSum=INT_MIN;
            int len=0;
            int maxElement=INT_MIN;
            for(int j=i;j<min((int)arr.size(),i+k);j++){
            len++;
            maxElement=max(maxElement,arr[j]);
            int currSum=len*maxElement+dp[j+1];
            maxSum=max(maxSum,currSum);
        }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};