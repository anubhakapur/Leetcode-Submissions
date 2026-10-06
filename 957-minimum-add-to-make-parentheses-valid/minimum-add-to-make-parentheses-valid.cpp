class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int openBraces=0;
        for(char&c:s){
            if(c=='(')openBraces++;
            else if(openBraces==0)cnt++;
            else openBraces--;
        }
        cnt+=openBraces;
        return cnt;
    }
};