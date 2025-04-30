class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v = score;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<string> s;
        unordered_map<int,string> rank; 
        for (int i=0; i<v.size();i++) {
            if (i==0) rank[v[i]]= "Gold Medal";
            else if (i==1) rank[v[i]]="Silver Medal";
            else if (i==2) rank[v[i]]="Bronze Medal";
            else rank[v[i]]=to_string(i+1); 
        }
        vector<string> ans;
        for (int i=0; i<score.size(); i++) {
            ans.push_back(rank[score[i]]);
        }
        return ans;
    }
};