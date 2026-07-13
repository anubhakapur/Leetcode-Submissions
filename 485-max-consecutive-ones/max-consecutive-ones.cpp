class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxOnes=0;
        int consecutiveOnes=0;
        for(int i=0;i<n;i++){
            maxOnes=max(maxOnes,consecutiveOnes);
            if(nums[i]==1){
                consecutiveOnes++;
            }else{
                consecutiveOnes=0;
            }
        }
        return max(maxOnes,consecutiveOnes);
    }
};