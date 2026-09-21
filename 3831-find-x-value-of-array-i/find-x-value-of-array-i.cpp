class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>res(k);
        vector<long long>prev(k);
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<long long>curr(k);
            int x=nums[i]%k;
            curr[x]++;
            for(int rem=0;rem<k;rem++){
                if(prev[rem]==0)continue;
                int newRem=(rem*x)%k;
                curr[newRem]+=prev[rem];
            }
            for(int rem=0;rem<k;rem++){
                res[rem]+=curr[rem];
            }
            prev=curr;
        }
        return res;
    }
};