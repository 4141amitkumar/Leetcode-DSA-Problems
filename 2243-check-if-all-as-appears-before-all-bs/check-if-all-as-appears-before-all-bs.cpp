class Solution {
public:
    bool checkString(string s) {
        int i=0;
        bool flag=false;
        while(i<s.size()){
            if(s[i]=='b') flag=true;
            else if(flag==true && s[i]=='a') return false;
            i++;
        }
        return true;
    }
};