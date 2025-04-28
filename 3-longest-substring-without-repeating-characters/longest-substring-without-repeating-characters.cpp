class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int n = s.size();
        int right=0;
        int left=0;
        int maxi=0;
        while(right<n){
            if(unique.find(s[right])==unique.end()){
                unique.insert(s[right]);
                maxi=max(maxi,(int)unique.size());
                right++;
            }
            else{
                unique.erase(s[left]);
                left++;
            }
        }
        return maxi;
    }
};