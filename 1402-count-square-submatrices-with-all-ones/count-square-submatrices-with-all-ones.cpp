class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0)); //how many squares end at (i,j) ie have (i,j) as right bottom
        int cnt=0;
        for(int i=0;i<m;i++){//first row=1
            if(matrix[0][i]==1){
                dp[0][i]=1;
                cnt++;
            }
        }
        for(int i=1;i<n;i++){//first col=1 and skipping dp[0][0] as covered above
            if(matrix[i][0]==1){
                dp[i][0]=1;
                cnt++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    cnt+=dp[i][j];
                }
            }
        }
        return cnt;        
    }
};