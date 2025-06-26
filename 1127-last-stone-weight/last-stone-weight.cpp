class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Bad approach
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int x = stones[stones.size()-1];
            stones.pop_back();
            int y = stones[stones.size()-1];
            stones.pop_back();
            if(x!=y) stones.push_back(x-y);
        }
        if(stones.size()==1) return stones[0];
        else return 0;
    }
};