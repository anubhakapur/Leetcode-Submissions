class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX));

        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0){
                dp[0][amt]=amt/coins[0];
            }
        }

        for(int i=1;i<n;i++){
            for(int amt=1;amt<=amount;amt++){
                int skip=dp[i-1][amt];
                int take = INT_MAX;
                if (coins[i]<=amt && dp[i][amt-coins[i]] != INT_MAX)take=1+dp[i][amt-coins[i]];
                dp[i][amt]=min(skip,take);
            }
        }
        return (dp[n-1][amount]==INT_MAX)?-1:dp[n-1][amount];
    }
};