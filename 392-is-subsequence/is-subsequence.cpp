class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j=0;
        for(i=0;i<s.size();i++){
            while(j<t.size() && t[j]!=s[i]){
                j++;
            }
            j++;
            if(j>t.size()) return false;
        }
        if(i==s.size()) return true;
        else return false;
    }
};