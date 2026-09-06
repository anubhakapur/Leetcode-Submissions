class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxLen=0;
        int n=nums.size();
        int i=0;
        while(i<n){ //1 2 3 4 100 200
            int start=nums[i];
            int len=1;
            while(i<n){
                if(nums[i]==start)i++;
                else if(nums[i]==start+1){
                    i++;
                    start++;
                    len++;
                }
                else break;
            }
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};
