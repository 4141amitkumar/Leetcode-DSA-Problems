class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int maxodd = INT_MIN;
        int mineven = INT_MAX;
        for(auto x:m){
            if(x.second%2!=0)maxodd=max(maxodd,x.second);
            if(x.second%2==0)mineven=min(mineven,x.second);
        }
        return maxodd-mineven;
    }
};