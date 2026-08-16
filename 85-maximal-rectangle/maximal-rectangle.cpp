class Solution {
public:
    int MaxAreaInHistogram(vector<int>&histogram){
        int maxArea=0;
        int n=histogram.size();
        for(int i=0;i<n;i++){
            int rightSmaller=n;
            int leftSmaller=-1;
            for(int j=i+1;j<n;j++){
                if(histogram[j]<histogram[i]){
                    rightSmaller=j;
                    break;
                }
            }
            for(int j=i-1;j>=0;j--){
                if(histogram[j]<histogram[i]){
                    leftSmaller=j;
                    break;
                }
            }
            int area=(rightSmaller-leftSmaller-1)*histogram[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>histogram(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')histogram[j]++;
                else histogram[j]=0;
            }
            int area=MaxAreaInHistogram(histogram);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};