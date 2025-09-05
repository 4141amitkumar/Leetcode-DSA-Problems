class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, have;
        for(char c:t) need[c]++;
        int required=need.size(); 
        int formed=0;
        int i=0, j=0;
        int minLen=INT_MAX, start=0;

        while(j <s.size()){
            have[s[j]]++;
            if(need.count(s[j]) && have[s[j]]==need[s[j]]) {
                formed++;
            }
            while(i<=j && formed==required){
                if(j-i+1 <minLen){
                    minLen =j-i+1;
                    start=i;
                }
                have[s[i]]--;
                if(need.count(s[i]) && have[s[i]] <need[s[i]]) {
                    formed--;
                }
                i++;
            }
            j++;
        }
        return (minLen==INT_MAX) ?"" :s.substr(start, minLen);
    }
};
