class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();

        if(n>m)return "";

        unordered_map<char,int>freq;
        for(char c:t)freq[c]++;
        int requiredLength=freq.size();
        int minLength=m;
        string res="";

        int i=0,j=0,formedLength=0,startIndex=-1;
        unordered_map<char,int> windowFreq;
        while(j<m){
            windowFreq[s[j]]++;
            if(freq.find(s[j])!=freq.end() && freq[s[j]]==windowFreq[s[j]])formedLength++;
            while(formedLength==requiredLength){
                if(minLength>=j-i+1){
                    minLength=j-i+1;
                    startIndex=i;
                }
                windowFreq[s[i]]--;
                if(freq.find(s[i])!=freq.end() && freq[s[i]]>windowFreq[s[i]]){
                    formedLength--;
                }
                i++;
            }
            j++;
        }
        return (startIndex==-1)?"":s.substr(startIndex,minLength);
    }
};