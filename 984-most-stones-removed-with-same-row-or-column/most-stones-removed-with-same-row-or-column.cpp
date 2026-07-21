class Solution {
public:
    void dfs(int node,vector<vector<int>>& stones,vector<bool>&visited){
        visited[node]=true;
        for(int i=0;i<stones.size();i++){
            if(!visited[i] && (stones[node][0]==stones[i][0]||stones[node][1]==stones[i][1])){
                dfs(i,stones,visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int nodes=stones.size();
        vector<bool>visited(nodes,false);
        int noOfComponents=0;
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                noOfComponents++;
            }
        }
        return (nodes-noOfComponents);
    }
};