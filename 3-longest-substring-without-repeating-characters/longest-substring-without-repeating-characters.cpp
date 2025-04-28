class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi=0;
        for(int start=0;start<n;start++){
            unordered_set<char> unique;
            for(int end=start;end<n;end++){
                unique.insert(s[end]);
                if(unique.size()==(end-start+1)) maxi=max(maxi,(int)unique.size());
                else break;
            }
        }
        return maxi;
    }
};