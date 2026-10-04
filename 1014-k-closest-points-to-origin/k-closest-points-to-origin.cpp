class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long,pair<int,int>>>distances;
        for(auto &point:points){
            int x=point[0];
            int y=point[1];
            long long distance=x*x+y*y;
            distances.push_back({distance,{x,y}});
        }
        sort(distances.begin(),distances.end());
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            res.push_back({distances[i].second.first,distances[i].second.second});
        }
        return res;
    }
};