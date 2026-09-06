class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char &c:s){
            if(c>=65 && c<=90){
                temp+=(c+32);
            }else if(c>=97 && c<=122)temp+=c;
            else if(c>='0' && c<='9')temp+=c;
        }
        cout<<temp;
        int i=0,j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j])return false;
            i++;j--;
        }
        return true;
    }
};