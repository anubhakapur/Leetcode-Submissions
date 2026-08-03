class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,INT_MAX);
        prev[0]=0;
        for(int i=0;i<n;i++)prev[0]=0;
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0){
                    prev[amt]=amt/coins[0];
            }
        }

        for(int i=1;i<n;i++){
            vector<int>curr(amount+1,INT_MAX);
            curr[0]=0;
            for(int amt=1;amt<=amount;amt++){
                int skip=prev[amt];
                int take = INT_MAX;
                if (coins[i]<=amt && curr[amt-coins[i]] != INT_MAX)take=1+curr[amt-coins[i]];
                curr[amt]=min(skip,take);
            }
            prev=curr;
        }
        return (prev[amount]==INT_MAX)?-1:prev[amount];
    }
};