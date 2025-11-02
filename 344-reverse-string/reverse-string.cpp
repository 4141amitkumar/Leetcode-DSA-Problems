class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int lo=0, hi=n-1;
        while(lo<hi){
            swap(s[lo],s[hi]);
            lo++;
            hi--;
        }
    }
};