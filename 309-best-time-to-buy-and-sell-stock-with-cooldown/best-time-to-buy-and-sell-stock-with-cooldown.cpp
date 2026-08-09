class Solution {
public:
    int solve(vector<int>&prices,int i,int holdingStock,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][holdingStock]!=-1)return dp[i][holdingStock];
        if(holdingStock==0){
            int buy=-prices[i]+solve(prices,i+1,true,dp);
            int skipBuying=solve(prices,i+1,false,dp);
            return dp[i][holdingStock]=max(buy,skipBuying);
        }else{
            int sell=prices[i]+solve(prices,i+2,false,dp);// i+2 for cooldown
            int skipSelling=solve(prices,i+1,true,dp);
            return dp[i][holdingStock]=max(sell,skipSelling);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};