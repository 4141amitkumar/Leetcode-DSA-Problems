class Solution {
public:
    bool checkString(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]=='b' && s[i+1]=='a') return false;
            i++;
        }
        return true;
    }
};