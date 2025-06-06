class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int count=0;
        for(int i=words.size()-1;i>=0;i--){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(s.find(rev)!=s.end())count++;
            s.insert(words[i]);
        }
        return count;
    }
};