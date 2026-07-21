class DisjointSet{
    public:
    vector<int>parent,Size;
    DisjointSet(int n){
        parent.resize(n+1);
        Size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i] = i;
    }
    int findParent(int u){
        if(u==parent[u])return u;
        return parent[u]=findParent(parent[u]);
    }
    void UnionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(Size[pu]<Size[pv]){
            parent[pu]=pv;
            Size[pv]+=Size[pu];
        }else{
            parent[pv]=pu;
            Size[pu]+=Size[pv];
        }
    }
};
class Solution {
    public:
    int removeStones(vector<vector<int>>& stones) {
        int nodes=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto & edge:stones){
            maxRow=max(maxRow,edge[0]);
            maxCol=max(maxCol,edge[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        for(auto&stone:stones){
            int x=stone[0];
            int y=stone[1];
            ds.UnionBySize(x,y+maxRow+1);
        }
        unordered_set<int>components;
        for (auto &stone:stones) {
            int row=stone[0];
            components.insert(ds.findParent(row));
        }
        return nodes-components.size();
    }
};