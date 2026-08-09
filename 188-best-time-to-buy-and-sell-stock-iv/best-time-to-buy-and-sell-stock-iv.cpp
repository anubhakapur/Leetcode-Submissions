class Solution {
public:
        int solve(vector<int>&prices,int i,int cnt,int holdingStock,vector<vector<vector<int>>>&dp,int k){
        if(i>=prices.size() || cnt==k)return 0;
        if(dp[i][cnt][holdingStock]!=-1)return dp[i][cnt][holdingStock];
        if(holdingStock==0){
            int buy=-prices[i]+solve(prices,i+1,cnt,1,dp,k);
            int skipBuying=solve(prices,i+1,cnt,0,dp,k);
            return dp[i][cnt][holdingStock]=max(buy,skipBuying);
        }else{
            int sell=prices[i]+solve(prices,i,cnt+1,0,dp,k);
            int skipSelling=solve(prices,i+1,cnt,1,dp,k);
            return dp[i][cnt][holdingStock]=max(sell,skipSelling);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k,vector<int>(2,-1))); 
        return solve(prices,0,0,0,dp,k);

    }
};