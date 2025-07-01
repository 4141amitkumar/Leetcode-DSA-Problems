class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int ele:answers){
            mp[ele]++;
            if(mp[ele]==ele+1) {
                ans+=(ele+1);
                mp.erase(ele);
            }
        }
        for(auto& x:mp){
            ans+=(x.first+1);
        }
        return ans;
    }
};