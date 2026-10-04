class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='(')open.push(i);
            else if(c=='*')star.push(i);
            else{
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty()){
                    star.pop();
                }else return false;
            }
        }
        if(open.empty())return true;
        while(!open.empty()){
            if(star.empty())return false;
            if(star.top()<open.top())return false;
            star.pop();
            open.pop();
        }
        return true;
    }
};