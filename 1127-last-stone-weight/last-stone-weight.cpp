class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int &s:stones)pq.push(s);
        while(pq.size()>=2){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)pq.push(x-y);
        }
        if(pq.size()==1)return pq.top();
        return 0;
    }
}; // 8 7 4 2 1 1