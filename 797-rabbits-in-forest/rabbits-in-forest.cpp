class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int ele: answers){
            mp[ele]++;
        }
        int ans=0;
        for(auto& x:mp){
            ans+=((x.first+1)*(ceil((double)x.second/(double)(x.first+1))));
        }
        return ans;
    }
};