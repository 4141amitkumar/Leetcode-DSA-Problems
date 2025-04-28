class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        string s = to_string(x);
        string k = s;
        reverse(k.begin(),k.end());
        if(s==k) return true;
        return false;
    }
};