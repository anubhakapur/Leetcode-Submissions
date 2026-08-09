class Solution {
public:
    int solve(vector<int>& prices, int i,int holdingStock,int fee,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][holdingStock]!=-1)return dp[i][holdingStock];
        if(holdingStock==0){
            int buy=-prices[i]+solve(prices,i+1,1,fee,dp);
            int skip=solve(prices,i+1,0,fee,dp);
            return dp[i][holdingStock]=max(buy,skip);
        }else{ 
            int sell=prices[i]+solve(prices,i,0,fee,dp)-fee;
            int skip=solve(prices,i+1,1,fee,dp);
            return dp[i][holdingStock]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0)); 
         for(int i=n-1;i>=0;i--){
            int buy=dp[i+1][1]-prices[i];
            int skipBuying=dp[i+1][0];
            dp[i][0]=max(buy,skipBuying);

            int sell=dp[i][0]+prices[i]-fee;
            int skipSelling=dp[i+1][1];
            dp[i][1]=max(sell,skipSelling);
        }
        return dp[0][0];
    }
};