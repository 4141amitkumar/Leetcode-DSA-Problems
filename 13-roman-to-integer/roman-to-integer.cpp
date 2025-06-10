class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I' && (m['V']!=0 || m['X']!=0)) m['I']--;
            else if(s[i]=='X' && (m['L']!=0 || m['C']!=0)) m['X']--;
            else if(s[i]=='C' && (m['D']!=0 || m['M']!=0)) m['C']--;
            else m[s[i]]++;
        }
        return m['M']*1000+m['D']*500+m['C']*100+m['L']*50+m['X']*10+m['V']*5+m['I'];
    }
};