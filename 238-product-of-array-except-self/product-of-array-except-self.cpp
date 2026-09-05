class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        int prod=1;
        int cntOfZeros=0;
        int zeroIdx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroIdx=i;
                cntOfZeros++;
            }
            else prod=prod*nums[i];
        }
        if(cntOfZeros>1)return res; //array of zeros
        if(zeroIdx!=-1){
            res[zeroIdx]=prod;
            return res;
        }
        for(int i=0;i<n;i++){
            res[i]=prod/nums[i];
        }
        return res;
    }
};
