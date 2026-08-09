class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>nextDay(2,0);
         for(int i=n-1;i>=0;i--){
            int buy=nextDay[1]-prices[i];
            int skipBuying=nextDay[0];
            curr[0]=max(buy,skipBuying);

            int sell=curr[0]+prices[i]-fee;
            int skipSelling=nextDay[1];
            curr[1]=max(sell,skipSelling);
            nextDay=curr;
        }
        return curr[0];
    }
};