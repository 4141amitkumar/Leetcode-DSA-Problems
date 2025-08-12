class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> pm;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            if (j>=s.size()) return false; //to check whether pattern size is more than word size or not;
            string word="";
            while(j<s.size() && s[j]!=' '){
                word+=s[j];
                j++;
            }
            j++;
            if (mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=word) return false;
            if (pm.find(word)!=pm.end() && pm[word]!=pattern[i]) return false;
            mp[pattern[i]]=word;
            pm[word]=pattern[i];
        }
        return j>=s.size();  //to check whether word size is more than pattern size or not;
    }
};