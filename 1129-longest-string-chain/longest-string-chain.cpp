class Solution {
public:
    bool isPredecessor(string prev,string curr){
        if(curr.length()!=prev.length()+1)return false;
        int i=0,j=0;
        // We are allowed to skip exactly one character from curr
        while(i<prev.length() && j<curr.length()){
            if(prev[i]==curr[j]){
                i++;j++;
            }else{
                j++;
            }
        }
        // More than one mismatch
        if(j-i>1)return false;
        return true;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.length()<b.length();
        });
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<i;prev++){
                int take=0;
                if(prev==-1 || isPredecessor(words[prev],words[i])){
                    take=1+dp[i+1][i+1];
                }
            int notTake=dp[i+1][prev+1];
            dp[i][prev+1]=max(take,notTake);
        }
        }
        return dp[0][0];
    }
};