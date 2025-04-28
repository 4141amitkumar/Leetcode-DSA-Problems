class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c:s) {
            count[c]++;
        }
        int length=0;
        int n=0;
        bool odd=false;
        for (auto& a:count) {
            if(a.second%2==0){
                length+=a.second;
            }
            else{
                length+=a.second-1;
                odd=true;
            }
        }
        if(odd){
            length+=1;
        }
        return length;
    }
};