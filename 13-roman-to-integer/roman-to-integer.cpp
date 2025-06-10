class Solution {
public:
    int romanToInt(string s) {
        int total=0;
        unordered_map<char,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int prev=0;
        for(int i=s.size()-1;i>=0;i--){
            if(prev>m[s[i]]) total-=m[s[i]];
            else total+=m[s[i]];
            prev=m[s[i]];
        }
        return total;
    }
};