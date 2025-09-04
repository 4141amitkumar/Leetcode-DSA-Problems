class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        if (n>s.size()) return {};
        vector<int> pp(26,0);
        for(int i=0;i<n;i++){
            pp[p[i]-'a']++;
        }
        vector<int> ss(26,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            ss[s[i]-'a']++;
        }
        if(pp==ss) ans.push_back(0);
        for(int i=n;i<s.size();i++){
            ss[s[i]-'a']++;
            ss[s[i-n]-'a']--;
            if(ss==pp) ans.push_back(i-n+1);
        }
        return ans;
    }
};