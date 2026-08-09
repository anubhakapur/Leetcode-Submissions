class Solution {
public:
    int solve(vector<int>& prices, int i,int holdingStock,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][holdingStock]!=-1)return dp[i][holdingStock];
        if(holdingStock==0){// ie cant sell as koi stock hai hi nhi,can only buy or skip
            int buy=-prices[i]+solve(prices,i+1,true,dp);// buy
            int skip=solve(prices,i+1,false,dp);//skip
            return dp[i][holdingStock]=max(buy,skip);
        }else{ //can sell or can skip, cant buy
            int sell=prices[i]+solve(prices,i,false,dp);// sold but can buy again from same day so no i++
            int skip=solve(prices,i+1,true,dp);//skip
            return dp[i][holdingStock]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); //2 possible values:true/1,false/0
        return solve(prices,0,0,dp);
    }
};