class Solution {
public:
    bool isCyclePresentUsingDFS(int node,vector<int>adj[],vector<bool>& visited,vector<bool>&inRecursion){
        visited[node]=1;
        inRecursion[node]=1;
        for(auto&v:adj[node]){
            if(visited[v] && inRecursion[v])return true;
            if(!visited[v] && isCyclePresentUsingDFS(v,adj,visited,inRecursion) )return true;
        }
        inRecursion[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto &prereq:prerequisites){
            int a=prereq[0];
            int b=prereq[1];
            adj[a].push_back(b);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>inRecursion(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && isCyclePresentUsingDFS(i,adj,visited,inRecursion))return false;
        }
        return true;
    }
};