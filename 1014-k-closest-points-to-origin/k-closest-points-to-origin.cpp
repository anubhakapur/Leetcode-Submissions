class Solution {
public:
    typedef pair<long long,pair<int,int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P,vector<P>>pq;
        for(auto &point:points){
            int x=point[0];
            int y=point[1];
            long long distance=x*x+y*y;
            pq.push({distance,{x,y}});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            res.push_back({it.second.first,it.second.second});
        }
        return res;
    }
};