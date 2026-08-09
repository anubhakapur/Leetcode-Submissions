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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0))); //dp[n][cnt][holdingStock]
        for(int i=n-1;i>=0;i--){
            for(int cnt=1;cnt>=0;cnt--){//c==2 mei sb 0 hai as per base case 
                int buy=-prices[i]+dp[i+1][cnt][1];
                int skipBuying=dp[i+1][cnt][0];
                dp[i][cnt][0]=max(buy,skipBuying);

                int sell=prices[i]+dp[i][cnt+1][0];
                int skipSelling=dp[i+1][cnt][1];
                dp[i][cnt][1]=max(sell,skipSelling);
            }
        }
        return dp[0][0][0];//starting state is idx 0, cnt 0 and stock bhi nhi h
    }
};