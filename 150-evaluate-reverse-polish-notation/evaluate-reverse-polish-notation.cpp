class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &token:tokens){
            if(token!="+" && token!="-" && token!="*" && token!="/")st.push(stoi(token));
            else{
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                int res=0;
                if(token=="+")res=first+second;
                else if(token=="-")res=second-first;
                else if(token=="*")res=first*second;
                else res=second/first;
                st.push(res);
            }
        }
        return st.top();
    }
};