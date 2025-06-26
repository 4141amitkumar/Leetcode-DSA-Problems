class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //k frequent or k largest, so use MinHeap
        // map pair is <ele,freq>
        unordered_map<int,int> mp;
        for(int ele: nums){
            mp[ele]++;
        }
        // heap pair is <freq,ele>
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};