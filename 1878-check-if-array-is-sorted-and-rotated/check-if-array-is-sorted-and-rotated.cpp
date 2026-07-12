class Solution {
public:
    void rotateArray(vector<int>& nums){
        int firstElement=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            nums[i]=nums[i+1];
        }
        nums[nums.size()-1]=firstElement;
    }
    bool check(vector<int>& nums) {
        vector<int>sortedArray(nums.begin(),nums.end());
        sort(sortedArray.begin(),sortedArray.end());
        int rotations=nums.size();
        for(int i=1;i<=rotations;i++){
            rotateArray(nums);
            if(nums==sortedArray)return true;
        }
        return false;
    }
};