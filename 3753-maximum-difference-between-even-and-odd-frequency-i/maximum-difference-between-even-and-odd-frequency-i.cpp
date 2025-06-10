class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        vector<int> v1;
        vector<int> v2;
        for(auto x:m){
            if(x.second%2!=0)v1.push_back(x.second);
            if(x.second%2==0)v2.push_back(x.second);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1[v1.size()-1]-v2[0];
    }
};