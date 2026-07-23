class DisjointSet{
    vector<int>parent;
    vector<int>Size;
    public:
    DisjointSet(int n){
        parent.resize(n);
        Size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(u==parent[u])return u;
        return parent[u]=findParent(parent[u]);
    }
    void Union(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(Size[pu]<=Size[pv]){
            parent[pu]=pv;
            Size[pv]+=Size[pu];
        }else{
            parent[pv]=pu;
            Size[pu]+=Size[pv];
        }
    }
    int findSize(int node){
        return Size[node];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node=i*n+j;
                    for(auto &dir:directions){
                        int x=i+dir[0];
                        int y=j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<n &&grid[x][y]==1){
                            int adjNode=x*n+y;
                            ds.Union(node,adjNode);
                        }
                    }
                }
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int node=i*n+j;
                    int cnt=1;
                    unordered_set<int>parentNodes;
                    for(auto &dir:directions){
                        int x=i+dir[0];
                        int y=j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<n &&grid[x][y]==1){
                            int adjNode=x*n+y;
                            int parentNode=ds.findParent(adjNode);
                            parentNodes.insert(parentNode);
                        }
                    }
                    for (int p:parentNodes){
                        cnt+=ds.findSize(p);
                    }
                    res=max(res,cnt);
                }
            }
        }
        return (res==INT_MIN)? n*n:res; // if no zero all are 1 return n*n
    }
};