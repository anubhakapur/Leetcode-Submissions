class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxLen=0;
        int start;
        for(auto&x:st){
            if(st.find(x-1)==st.end()){
                int len=1;
                start=x;
                while(st.find(start+1)!=st.end()){
                    start++;
                    len++;
                }
                maxLen=max(maxLen,len);
            }
        }
        return maxLen;
    }
};
