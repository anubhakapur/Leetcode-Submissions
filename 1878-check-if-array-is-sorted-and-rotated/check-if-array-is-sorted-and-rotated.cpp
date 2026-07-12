class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int noOfInversionPairs=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])noOfInversionPairs++;
        }
        if(nums[0]<nums[n-1])noOfInversionPairs++;
        return (noOfInversionPairs<=1);
    }
};