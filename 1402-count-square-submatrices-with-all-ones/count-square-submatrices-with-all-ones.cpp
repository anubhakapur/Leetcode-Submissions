class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size(); 
        int ans = 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
         for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) {
                   dp[i][j] = 1 + min({dp[i][j + 1],dp[i + 1][j],dp[i + 1][j + 1]});
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};