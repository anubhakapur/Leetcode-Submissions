class Solution {
public:
    int solve(vector<int>&prices,int i,int cnt,int holdingStock,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || cnt==2)return 0;
        if(dp[i][cnt][holdingStock]!=-1)return dp[i][cnt][holdingStock];
        if(holdingStock==0){
            int buy=-prices[i]+solve(prices,i+1,cnt,1,dp);
            int skipBuying=solve(prices,i+1,cnt,0,dp);
            return dp[i][cnt][holdingStock]=max(buy,skipBuying);
        }else{
            int sell=prices[i]+solve(prices,i,cnt+1,0,dp);
            int skipSelling=solve(prices,i+1,cnt,1,dp);
            return dp[i][cnt][holdingStock]=max(sell,skipSelling);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1))); //dp[n][cnt][holdingStock]
        return solve(prices,0,0,0,dp);
    }
};