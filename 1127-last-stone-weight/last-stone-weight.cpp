class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        while(stones.size()>=2){
            sort(stones.rbegin(),stones.rend());
            int x=stones[0];
            int y=stones[1];
            stones.erase(stones.begin(),stones.begin()+2);
            if(x!=y)stones.insert(stones.begin(),x-y);
        }
        if(stones.size()==1)return stones[0];
        return 0;
    }
};