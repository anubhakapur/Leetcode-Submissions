class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<char>st;
        for(char&c:s){
            if(c=='(')st.push(c);
            else if(st.empty())cnt++;
            else st.pop();
        }
        cnt+=st.size();
        return cnt;
    }
};