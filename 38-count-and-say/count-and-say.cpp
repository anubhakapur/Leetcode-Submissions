class Solution {
public:
    void solve(int i,int n,string&res){
        if(i==n+1)return;
        string temp="";
        char c=res[0];
        int j=1;
        int len=1;
        while(j<res.length()){
            if(res[j]==c){
                len++;
            }else{
                temp+=to_string(len);
                temp+=c;
                len=1;
                c=res[j];
            }
            j++;
        }
        temp+=to_string(len);
        temp+=c;
        res=temp;
        solve(i+1,n,res);
    }
    string countAndSay(int n) {
        string res="1";
        solve(2,n,res);
        return res;
    }
};