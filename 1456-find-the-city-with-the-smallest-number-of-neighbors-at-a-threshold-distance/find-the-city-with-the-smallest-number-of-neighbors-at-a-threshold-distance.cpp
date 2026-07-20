class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>>adjGraph(n,vector<int>(n,INT_MAX));
       for(auto & edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adjGraph[u][v]=adjGraph[v][u]=wt;
       } 
       for(int i=0;i<n;i++){
            adjGraph[i][i]=0;
       }
       for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjGraph[i][via]!=INT_MAX && adjGraph[j][via]!=INT_MAX){
                        adjGraph[i][j]=min(adjGraph[i][j],adjGraph[i][via]+adjGraph[via][j]);
                    }
                }
            }
       }
       int minCount=INT_MAX;
       int minIndex=-1;
       for(int i=0;i<n;i++){
            int cnt=0;
        for(int j=0;j<n;j++){
            if(i!=j && adjGraph[i][j]<=distanceThreshold)cnt++;
        }
        cnt;
        if(cnt<=minCount){
            minCount=cnt;
            minIndex=i;
        }
       }
       return minIndex;
    }  
};