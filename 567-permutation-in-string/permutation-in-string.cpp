class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)freq[s1[i]-'a']++;
        for(int i=0;i<=m-n;i++){
            vector<int>f(26,0);
            for(int j=i;j<i+n;j++){
                f[s2[j]-'a']++;
            } 
            bool found=true;
            for(int i=0;i<26;i++){
                if(freq[i]!=f[i]){
                    found=false;
                    break;
                }
            }
            if(found)return true; 
        }
        return false;
    }
};
