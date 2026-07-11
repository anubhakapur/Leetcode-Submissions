class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<tuple<int,int,int>>q;
        q.push({sr,sc,image[sr][sc]});
        vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto[r,c,currColor]=q.front();
            q.pop();
            image[r][c]=color;
            for(auto &dir:directions){
                int x=r+dir[0];
                int y=c+dir[1];
                if(x>=0 && x<m && y>=0 && y<n && image[x][y]!=color && image[x][y]==currColor){
                    q.push({x,y,image[x][y]});
                }
            }
        }
        return image;
    }
};