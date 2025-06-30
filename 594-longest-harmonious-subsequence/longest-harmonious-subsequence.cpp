class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int ele: nums){
            mp[ele]++;
        }
        int ans=0;
        for(auto& x:mp){
            if(mp.find(x.first+1)!=mp.end()) ans=max(ans,(x.second+mp[x.first+1]));
        }
        return ans;
    }
};