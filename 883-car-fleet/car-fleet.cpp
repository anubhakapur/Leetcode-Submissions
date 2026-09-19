class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        stack<double>st;
        for(auto&car:cars){
            double t=(double)(target-car.first)/car.second;
            if(st.empty() || t>st.top()) st.push(t);
        }
        return st.size();
    }
};
