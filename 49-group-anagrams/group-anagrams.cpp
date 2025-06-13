class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string org = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(mp.find(strs[i])==mp.end()) mp.insert({strs[i],{org}});
            else mp[strs[i]].push_back(org);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};